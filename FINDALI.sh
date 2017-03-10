#!/bin/bash
#Simple bash script to search through AliPhysics and AliROOT looking for specified file name. If found, one can choose to open the .cxx and .h files with vim, or cd into the directory containing the file. 

installPath="${HOME}/alice/ali-master/"

if [ $# -ne 1 ]; then
  echo "Error: Search function accepts only one argument"
fi

filename=$1
location=$(find ${installPath}AliPhysics/ ${installPath}AliRoot/ -iname ${1}.cxx)
if [ -z ${location} ];then #Checks if the string is empty
  echo "No file matching ${1} can be found in current version of AliPhysics or AliROT"
  exit 
fi

echo "File found in $(dirname $location)"
read -p "Type \"show\" to show .h and .cxx files, or \"go\" to cd into directory: " answer
case $answer in
  show ) vim -O $(dirname $location)\/${filename}.{h,cxx} ;; #Open both files with vertical split in vim
  go ) cd $(dirname $location)\/ ;;
  #* ) echo "`basename $0` :usage SEARCHALI [filename without extension]" ;;
  * ) echo "Invalid option." ;;
esac
