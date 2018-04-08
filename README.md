# ROOT functions and scripts
This repository is central space to store commonly used ROOT functions, e.g. formatting histograms, creating TLatex labels, calculating pair variables and dielectron spectra quantities  
The included setup script creates a symlink from your home directory to the rootrc contained in ~/AliPhysics-ROOT-scripts/. Any existing rootrc will be moved to ~/.rootrc_OLD.  
 

rootrc  
rootlogon.C    - ALICE plotting defaults, color adjustments, analysis specific plotting bins  
rootalias.C    - commong root functions (hist plotting etc)  
diElecFuncs.C  - calculate signal and background distributions, R factors, etc  
pairingFuncs.C - calculate pair variables (typically used when creating local pair TTrees)  
texLabels.C    - simple functions to create commonly created TLatex labels for plotting  
plus a few structure and array files which are specific to the analyses of LHC16q (pPb 5TeV)  


In addition to the function files, there is a simple bash script to search AliPhysics and open the results in a split in the terminal for quick access.  
SEARCHALI - Search through AliPhysics. If found, open .cxx and .h in editor, or alternatively cd into directory. 
