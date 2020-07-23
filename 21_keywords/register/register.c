/**
*	Keywords in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include "../keywords.h"

void exampleRegisterKeyword() {
	/*
	*	In C the keyword 'register' sugggests to the
	*	compiler that the current variable should be
	*	stored in a CPU register, rather than into
	*	the memory.
	*
	*	Usage: To store variables into a register, the
	*	data is accessed faster than data, which is stored
	*	in memory, however, it's only a "hint" to the
	*	compiler and it could ignore it.
	*w
	*	Every variable, which is stored into a register
	*	doesn't have an information WHERE this variable
	*	is stored, thus it's not possible to use "%p".
	*/
	int values[FIXED_NUMBER];								//	normal definition
	register int ctr;										//	register typed definition
	int arrLength = (sizeof(values) / sizeof(values[0]));

	/*	
	*	Finally, the register is a storage class specifier.
	*	We can't use more than one storage class for a register variable.
	*
	*	register static int number;
	*	register auto int number;
	*	register extern int number;
	*/

	for (ctr = 0; ctr < arrLength; ctr++) {
		values[ctr] = ctr;
	}

	//printf(" ctr is stored on address: %p\n", ctr);		//	--> The compiler will refuse it's job here.

	printf(" values = {");	
	for (ctr = 0; ctr < arrLength; ctr++) {
		if (ctr < (arrLength - 1)) {
			printf("%d, ", values[ctr]);					//	normal output
		} else {
			printf("%d", values[ctr]);						//	last element
		}
	}
	printf("}\n");
}
