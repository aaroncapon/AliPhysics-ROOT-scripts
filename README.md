# ROOT functions and scripts  
This repository is central space to store commonly used ROOT functions, e.g. formatting histograms, creating TLatex labels, calculating pair variables and dielectron spectrum quantities.  
The included setup script creates a symlink from your home directory to the rootrc contained in ~/AliPhysics-ROOT-scripts/. Any existing rootrc will be moved to ~/.rootrc_OLD.  
 
## ROOT Functions
**rootlogon.C**    - ALICE plotting defaults, color adjustments, analysis specific plotting bins  
**rootalias.C**    - common histogram formatting functions  
**diElecFuncs.C**  - calculate signal and background distributions, R factors, etc  
**pairingFuncs.C** - calculate pair variables (typically used when creating local pair TTrees)  
**texLabels.C**    - simple functions to create commonly created TLatex labels for plotting  
plus a few structure and array files which are specific to the analyses of LHC16q (pPb 5TeV)  


## Bash Scripts 
**SEARCHALI** - Search through AliPhysics for a specific class (do not include file extensions in search). If found, open .cxx and .h in ${EDITOR}, or alternatively cd into directory. 
