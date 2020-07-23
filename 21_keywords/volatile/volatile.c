/**
*	Keywords in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include "../keywords.h"

void exampleVolatileKeyword() {
	/*
	 *	The volatile keyword is a qualifier that is applied to
	 *	a variable when it's declared. It tells the compiler
	 *	that the value of the variable may change at any time.
	 *
	 *	Without any action being taken by the code the compiler
	 *	finds nearby. The implications of this are quite serious.
	 *
	 *	However, a variable should be declared volatile whenever it's
	 *	value could change unexpectedly. In practice, only three
	 *	types of variables could change:
	 *
	 *	-	memory mapped peripheral registers
	 *	-	global variables modified by an interrupt service routine
	 *	-	global variables accessed by multiple tasks within a
	 *		multi-threaded application.
	 */

	const volatile int local = 10;
	int *iPtr = (int *) &local;
	printf(" initial value of local: %d\n", local);

	*iPtr = 100;
	printf(" initial value of local: %d\n", local);
}
