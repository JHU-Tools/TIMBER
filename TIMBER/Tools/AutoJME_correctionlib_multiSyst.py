'''
Automatic calculation of per-jet per-event JES factors and uncertainties.
'''
from TIMBER.Tools.Common import GetJMETag, CompileCpp
from TIMBER.Analyzer import Calibration
import correctionlib._core as core
import ROOT
import os
################################################
#This module is only validated with Run3 NanoAOD_v15 datasets.
#For MC ONLY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#DON'T APPLY IT ON DATA!!!!!!!!!!!!!!!!!!!!!!!
################################################

def AutoJME(a, jetCollections, year, dataEra='', calibrate=True, AK4Calib_extras = [], AK8Calib_extras = [], col_jetId = "Jet_jetId_corr"):
    '''
    @param a (analyzer): TIMBER analyzer object to be manipulated and returned.
    @param jetCollections (str list): Names of the jet collection to correct. For example, it can take ["FatJet"], ["Jet"] or ["FatJet", "Jet"]. However, it is ALWAYS recommended to include AK4 jets even if it is not used in your analysis, since it is used for Jet Veto Map, which requires correct correction of the AK4 jets
    @param year (str): Year associated with the input files to the analyzer
        Run 2 options: 2016preVFP_UL/EOY, 2016postVFP_UL/EOY, 2017_UL/EOY, 2018_UL/EOY
        Run 3 options: 2022_Prompt, 2022_Summer22, 2022_Summer22EE, 2023_Summer23, 2023_Summer23BPix, 2024_Summer24, 2024_Winter24
    @param dataEra (str): If providing data, include the "era" (e.g. A,B,C,D,..)
    @param calibrate (bool): Whether to calibrate the pT and masses of the jets in the event using HadamardProduct. If False, then only produce the uncertainty columns
    @param AK4Calib_extras (str list): The extra NanoAOD columns of AK4 jets you want to calibrate. DON'T feed Raw values.
    @param AK8Calib_extras (str list): The extra NanoAOD columns of AK8 jets you want to calibrate. DON'T feed Raw values.
    @param col_jetID (str): the column for jet ID used for JVM. The default Jet_jetId column in NanoAOD v12 - v14 is buggy and shouldn't be used. In NanoAOD v15 it doesn't exist at all. So please make a custom jetId column and feed it into this function.
    Raises:
        ValueError: Provided JetCollection does not exist in the analyzer's stored list of collections
        ValueError: Provided dataEra does not exist for the input year

    Returns:
        analyzer: Manipulated version of the input analyzer object.
    '''
    #####################################################################################################
    ########### calibrate=False is not supported anymore. since JER correction requires calibrated JES pt
    ###   DO NOT USE THIS MODULE TO CORRECT FatJet_msoftdrop. USE AutoJME_mSD INSTEAD.
    #####################################################################################################

    AK8collection = "FatJet"
    AK4collection = "Jet"
    AK8Calibs = ["mass", "pt"] + AK8Calib_extras
    AK4Calibs = ["mass", "pt"] + AK4Calib_extras
    print('----------------------------------------------------------------------------------------')
    print('--------------------------- Starting AutoJME -------------------------------------------')
    print('----------------------------------------------------------------------------------------')



    if ((a.isData)):
        raise ValueError(f'Do not use this module for data.')
    CompileCpp('TIMBER/Framework/src/getRawVal.cc')
    CompileCpp('TIMBER/Framework/src/JERC_JetVeto.cc')
    for jetCollection in jetCollections:

        
        print(f'\nStep 0: Calculate RAW value...')
        if jetCollection == AK8collection:
            for _calib in AK8Calibs:
                a.Define(f"{jetCollection}_{_calib}_raw", f"getRawVal(n{jetCollection}, {jetCollection}_{_calib}, {jetCollection}_rawFactor)")
                 
        if jetCollection == AK4collection:
            for _calib in AK4Calibs:
                a.Define(f"{jetCollection}_{_calib}_raw", f"getRawVal(n{jetCollection}, {jetCollection}_{_calib}, {jetCollection}_rawFactor)")





        print(f'\nStep 1: JES corrections...')
        # Get the 4-digit year
        y = int(year.split('_')[0][:4])

        # Determine the jet clustering and cleaning algorithm and which JSON file to use
        if jetCollection == AK8collection:
            algo  = 'AK8PFPuppi'
            json  = 'fatJet_jerc'
            # Determine whether to do JMR/JMS corrections to MC
            if (y <= 2018): # Run 2
                doMass = True
            else:
                doMass = False
            if (y == 2024):
                json  = 'jet_jerc' ###AD HOC SOLUTION!!!!!!!!!!!: 2024 fatjet json not avaliable, using AK4 jet correction instead
        elif jetCollection == AK4collection:
            if (y <= 2018): # Run 2
                algo = 'AK4PFchs'
            else:
                algo = 'AK4PFPuppi'
            json = 'jet_jerc'
            doMass = False
        else:
            available_colls = list(a._collectionOrg.GetCollectionNames())
            raise ValueError(f'Jet collection name {jetCollection} not supported. Make sure to set AutoJME.AK8collection or AutoJME.AK4collection if using a custom collection. The collections available in the passed analyzer are: {available_colls}')

        # Determine the JEC level
        level  = 'L1L2L3Res' # Currently only supporting the compound correction. This will cover all JERC required corretions
        unc = ""


        # Load the CorrectionSet from the file hosted on CVMFS. These files are synced daily, see here: https://gitlab.cern.ch/cms-nanoAOD/jsonpog-integration/-/blob/master/README.md
        #fname_jes = f"/cvmfs/cms.cern.ch/rsync/cms-nanoAOD/jsonpog-integration/POG/JME/{year}/{json}.json.gz"
        fname_jes = os.path.dirname(os.path.abspath(__file__)) + f"/newest_JERC/{year}/{json}.json.gz"

        print(f'\nJet collection: {jetCollection}')
        print(f'Jet algorithm:  {algo}')
        print(f'Uncertainty:    {unc}')
        print(f'JEC level:      {level}')
        print(f'Year:           {year}')
        if (a.isData):
            print(f'Era:            {dataEra}')

        print("\nLoading JSON file: {}".format(fname_jes))
        cset_jes = core.CorrectionSet.from_file(fname_jes)
        compound_keys = list(cset_jes.compound.keys())
        level_key = [k for k in compound_keys if 'MC' in k][0] 
        keys = list(cset_jes)
        L2L3_keys = []
        L2_keys = []
        L1_keys = []
        for key in keys:
            print(key)
            if "Regrouped" in key and "Total" not in key: L2_keys.append(key)
        for key in keys:
            if "L1" in key: L1_keys.append(key) 
        for key in keys:
            if "L2L3" in key: L2L3_keys.append(key) 
        print(L1_keys)
        print(L2_keys)
        print(L2L3_keys)
        if len(L2_keys) != 11: raise ValueError(f'There are supposed to be 11 L2L3 variants but only {len(L2_keys)} were given!!!!!!!!!!')
        # Find the appropriate CorrectionSet key for Data or MC
        unc_keys = ""
        unc_names = []
        for key in L2_keys:
            unc_keys = unc_keys + key + ","
            unc_names.append(key[key.find("Regrouped_")+10:key.find("_AK4PFP")])

        jes = Calibration(
            f"{jetCollection}_JES",
            "TIMBER/Framework/src/JES_correctionlib_multiSyst_weight.cc", 
            [fname_jes, level_key, unc_keys, a.isData], 
            corrtype='Calibration'
        )
        evalargs = {
            jes: {
                "pt": f"{jetCollection}_pt_raw",
                "eta": f"{jetCollection}_eta",
                "phi": f"{jetCollection}_phi",
                "area": f"{jetCollection}_area",
                "run":  "run",
                "fixedGridRhoFastjetAll":"fixedGridRhoFastjetAll" if (y <= 2018) else "Rho_fixedGridRhoFastjetAll"
            }
        }
        if jetCollection == AK8collection:    
            calibdict = {}
            for _calib in AK8Calibs:
                calibdict[f"{jetCollection}_{_calib}_raw"] = [jes]
        elif jetCollection == AK4collection:
            calibdict = {}
            for _calib in AK4Calibs:
                calibdict[f"{jetCollection}_{_calib}_raw"] = [jes]
        

        # Create the columns corresponding to the JES variations
        a.CalibrateVars_multiSyst(calibdict,evalargs,'',variationsFlag=(not a.isData), syst_names = unc_names)
        



        # Now handle JER corrections to MC only. JER corrections use the JES-corrected pT
        print(f'\nStep 2: JER corrections...\n')
        if jetCollection == AK8collection:
            genJetColl = "GenJetAK8"
            dRmax = 0.4
            if (y == 2024):
                json  = 'jet_jerc' ###AD HOC SOLUTION!!!!!!!!!!!: 2024 fatjet json not avaliable, using AK4 jet correction instead
        elif jetCollection == AK4collection:
            genJetColl = "GenJet"
            dRmax = 0.2
        
        if a.isData:
            if jetCollection == AK8collection:
                for _calib in AK8Calibs:
                    a.Define(f"{jetCollection}_{_calib}_nom", f"{jetCollection}_{_calib}_raw_nom")
                 
            if jetCollection == AK4collection:
                for _calib in AK4Calibs:
                    a.Define(f"{jetCollection}_{_calib}_nom", f"{jetCollection}_{_calib}_raw_nom")

        else:

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
                    key_res,    # pt resolution key
                    key_sf,     # SF key
                    dRmax,      # used for gen<->reco matching. 0.8 for AK8, 0.4 for AK4
                    dpTmax      # dPtMaxFactor, default for CMS
                ],
                corrtype='Calibration'
            )

            evalargs = {
                jer: {
                    "nJet": f"n{jetCollection}", 
                    "jet_pt": f"{jetCollection}_pt_raw_nom", 
                    "jet_eta": f"{jetCollection}_eta", 
                    "jet_phi": f"{jetCollection}_phi", 
                    "nGenJet": f"n{genJetColl}", 
                    "genJet_pt": f"{genJetColl}_pt", 
                    "genJet_eta": f"{genJetColl}_eta", 
                    "genJet_phi": f"{genJetColl}_phi", 
                    "fixedGridRhoFastjetAll":"fixedGridRhoFastjetAll" if (y <= 2018) else "Rho_fixedGridRhoFastjetAll"
                }
            }
            if jetCollection == AK8collection:    
                calibdict = {}
                for _calib in AK8Calibs:
                    calibdict[f"{jetCollection}_{_calib}_raw_nom"] = [jer]
            elif jetCollection == AK4collection:
                calibdict = {}
                for _calib in AK4Calibs:
                    calibdict[f"{jetCollection}_{_calib}_raw_nom"] = [jer]

            a.CalibrateVars(calibdict,evalargs,'',variationsFlag=(not a.isData))
            
            if jetCollection == AK8collection:
                for _calib in AK8Calibs:
                    
                    a.Define(f"{jetCollection}_{_calib}_nom", f"{jetCollection}_{_calib}_raw_nom_nom")
                    for unc_name in unc_names:
                        a.Define(f"{jetCollection}_{_calib}_JES__{unc_name}_up", f"{jetCollection}_{_calib}_raw_JES__{unc_name}_up")
                        a.Define(f"{jetCollection}_{_calib}_JES__{unc_name}_down", f"{jetCollection}_{_calib}_raw_JES__{unc_name}_down")
                    a.Define(f"{jetCollection}_{_calib}_JER__up", f"{jetCollection}_{_calib}_raw_nom_JER__up")
                    a.Define(f"{jetCollection}_{_calib}_JER__down", f"{jetCollection}_{_calib}_raw_nom_JER__down")
                 
            if jetCollection == AK4collection:
                for _calib in AK4Calibs:
                    a.Define(f"{jetCollection}_{_calib}_nom", f"{jetCollection}_{_calib}_raw_nom_nom")
                    for unc_name in unc_names:
                        a.Define(f"{jetCollection}_{_calib}_JES__{unc_name}_up", f"{jetCollection}_{_calib}_raw_JES__{unc_name}_up")
                        a.Define(f"{jetCollection}_{_calib}_JES__{unc_name}_down", f"{jetCollection}_{_calib}_raw_JES__{unc_name}_down")
                    a.Define(f"{jetCollection}_{_calib}_JER__up", f"{jetCollection}_{_calib}_raw_nom_JER__up")
                    a.Define(f"{jetCollection}_{_calib}_JER__down", f"{jetCollection}_{_calib}_raw_nom_JER__down")





        # Now apply veto maps to Data and MC (Run 3 ONLY)
        print('\nStep 3: Applying JERC jet veto maps (Run 3 only)...')
        if (y > 2018 and jetCollection == "Jet"): ##Only needed for AK4 Jets
            #fname_vetomap = f"/cvmfs/cms.cern.ch/rsync/cms-nanoAOD/jsonpog-integration/POG/JME/{year}/jetvetomaps.json.gz"
            fname_vetomap = os.path.dirname(os.path.abspath(__file__)) +  f"/newest_JERC/{year}/jetvetomaps.json.gz"
            cset_vetomap = core.CorrectionSet.from_file(fname_vetomap)
            key_vetomap = [k for k in cset_vetomap][0]  # there is only one vetomap key, so the key will always be the first and only element
            CompileCpp(f'JERC_JetVeto {jetCollection}_jet_vetoer = JERC_JetVeto("{fname_vetomap}","{key_vetomap}");')
            a.Define(f'{jetCollection}_jetmap_vetoed_events',f'{jetCollection}_jet_vetoer.eval(nJet, Jet_pt_nom, Jet_eta, Jet_phi, {col_jetId}, Jet_chEmEF, Jet_neEmEF)')   
            a.Cut(f'{jetCollection}_JERC_jet_veto',f'{jetCollection}_jetmap_vetoed_events == 0')


    print('\n----------------------------------------------------------------------------------------')
    print('------------------------------Finished AutoJME -----------------------------------------')
    print('----------------------------------------------------------------------------------------')






