#!/bin/bash

#compile program
gcc -g -Wall -o MallocCalloc.run memory.c

#start
echo "Demonstration of malloc and calloc:"

./MallocCalloc.run

