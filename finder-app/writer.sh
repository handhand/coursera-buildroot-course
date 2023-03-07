#!/bin/bash
if [ -z "$1" ] || [ -z "$2" ]; then
	echo "parameters are not specified"
	exit 1
fi
DIR=$(dirname $1)
echo $DIR
if [ ! -d $DIR ]; then
	echo "make directory $DIR"
	mkdir -p $DIR
fi
echo $2 > $1
