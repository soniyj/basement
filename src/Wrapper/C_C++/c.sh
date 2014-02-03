#!/bin/sh
# Script by Marco "soniyj" Matascioli

# In case the rpath doesn't work export the path
#export LD_LIBRARY_PATH=$MDIR:$LD_LIBRARY_PATH

# Executable file name
FILEN=$1
# Library file name without lib and .so extension
LIBFILE=$2

# Command substitution to get the working directory
#MDIR=$(pwd)
MDIR=`pwd`

if [ ! -z $1 ]
then
	echo "Working directory $MDIR"

	LIBFILE=`echo $LIBFILE | sed 's/lib//g' | sed 's/.so//g'`
	echo "Library $LIBFILE"

	FILEN=`echo $FILEN | sed 's/.c//g'`
	echo "Making $FILEN.exe"
	gcc -L$MDIR/ -g -Wall $FILEN.c -o $FILEN.exe -l$LIBFILE -Wl,-rpath=$MDIR
fi

