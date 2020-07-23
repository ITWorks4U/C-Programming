#!/bin/bash
#	This script is going to run our program "exitExample.run" to
#	see which return value is going to get.
#
#	author			ITWorks4U

#	fist step:	build the program...
make all

#	then run the program...
./exitExample.run

#	get the return value...
ret=$?

#	check the return value
if [ $ret -eq 0 ]
then
	echo " Your program has been termianted with exit code: $ret."
else
	echo " ERROR: Your program has been terminated with exit code: $ret!"
fi
