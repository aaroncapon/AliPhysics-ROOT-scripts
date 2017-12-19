#!/bin/bash
############################
# .make.sh
# This script creates symlinks from the home directory to any desired dotfiles in ~/dotfiles
############################

########## Variables

dir=~/AliPhysics-ROOT-scripts                    
files="rootrc"    # list of files/folders to symlink in homedir

##########

# change to the dotfiles directory
echo "Changing to the $dir directory"
cd $dir
echo "...done"

# move any existing dotfiles in homedir to dotfiles_old directory, then create symlinks 
for file in $files; do
    echo "Renaming any existing rootrc to rootrc_OLD"
    mv ~/.$file ~/.${file}_OLD
    echo "Creating symlink to $file in home directory."
    ln -s $dir/$file ~/.$file
done
