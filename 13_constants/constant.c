/**
*	Different ways to define and use constants.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	/*
	*	first type of constant defintion:
	*	by using const
	*/
	const int value = 13;
	printf(" value = %d\n", value);

	/*
	*	second type of constant defintion:
	*	by using MACROS
	*/
	#define EULER 2.71828182845904523536
	#define MASS_ELECTRON 9.1093897e-31
	printf(" EULER = %lf\n", EULER);
	printf(" mass of an electron: %e\n", MASS_ELECTRON);

	/*
	*	third type of constant defintion:
	*	by using an anonymous enumeration
	*/
	enum {
		first = 31, second = 42, third = 3, fourth = 97
	};
	printf(" first = %u\n", first);
	printf(" second = %u\n", second);
	printf(" third = %u\n", third);
	printf(" fourth = %u\n", fourth);

	return EXIT_SUCCESS;
}
