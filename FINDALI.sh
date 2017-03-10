#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Error: Alisearch accepts only one argument"
fi
filename=$1
location=$(find /home/aaron/alice/ali-master/AliPhysics/ /home/aaron/alice/ali-master/AliRoot/ -iname *${1}*.cxx)
if [ -z ${location} ];then # -z checks that the string has zero length
  echo "No file matching ${1} can be found in AliPhysics"
  return
fi

alicheck=${filename:0:3}
if [ $alicheck == Ali ]; then
  tabname=${filename:3:}
fi


echo "File found in $(dirname $location)"
read -p "Type \"show\" to show .h and .cxx files, or \"go\" to cd into directory: " answer
case $answer in
  show ) vim -O $(dirname $location)\/${filename}.{h,cxx} ;; #Open both files with vertical split in vim
  go ) cd $(dirname $location)\/ ;;
  #* ) echo "`basename $0` :usage SEARCHALI [filename without extension]" ;;
  * ) echo "Invalid option." ;;
esac
