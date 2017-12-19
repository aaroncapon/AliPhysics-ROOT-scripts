# ROOT scripts
This repository contains a collection of scripts that I use to make using ROOT/AliPhysics easier.  
The setup script creates a symlink from your home directory to the rootrc contained in ~/AliPhysics-ROOT-scripts/. Any existing rootrc will be moved to ~/.rootrc_OLD.  
 
ALIENV - Remain in current directory when entering AliPhysics.  
SEARCHALI - Search through AliPhysics. If found, open .cxx and .h in editor, or alternatively cd into directory. 

rootrc  
rootlogon.C - ALICE plotting defaults, color adjustments, analysis specific plotting bins  
rootalias.C - analysis functions (comb backgr., R factor, etc)  
