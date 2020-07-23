/**
*	Keywords in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <string.h>
#include "../keywords.h"

/*	it's still visible in this file only.	*/
//static int callCounter = 0;						//	it has the same result like "./keywords.run static with_static"

void exampleStaticKeyword(const char *option) {
	/*
	 *	The static keyword in C is a storage-class specifier.
	 *	It has different meanings, depending on the context.
	 *
 	 *	Inside a function it makes a variable to retain it's value
	 *	between multiple function calls.
	 *
	 *	Outside of a function it retains the visibility of the
	 *	function or variable to the current file only.
	 */

	if ((strcmp(option, WITH_STATIC)) == 0) {
		static int callCounter = 0;
		printf(" Number of function call: %d\n", ++callCounter);
	} else {
		int callCounter = 0;
		printf(" Number of function call: %d\n", ++callCounter);
	}
}
