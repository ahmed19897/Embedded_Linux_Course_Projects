#!/bin/bash

	cd ~/Desktop/EmbeddedLinux/Bash/dip
	files=$(ls)
#list all the available fles
	echo "File available are:"$files


#removing each file
	for i in ${files[@]} ;
	do
		rm $i;
		echo "file $i removed"	
	done

#removing the directory
	#removing the space after the = made the pwd dumb its return to directory
	directory=$(pwd)
	cd ..
	rmdir $directory
	echo "directory $directory removed"