def AutoJME_mSD(a, year, dataEra=''):
    '''
    @param a (analyzer): TIMBER analyzer object to be manipulated and returned.
    @param jetCollections (str list): Names of the jet collection to correct. For example, it can take ["FatJet"], ["Jet"] or ["FatJet", "Jet"]. However, it is ALWAYS recommended to include AK4 jets even if it is not used in your analysis, since it is used for Jet Veto Map, which requires correct correction of the AK4 jets
    @param year (str): Year associated with the input files to the analyzer
        Run 2 options: 2016preVFP_UL/EOY, 2016postVFP_UL/EOY, 2017_UL/EOY, 2018_UL/EOY
        Run 3 options: 2022_Prompt, 2022_Summer22, 2022_Summer22EE, 2023_Summer23, 2023_Summer23BPix, 2024_Summer24, 2024_Winter24
    @param dataEra (str): If providing data, include the "era" (e.g. A,B,C,D,..)
    Returns:
        analyzer: Manipulated version of the input analyzer object.
    '''

    print('----------------------------------------------------------------------------------------')
    print('--------------------------- Starting AutoJME mSD ---------------------------------------')
    print('----------------------------------------------------------------------------------------')



    if ((a.isData) and (dataEra == '')):
        raise ValueError(f'Running on data but no dataEra specified.')
    CompileCpp('TIMBER/Framework/src/getRawVal.cc')

    print(f'\nStep -1: Look for the subjets...')
    a.Define("subjet1_mass", "JME_defineVal(nFatJet, FatJet_subJetIdx1, SubJet_mass)")
    a.Define("subjet1_pt", "JME_defineVal(nFatJet, FatJet_subJetIdx1, SubJet_pt)")
    a.Define("subjet1_eta", "JME_defineVal(nFatJet, FatJet_subJetIdx1, SubJet_eta)")
    a.Define("subjet1_phi", "JME_defineVal(nFatJet, FatJet_subJetIdx1, SubJet_phi)")
    a.Define("subjet1_area", "JME_defineVal(nFatJet, FatJet_subJetIdx1, SubJet_area)")
    a.Define("subjet1_rawFactor", "JME_defineVal(nFatJet, FatJet_subJetIdx1, SubJet_rawFactor)")
    a.Define("subjet2_mass", "JME_defineVal(nFatJet, FatJet_subJetIdx2, SubJet_mass)")
    a.Define("subjet2_pt", "JME_defineVal(nFatJet, FatJet_subJetIdx2, SubJet_pt)")
    a.Define("subjet2_eta", "JME_defineVal(nFatJet, FatJet_subJetIdx2, SubJet_eta)")
    a.Define("subjet2_phi", "JME_defineVal(nFatJet, FatJet_subJetIdx2, SubJet_phi)")
    a.Define("subjet2_area", "JME_defineVal(nFatJet, FatJet_subJetIdx2, SubJet_area)")
    a.Define("subjet2_rawFactor", "JME_defineVal(nFatJet, FatJet_subJetIdx2, SubJet_rawFactor)")


    print(f'\nStep 0: Calculate RAW value...')
    a.Define(f"subjet1_mass_raw", f"getRawVal(nFatJet, subjet1_mass, subjet1_rawFactor)")
    a.Define(f"subjet1_pt_raw", f"getRawVal(nFatJet, subjet1_pt, subjet1_rawFactor)")
    a.Define(f"subjet2_mass_raw", f"getRawVal(nFatJet, subjet2_mass, subjet2_rawFactor)")
    a.Define(f"subjet2_pt_raw", f"getRawVal(nFatJet, subjet2_pt, subjet2_rawFactor)")
    ######################A INVALID INPUT PROBLEM##################





    print(f'\nStep 1: JES corrections...')
    # Get the 4-digit year
    y = int(year.split('_')[0][:4])

    # Determine the jet clustering and cleaning algorithm and which JSON file to use
    if (y <= 2018): # Run 2
        algo = 'AK4PFchs'
    else:
        algo = 'AK4PFPuppi'
    json = 'jet_jerc'
    doMass = False

    # Determine the JEC level
    level  = 'L1L2L3Res' # Currently only supporting the compound correction. This will cover all JERC required corretions
    unc    = 'Total' # Only support Total uncertainty

    # Load the CorrectionSet from the file hosted on CVMFS. These files are synced daily, see here: https://gitlab.cern.ch/cms-nanoAOD/jsonpog-integration/-/blob/master/README.md
    #fname_jes = f"/cvmfs/cms.cern.ch/rsync/cms-nanoAOD/jsonpog-integration/POG/JME/{year}/{json}.json.gz"
    fname_jes = os.path.dirname(os.path.abspath(__file__)) +  f"/newest_JERC/{year}/{json}.json.gz"

    print(f'Jet algorithm:  {algo}')
    print(f'Uncertainty:    {unc}')
    print(f'JEC level:      {level}')
    print(f'Year:           {year}')
    if (a.isData):
        print(f'Era:            {dataEra}')

    print("\nLoading JSON file: {}".format(fname_jes))
    cset_jes = core.CorrectionSet.from_file(fname_jes)
    compound_keys = list(cset_jes.compound.keys())
    level_key = [k for k in compound_keys if 'MC' in k][0]
    keys = list(cset_jes)
    L2L3_keys = []
    L2_keys = []
    L1_keys = []
    for key in keys:
        print(key)
        if "Regrouped" in key and "Total" not in key: L2_keys.append(key)
    for key in keys:
        if "L1" in key: L1_keys.append(key)
    for key in keys:
        if "L2L3" in key: L2L3_keys.append(key)
    print(L1_keys)
    print(L2_keys)
    print(L2L3_keys)
    if len(L2_keys) != 11: raise ValueError(f'There are supposed to be 11 L2L3 variants, but only {len(L2_keys)} were given!!!!!!!!!!')
    # Find the appropriate CorrectionSet key for Data or MC
    unc_keys = ""
    unc_names=[]
    for key in L2_keys:
        unc_keys = unc_keys + key + ","
        unc_names.append(key[key.find("Regrouped_")+10:key.find("_AK4PFP")])


    print(f'\nUsing compound JEC level key: "{key}"')
    print(f'\nUsing compound JEC uncertainty\n')

    jes1 = Calibration(
        f"mSD1_JES",
        "TIMBER/Framework/src/JES_correctionlib_multiSyst_weight.cc", 
        [fname_jes, level_key, unc_keys, a.isData], 
        corrtype='Calibration'
    )
    jes2 = Calibration(
        f"mSD2_JES",
        "TIMBER/Framework/src/JES_correctionlib_multiSyst_weight.cc", 
        [fname_jes, level_key, unc_keys, a.isData], 
        corrtype='Calibration'
    )
    evalargs1 = {
        jes1: {
            "pt": f"subjet1_pt_raw",
            "eta": f"subjet1_eta",
            "phi": f"subjet1_phi",
            "area": f"subjet1_area",
            "run":  "run",
            "fixedGridRhoFastjetAll":"fixedGridRhoFastjetAll" if (y <= 2018) else "Rho_fixedGridRhoFastjetAll"
        }
    }
    evalargs2 = {
        jes2: {
            "pt": f"subjet2_pt_raw",
            "eta": f"subjet2_eta",
            "phi": f"subjet2_phi",
            "area": f"subjet2_area",
            "run":  "run",
            "fixedGridRhoFastjetAll":"fixedGridRhoFastjetAll" if (y <= 2018) else "Rho_fixedGridRhoFastjetAll"
        }
    }
    calibdict1 = {"subjet1_pt_raw": [jes1], "subjet1_mass_raw": [jes1]}
    calibdict2 = {"subjet2_pt_raw": [jes2], "subjet2_mass_raw": [jes2]}
    

    # Create the columns corresponding to the JES variations
    a.CalibrateVars_multiSyst(calibdict1,evalargs1,'',variationsFlag=(not a.isData), syst_names = unc_names)
    a.CalibrateVars_multiSyst(calibdict2,evalargs2,'',variationsFlag=(not a.isData), syst_names = unc_names)
    



    # Now handle JER corrections to MC only. JER corrections use the JES-corrected pT
    print(f'\nStep 2: JER corrections...\n')
    genJetColl = "GenJet"
    dRmax = 0.2
    
    if a.isData:
        for jetCollection in ["subjet1", "subjet2"]:
            for  _calib in ["mass", "pt"]:
                a.Define(f"{jetCollection}_{_calib}_nom", f"{jetCollection}_{_calib}_raw_nom")
        
        a.Define("FatJet_msoftdrop_nom", f"JME_invM(nFatJet, FatJet_subJetIdx1, FatJet_subJetIdx2, subjet1_pt_nom, subjet1_eta, subjet1_phi, subjet1_mass_nom, subjet2_pt_nom, subjet2_eta, subjet2_phi, subjet2_mass_nom)")
    else:

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

        jer1 = Calibration(
            f"mSD1_JER",
            'TIMBER/Framework/src/JER_correctionlib_weight.cc',
            [
                fname_jes,  # Name of the jerc file for AK8 or AK4
                key_res,    # pt resolution key
                key_sf,     # SF key
                dRmax,      # used for gen<->reco matching. 0.8 for AK8, 0.4 for AK4
                dpTmax      # dPtMaxFactor, default for CMS
            ],
            corrtype='Calibration'
        )
        jer2 = Calibration(
            f"mSD2_JER",
            'TIMBER/Framework/src/JER_correctionlib_weight.cc',
            [
                fname_jes,  # Name of the jerc file for AK8 or AK4
                key_res,    # pt resolution key
                key_sf,     # SF key
                dRmax,      # used for gen<->reco matching. 0.8 for AK8, 0.4 for AK4
                dpTmax      # dPtMaxFactor, default for CMS
            ],
        )

        evalargs1 = {
            jer1: {
                "nJet": f"nFatJet", 
                "jet_pt": f"subjet1_pt_raw_nom", 
                "jet_eta": f"subjet1_eta", 
                "jet_phi": f"subjet1_phi", 
                "nGenJet": f"n{genJetColl}", 
                "genJet_pt": f"{genJetColl}_pt", 
                "genJet_eta": f"{genJetColl}_eta", 
                "genJet_phi": f"{genJetColl}_phi", 
                "fixedGridRhoFastjetAll":"fixedGridRhoFastjetAll" if (y <= 2018) else "Rho_fixedGridRhoFastjetAll"
            }
        }
        evalargs2 = {
            jer2: {
                "nJet": f"nFatJet", 
                "jet_pt": f"subjet2_pt_raw_nom", 
                "jet_eta": f"subjet2_eta", 
                "jet_phi": f"subjet2_phi", 
                "nGenJet": f"n{genJetColl}", 
                "genJet_pt": f"{genJetColl}_pt", 
                "genJet_eta": f"{genJetColl}_eta", 
                "genJet_phi": f"{genJetColl}_phi", 
                "fixedGridRhoFastjetAll":"fixedGridRhoFastjetAll" if (y <= 2018) else "Rho_fixedGridRhoFastjetAll"
            }
        }
        calibdict1 = {"subjet1_pt_raw_nom": [jer1], "subjet1_mass_raw_nom": [jer1]}
        calibdict2 = {"subjet2_pt_raw_nom": [jer2], "subjet2_mass_raw_nom": [jer2]}

        a.CalibrateVars(calibdict1,evalargs1,'',variationsFlag=(not a.isData))
        a.CalibrateVars(calibdict2,evalargs2,'',variationsFlag=(not a.isData))
        
        for jetCollection in ["subjet1", "subjet2"]:
            for  _calib in ["mass", "pt"]:
                a.Define(f"{jetCollection}_{_calib}_nom", f"{jetCollection}_{_calib}_raw_nom_nom")
                for unc_name in unc_names:
                    a.Define(f"{jetCollection}_{_calib}_JES__{unc_name}_up", f"{jetCollection}_{_calib}_raw_JES__{unc_name}_up")
                    a.Define(f"{jetCollection}_{_calib}_JES__{unc_name}_down", f"{jetCollection}_{_calib}_raw_JES__{unc_name}_down")
                a.Define(f"{jetCollection}_{_calib}_JER__up", f"{jetCollection}_{_calib}_raw_nom_JER__up")
                a.Define(f"{jetCollection}_{_calib}_JER__down", f"{jetCollection}_{_calib}_raw_nom_JER__down")
        for variation in ["nom", "JER__up", "JER__down"]: 
            a.Define(f"FatJet_msoftdrop_{variation}", f"JME_invM(nFatJet, FatJet_subJetIdx1, FatJet_subJetIdx2, subjet1_pt_{variation}, subjet1_eta, subjet1_phi, subjet1_mass_{variation}, subjet2_pt_{variation}, subjet2_eta, subjet2_phi, subjet2_mass_{variation})")
        for unc_name in unc_names:
            a.Define(f"FatJet_msoftdrop_JES__{unc_name}_up", f"JME_invM(nFatJet, FatJet_subJetIdx1, FatJet_subJetIdx2, subjet1_pt_JES__{unc_name}_up, subjet1_eta, subjet1_phi, subjet1_mass_JES__{unc_name}_up, subjet2_pt_JES__{unc_name}_up, subjet2_eta, subjet2_phi, subjet2_mass_JES__{unc_name}_up)")
            a.Define(f"FatJet_msoftdrop_JES__{unc_name}_down", f"JME_invM(nFatJet, FatJet_subJetIdx1, FatJet_subJetIdx2, subjet1_pt_JES__{unc_name}_down, subjet1_eta, subjet1_phi, subjet1_mass_JES__{unc_name}_down, subjet2_pt_JES__{unc_name}_down, subjet2_eta, subjet2_phi, subjet2_mass_JES__{unc_name}_down)")




    print('\n----------------------------------------------------------------------------------------')
    print('------------------------------Finished AutoJME mSD--------------------------------------')
    print('----------------------------------------------------------------------------------------')
