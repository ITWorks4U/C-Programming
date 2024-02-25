#!/usr/bin/python3

'''
	Just a simple python script to create 250,000 random numbers
	in a range of {0;250,000}.
'''

import random as r

max = 250000
collection = list()

for i in range(max):
	collection.append(r.randrange(0,max))
#end for

with open('random_numbers.txt', mode='w') as f:
	for i in collection:
		print(i, file=f, end=', ')
	#end for
#end with