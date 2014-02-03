#!/bin/sh
# Script by Marco "soniyj" Matascioli

# Cpp file name will create the same library name
FILEN=$1

if [ ! -z $1 ]
then
	echo "Compiling $FILEN"
	g++ -c -g -Wall -Werror -fPIC $FILEN

	FILEN=`echo $FILEN | sed 's/.cpp//g'`
	echo "Linking $FILEN.o"
	echo "Making lib$FILEN.so"
	g++ -g -shared -o lib$FILEN.so $FILEN.o
fi

