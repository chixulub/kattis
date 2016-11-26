#!/bin/bash

# CHECK FOR PARAMETERS
if [ -z $1 ]; then
	echo "build: No problem name or command given."
	exit
fi

# INIT PROBLEM
if [ $1 == '-i' ]; then
	if [ -z $2 ]; then
		echo "build.init: No name given."
		exit -1
	fi

	if [ -d $2 ]; then
		echo "build.init: Name already taken."
	else
		echo "build.init: Initializing problem \"$2\""
		mkdir $2
		pushd $2
		wget https://open.kattis.com/problems/$2 -O $2.html
		cp ../TEMPLATE.cpp $2.cpp
		if [ $? -ne 0 ]; then
			echo "build.init: \"$2\" does not seem to be a valid kattis problem."
			popd
			rm -rf $2
			exit -1
		fi
		wget https://open.kattis.com/problems/$2/file/statement/samples.zip
		unzip -d samples samples.zip
		rm -f samples.zip
		popd
	fi

	gvim $2/$2.cpp
	exit
else


pushd $1
	g++ -g -O2 -static -std=gnu++11 -o $1.bin $1.cpp && ./$1.bin
popd

fi
