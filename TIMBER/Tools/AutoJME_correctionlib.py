'''
Automatic calculation of per-jet per-event JES factors and uncertainties.
'''
from TIMBER.Tools.Common import GetJMETag, CompileCpp
from TIMBER.Analyzer import Calibration
import correctionlib._core as core
import ROOT

'''
Should you wish to use a custom-named collection derived from the FatJet or Jet
collections, it is advisable to modify them in the script from which you call 
AutoJME, for example:

    from TIMBER.Tools.Common import AutoJME
    AutoJME.AK8collection = "myCustomAK8collection"
    AutoJME.AutoJME(analyzer, "myCustomAK8collection", 2017, '', True)
'''
AK8collection = "FatJet"
AK4collection = "Jet"

def AutoJME(a, jetCollection, year, dataEra='', calibrate=True):
    '''
    @param a (analyzer): TIMBER analyzer object to be manipulated and returned.
    @param jetCollection (str): Name of the jet collection to correct.
        The default jet collections in NanoAOD are FatJet (AK8) and Jet (AK4).
        However, you can also pass a custom collection built from either of these by changing the AK8/AK4collection values above.
    @param year (str): Year associated with the input files to the analyzer
        Run 2 options: 2016preVFP_UL/EOY, 2016postVFP_UL/EOY, 2017_UL/EOY, 2018_UL/EOY
        Run 3 options: 2022_Prompt, 2022_Summer22, 2022_Summer22EE, 2023_Summer23, 2023_Summer23BPix, 2024_Winter24
    @param dataEra (str): If providing data, include the "era" (e.g. A,B,C,D,..)
    @param calibrate (bool): Whether to calibrate the pT and masses of the jets in the event using HadamardProduct. If False, then only produce the uncertainty columns

    Raises:
        ValueError: Provided JetCollection does not exist in the analyzer's stored list of collections
        ValueError: Provided dataEra does not exist for the input year
        ValueError: Requested AK8 corrections for 2024_Winter24 (only AK4 corrections so far - Feb. 7, 2025)

    Returns:
        analyzer: Manipulated version of the input analyzer object.
    '''
    print('----------------------------------------------------------------------------------------')
    print('--------------------------- Starting AutoJME -------------------------------------------')
    print('----------------------------------------------------------------------------------------')

    print(f'\nStep 1: JES corrections...')

    if ((a.isData) and (dataEra == '')):
        raise ValueError(f'Running on data but no dataEra specified.')

    # Get the 4-digit year
    y = int(year.split('_')[0][:4])

    # Determine the jet clustering and cleaning algorithm and which JSON file to use
    if jetCollection == AK8collection:
        algo  = 'AK8PFPuppi'
        json  = 'fatJet_jerc'
        genJetColl = "GenJetAK8"
        dRmax = 0.8
        # Determine whether to do JMR/JMS corrections to MC
        if (y <= 2018): # Run 2
            doMass = True
        else:
            doMass = False
    elif jetCollection == AK4collection:
        y = int(year.split('_')[0][:4])
        if (y <= 2018): # Run 2
            algo = 'AK4PFchs'
        else:
            algo = 'AK4PFPuppi'
        json = 'jet_jerc'
        genJetColl = "GenJet"
        drMax = 0.4
        doMass = False
    else:
        available_colls = list(a._collectionOrg.GetCollectionNames())
        raise ValueError(f'Jet collection name {jetCollection} not supported. Make sure to set AutoJME.AK8collection or AutoJME.AK4collection if using a custom collection. The collections available in the passed analyzer are: {available_colls}')

    # Determine the JEC level
    levels = ['L1Fastjet', 'L2Relative', 'L3Absolute', 'L2L3Residual'] # NOT IMPLEMENTED YET (and not really needed for most cases)
    level  = 'L1L2L3Res' # Currently only supporting the compound correction
    unc    = 'Total'

    # Load the CorrectionSet from the file hosted on CVMFS. These files are synced daily, see here: https://gitlab.cern.ch/cms-nanoAOD/jsonpog-integration/-/blob/master/README.md
    fname_jes = f"/cvmfs/cms.cern.ch/rsync/cms-nanoAOD/jsonpog-integration/POG/JME/{year}/{json}.json.gz"

    print(f'\nJet collection: {jetCollection}')
    print(f'Jet algorithm:  {algo}')
    print(f'Uncertainty:    {unc}')
    print(f'JEC level:      {level}')
    print(f'Year:           {year}')
    if (a.isData):
        print(f'Era:            {dataEra}')

    print("\nLoading JSON file: {}".format(fname_jes))
    cset_jes = core.CorrectionSet.from_file(fname_jes)
    keys = list(cset_jes.compound.keys()) # NOTE: we are using "cset_jes.compound" here b/c individual JEC levels have not been implemented for AutoJME, and we are just using the compound "L1L2L3Res" JEC level

    # Find the appropriate CorrectionSet key for Data or MC
    if (a.isData):
        found = False
        keysData = [k for k in keys if 'DATA' in k]
        for k in keysData: 
            era = k.split('_')[1]
            if dataEra in era: 
                found = True
                key = k
                break
        if not found:
            raise ValueError(f'The dataEra {dataEra} does not correspond with any keys in the JSON CorrectionSet. Available data keys are: {keysData}')            
    else:
        # There is only one compound key in the JSON for MC
        key = [k for k in keys if 'MC' in k][0]

    print(f'\nUsing compound JEC level key: "{key}"')
    print(f'\nUsing compound JEC uncertainty\n')

    jes = Calibration(
        f"{jetCollection}_JES",
        "TIMBER/Framework/src/JES_correctionlib_weight.cc", 
        [fname_jes, key, key.replace(level,unc), a.isData], 
        corrtype='Calibration'
    )
    
    evalargs = {
        jes: {
            "pt": f"{jetCollection}_pt",
            "eta": f"{jetCollection}_eta",
            "phi": f"{jetCollection}_phi",
            "area": f"{jetCollection}_area",
            "fixedGridRhoFastjetAll":"fixedGridRhoFastjetAll" if (y <= 2018) else "Rho_fixedGridRhoFastjetAll"
        }
    }

    calibdict = {
        f"{jetCollection}_pt":[jes],
        f"{jetCollection}_mass":[jes],
        f"{jetCollection}_msoftdrop":[jes]
    }

    # Create the columns corresponding to the JES variations
    if (a.isData):
        if (calibrate):
            a.CalibrateVars(calibdict,evalargs,'',variationsFlag=(not a.isData))
        else:
            a.CalibrateVars({},evalargs,'',variationsFlag=(not a.isData))
    else:
        # Don't calibrate yet until JER is calcuated
        a.CalibrateVars({},evalargs,'',variationsFlag=(not a.isData))

    # Now handle JER corrections to MC only. JER corrections use the JES-corrected pT
    if not a.isData:
        print(f'\nStep 2: JER corrections...\n')

        # Get the appropriate keys for the JER resolution and SF. These will be stored in the JES correctionset "cset_jes"
        key_res = [i for i in cset_jes if 'PtResolution' in i][0]   # Each correctionset has only one of these keys, so the list will always be one element long
        key_sf  = [i for i in cset_jes if 'ScaleFactor' in i][0]

        # Multiplicative factor to the difference b/w the GEN and RECO jet pT, used in the JER correction algorithm (see JER_correctionlib_weight.cc)
        dpTmax = 3

        print(f'Using JER resolution key "{key_res}"')
        print(f'Using JER SF key         "{key_sf}"')
        print(f'Using hybrid smearing method with GEN match parameters:')
        print(f'\t delta pT max factor = {dpTmax}')
        print(f'\t deltaR max          = {dRmax}\n')

        jer = Calibration(
            f"{jetCollection}_JER",
            'TIMBER/Framework/src/JER_correctionlib_weight.cc',
            [
                fname_jes,  # Name of the jerc file for AK8 or AK4
                key,        # JES key
                key_res,    # pt resolution key
                key_sf,     # SF key
                dRmax,      # used for gen<->reco matching. 0.8 for AK8, 0.4 for AK4
                dpTmax      # dPtMaxFactor, default for CMS
            ],
            corrtype='Calibration'
        )

        evalargs = {
            jer: {
                "jets":f"{jetCollection}s",
                "genJets":f"{genJetColl}s",
                "fixedGridRhoFastjetAll":"fixedGridRhoFastjetAll" if (y <= 2018) else "Rho_fixedGridRhoFastjetAll"
            }
        }

        calibdict = {
            f"{jetCollection}_pt":[jes,jer],
            f"{jetCollection}_mass":[jes,jer],
            f"{jetCollection}_msoftdrop":[jes,jer]
        }

        if (calibrate):
            a.CalibrateVars(calibdict,evalargs,'',variationsFlag=(not a.isData))
        else:
            a.CalibrateVars({},evalargs,'',variationsFlag=(not a.isData))

    # Now apply veto maps to Data and MC (Run 3 ONLY)
    if (y > 2018):
        print('\nStep 3: Applying JERC jet veto maps (Run 3 only)...')
        fname_vetomap = f"/cvmfs/cms.cern.ch/rsync/cms-nanoAOD/jsonpog-integration/POG/JME/{year}/jetvetomaps.json.gz"
        cset_vetomap = core.CorrectionSet.from_file(fname_vetomap)
        key_vetomap = [k for k in cset_vetomap][0]  # there is only one vetomap key, so the key will always be the first and only element
        CompileCpp('TIMBER/Framework/src/JERC_JetVeto.cc')
        CompileCpp(f'JERC_JetVeto jet_vetoer = JERC_JetVeto("{fname_vetomap}","{key_vetomap}");')
        a.Define('jetmap_vetoed_events',f'jet_vetoer.eval(Jets)')   # Pass in the TIMBER-created struct for the AK4 jets ("Jet"+"s")
        a.Cut('JERC_jet_veto','jetmap_vetoed_events == 1')


    print('\n----------------------------------------------------------------------------------------')
    print('------------------------------Finished AutoJME -----------------------------------------')
    print('----------------------------------------------------------------------------------------')
