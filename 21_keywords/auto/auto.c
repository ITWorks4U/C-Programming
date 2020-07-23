/**
*	Keywords in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include "../keywords.h"

void exampleAutoKeyword() {
	/*
	*	In C the keyword 'auto' has become obsolete
	*	and it's hardly used.
	*
	*	It's still available from the previous programming
	*	language 'B' and it's useful for backward compability.
	*	
	*	Every variable, data type etc. with the keyword 'auto'
	*	specifies a storage duration. When you create an auto
	*	variable it has an "automatic storage duration".
	*
	*	It's the same as "local variables", where in C all
	*	variables in functions are local by default.
	*/
	auto int auto_number = FIXED_NUMBER;
	int normal_number = (FIXED_NUMBER * FIXED_NUMBER);

	printf(" auto_number = %d,\n normal_number = %d\n", auto_number, normal_number);
}

