#!/bin/bash

# Name conventions:
#
# k_foo - foo is a function that doesn't "return" anything.
#
# kr_foo - foo is a function that "returns" a value in $r
#
# kv_bar - bar is a variable that keeps persistent values between executions.
#
#
#
#
#
#
#

function kattis {

	case $# in
		"1")
			k_kattisMain $1 $kv_currentProblem 
			;;
		"2")
			k_kattisMain $1 $2
			;;
		*)
			echo "Wrong number of arguments: $#, must be 1 or 2"
			k_usage
			return -1
			;;
	esac
}

function k_kattisMain
{
	action=$1
	problem=$2

	if [[ $problem == "" ]]; then
		case $action in
		"?")
			k_query
			return 0
			;;
		"!")
			k_reset
			return 0
			;;
		*)
			echo "No problem given. Use action 'init' or '!'"
			k_usage
			return -1
		esac
	fi

	case $action in
		"init") 
			k_init
			;;
		"test")
			k_test
			;;
		"run") 
			k_run
			;;
		"rundebug")
			k_run_debug
			;;
		"commit")
			k_commit
			;;
		"core")
			k_core
			;;
		"submit")
			k_submit
			;;
		"?")
			k_query
			return 0
			;;
		"!")
			k_reset
			return 0
			;;
		*)
			echo "Invalid action: \"$action\""
			k_usage
			return -1
			;;
	esac
}

function k_init
{
	echo "Action INIT for problem \"$problem\""
	mkdir $problem
	pushd $problem
	wget https://open.kattis.com/problems/$problem/file/statement/samples.zip
	if [ $? -ne 0 ]; then
		echo "Error: \"$problem\" does not seem to be a valid kattis problem."
		popd
		rm -rf $problem
		return -1
	else
		cp -i ../TEMPLATE.cpp $problem.cpp
		unzip -d samples samples.zip
		rm -f samples.zip
		popd

		kv_currentProblem=$problem
		gvim $problem/$problem.cpp
	fi
}

function k_test
{
	echo "Action TEST for problem \"$problem\""
	pushd $problem
	k_build $problem
	if [ $? -eq 0 ]; then
		for n in samples/*.in; do
			echo "Running sample $n ..."
			cat $n | ./$problem.bin > samples/`basename $n .in`.out
			diff samples/`basename $n .in`.out samples/`basename $n .in`.ans
			echo "Done."
		done
	else
		echo "Error: Build failed, not running tests."
	fi
	popd
}

function k_run
{
	echo "Action RUN for problem \"$problem\""
	pushd $problem
	k_build $problem
	if [ $? -eq 0 ]; then
		echo "Build successful."
		for n in samples/*.in; do
			echo "Running sample $n ..."
			cat $n | ./$problem.bin
			echo "Done."
		done
	else
		echo "Error: Build failed, not running tests."
	fi
	popd
}

function k_run_debug
{
	echo "Action RUN DEBUG for problem \"$problem\""
	pushd $problem
	k_build_debug $problem
	if [ $? -eq 0 ]; then
		echo "Debug build successful."
		for n in samples/*.in; do
			echo "Running sample $n ..."
			cat $n | ./$problem.bin
			echo "Done."
		done
	else
		echo "Error: Build failed, not running tests."
	fi
	popd
}

function k_commit
{
	echo "Action COMMIT for problem \"$problem\""
	git add $problem
	git commit -m"Solve problem: $problem"
	git log -n1
	git status
}

function k_submit
{
	echo "Action SUBMIT for problem \"$problem\""
	python3 submit.py -p $problem $problem/$problem.cpp
}

function k_core
{
	echo "Action CORE for problem \"$problem\""
	gdb $problem/$problem.bin $problem/core
}

function k_query
{
	echo "Current problem is \"$kv_currentProblem\""
}

function k_reset
{
	if [[ $problem == $kv_currentProblem ]]; then
		echo "Unbinding current problem. (It was \"$kv_currentProblem\")"
		kv_currentProblem=""
	else
		echo "Rebinding current problem to \"$problem\". (It was \"$kv_currentProblem\")"
		kv_currentProblem=$problem
	fi
}

function k_usage
{
	echo ""
	echo "usage: kattis <action> [problem]"
	echo ""
	echo "problem - name of a kattis problem as it shows up in the URL https://open.kattis.com/problems/<problem>"
	echo ""
	echo "action  - one of init, test, run, commit"
	echo ""
}


function k_build {
	if [[ "0" == $(grep float $1.cpp | wc -l) ]]; then
		g++ -g -O2 -static -std=gnu++11 -o $1.bin $1.cpp
	else
		echo "Don't use float, you idiot!!!"
		return -1
	fi
}

function k_build_debug {
	if [[ "0" == $(grep float $1.cpp | wc -l) ]]; then
		g++ -ggdb -O0 -static -std=gnu++11 -o $1.bin $1.cpp
	else
		echo "Don't use float, you idiot!!!"
		return -1
	fi
}
