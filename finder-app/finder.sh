#!/bin/bash
# check arguments
if [ -z "$1" ] || [ -z "$2" ]; then
	echo "parameters are not specified"
	exit 1
fi

# check if is directory
if [ ! -d "$1" ]; then
	echo "$1 is not a directory"
	exit 1
fi
# total files
total_files=$(find $1 -type f | wc -l | tr -d " ")

# find text
y=$(grep -rnw "$1" -e "$2" | wc -l | tr -d " ")
echo "The number of files are $total_files and the number of matching lines are $y"

