#!/bin/bash

function Build {
	g++ -g -O2 -static -std=gnu++11 -o $1.bin $1.cpp
}

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
elif [ $1 == '-t' ]; then
	if [ -z $2 ]; then
		echo "build.test: No name given."
		exit -1
	fi

	pushd $2
	Build $2
	if [ $? -eq 0 ]; then
		for n in samples/*.in; do
			echo "Running sample $n ..."
			cat $n | ./$2.bin > samples/`basename $n .in`.out
			diff samples/`basename $n .in`.out samples/`basename $n .in`.ans
			echo "Done."
		done
	else
		echo "Build failed, not running tests."
	fi
	popd
elif [ $1 == '-r' ]; then
	pushd $2
	Build $2
	for n in samples/*.in; do
		echo "Running sample $n ..."
		cat $n | ./$2.bin
		echo "Done."
	done
	popd
else
	pushd $1
	Build $1
	popd
fi
