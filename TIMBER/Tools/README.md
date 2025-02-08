# TIMBER Tools repository

## Automatic JES + JER corrections

There are two modules for automatically applying per-event, per-jet jet energy corrections.

### `AutoJME_correctionlib.py`

This script handles the automatic application of per-event, per-jet jet energy corrections to a given jet collection using the `correctionlib` library. 

Example usage:
```python
import TIMBER.Tools.AutoJME_correctionlib as AutoJME

a = analyzer('2018_MC.root')

jetCollection = 'FatJet'
year          = '2018_UL'
dataEra       = ''
calibrate     = True

AutoJME.AutoJME(a, jetCollection, year, dataEra, calibrate)
```

Parameters:

* `a` (analyzer): TIMBER analyzer object to be manipulated and returned.
* `jetCollection` (string): Name of the jet collection to correct.
    * The default jet collections in NanoAOD are FatJet (AK8) and Jet (AK4).
    * However, you can also pass a custom collection built from either of these by changing the AK8/AK4collection values above.
        * An example of a custom collection would be, e.g., one created using `TIMBER.Analyzer.SubCollection()`
* `year` (string): The full year corresponding to the MC or Data sample. Valid options are:
    * Run 2 options: `2016preVFP_UL/EOY`, `2016postVFP_UL/EOY`, `2017_UL/EOY`, `2018_UL/EOY`
        * Note that `2016APV` corresponds to `2016_preVFP` and `2016` corresponds to `2016postVFP`
    * Run 3 options: `2022_Prompt`, `2022_Summer22`, `2022_Summer22EE`, `2023_Summer23`, `2023_Summer23BPix`, `2024_Winter24`
        * Note that, as of Feb. 8, 2025, there are no JEC corrections for AK8 jets.
* `dataEra` (string): If providing data, include the "era" (e.g. A,B,C,D,..). The valid era strings for the different data-taking years are described below:

| Data-taking year   | Valid `dataEra` strings                             |
|--------------------|-----------------------------------------------------|
| 2016preVFP_UL/EOY  | `B`, `C`, `D`, `E`, `F`                             |
| 2016postVFP_UL/EOY | `F`, `G`, `H`                                       |
| 2017_UL/EOY        | `B`, `C`, `D`, `E`, `F`                             |
| 2018_UL/EOY        | `A` `B` `C` `D`                                     |
| 2022_Prompt        | `C`, `D`                                            |
| 2022_Summer22      | `C`, `D`                                            |
| 2022_Summer22EE    | `E`, `F`, `G`                                       |
| 2023_Summer23      | `Cv123`, `Cv4`                                      |
| 2023_Summer23BPix  | `D`                                                 |
| 2024_Winter24      | (AK4 _only_) `B`, `C`, `D`, `E`, `F`, `G`, `H`, `I` |

* `calibrate` (bool): Defaults to `True`. Whether or not to calibrate the pT and mass using the JEC corrections. If `True`, then new columns will be created containing the JER- (MC only) and JES-corrected pT and masses, as shown below. If `False`, then only the `JES/JER_nom/up/down` columns will be created.

Example output running on MC with `calibrate=True` passed to `AutoJME()`:
```
# First, the JES correction is calculated...
Defining FatJet_JES__vec: FatJet_JES.eval(FatJet_pt, FatJet_eta, FatJet_phi, FatJet_area, fixedGridRhoFastjetAll)
Defining FatJet_JES__vecT: hardware::Transpose(FatJet_JES__vec)
Defining FatJet_JES_nom: FatJet_JES__vecT.size() > 0 ? FatJet_JES__vecT[0] : RVec<float> (0);
Defining FatJet_JES_up: FatJet_JES__vecT.size() > 0 ? FatJet_JES__vecT[1] : RVec<float> (0);
Defining FatJet_JES_down: FatJet_JES__vecT.size() > 0 ? FatJet_JES__vecT[2] : RVec<float> (0);

# Then, the JER correction is calculated...
Defining FatJet_JER__vec: FatJet_JER.eval(FatJets, GenJetAK8s, fixedGridRhoFastjetAll)
Defining FatJet_JER__vecT: hardware::Transpose(FatJet_JER__vec)
Defining FatJet_JER_nom: FatJet_JER__vecT.size() > 0 ? FatJet_JER__vecT[0] : RVec<float> (0);
Defining FatJet_JER_up: FatJet_JER__vecT.size() > 0 ? FatJet_JER__vecT[1] : RVec<float> (0);
Defining FatJet_JER_down: FatJet_JER__vecT.size() > 0 ? FatJet_JER__vecT[2] : RVec<float> (0);

# Then, the pT, regressed mass (mass), and softdrop mass (msoftdrop) variables are corrected...
Defining FatJet_pt_nom: hardware::MultiHadamardProduct(FatJet_pt,{FatJet_JES__vec,FatJet_JER__vec},0)
Defining FatJet_pt_JES__up: hardware::HadamardProduct(hardware::MultiHadamardProduct(FatJet_pt,{FatJet_JER__vec},0),FatJet_JES__vec,1)
Defining FatJet_pt_JES__down: hardware::HadamardProduct(hardware::MultiHadamardProduct(FatJet_pt,{FatJet_JER__vec},0),FatJet_JES__vec,2)
Defining FatJet_pt_JER__up: hardware::HadamardProduct(hardware::MultiHadamardProduct(FatJet_pt,{FatJet_JES__vec,},0),FatJet_JER__vec,1)
Defining FatJet_pt_JER__down: hardware::HadamardProduct(hardware::MultiHadamardProduct(FatJet_pt,{FatJet_JES__vec,},0),FatJet_JER__vec,2)
Defining FatJet_mass_nom: hardware::MultiHadamardProduct(FatJet_mass,{FatJet_JES__vec,FatJet_JER__vec},0)
Defining FatJet_mass_JES__up: hardware::HadamardProduct(hardware::MultiHadamardProduct(FatJet_mass,{FatJet_JER__vec},0),FatJet_JES__vec,1)
Defining FatJet_mass_JES__down: hardware::HadamardProduct(hardware::MultiHadamardProduct(FatJet_mass,{FatJet_JER__vec},0),FatJet_JES__vec,2)
Defining FatJet_mass_JER__up: hardware::HadamardProduct(hardware::MultiHadamardProduct(FatJet_mass,{FatJet_JES__vec,},0),FatJet_JER__vec,1)
Defining FatJet_mass_JER__down: hardware::HadamardProduct(hardware::MultiHadamardProduct(FatJet_mass,{FatJet_JES__vec,},0),FatJet_JER__vec,2)
Defining FatJet_msoftdrop_nom: hardware::MultiHadamardProduct(FatJet_msoftdrop,{FatJet_JES__vec,FatJet_JER__vec},0)
Defining FatJet_msoftdrop_JES__up: hardware::HadamardProduct(hardware::MultiHadamardProduct(FatJet_msoftdrop,{FatJet_JER__vec},0),FatJet_JES__vec,1)
Defining FatJet_msoftdrop_JES__down: hardware::HadamardProduct(hardware::MultiHadamardProduct(FatJet_msoftdrop,{FatJet_JER__vec},0),FatJet_JES__vec,2)
Defining FatJet_msoftdrop_JER__up: hardware::HadamardProduct(hardware::MultiHadamardProduct(FatJet_msoftdrop,{FatJet_JES__vec,},0),FatJet_JER__vec,1)
Defining FatJet_msoftdrop_JER__down: hardware::HadamardProduct(hardware::MultiHadamardProduct(FatJet_msoftdrop,{FatJet_JES__vec,},0),FatJet_JER__vec,2)
```
