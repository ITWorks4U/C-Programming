/**
*	How to handle with GOTO commands.
*
*	Not recommended, because a goto
*	command causes the 'spaghetti code'.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	printf(" *** GOTO command in C ***\n");
	int ctr = 0;
	
	/*	using goto command	*/
	BEYOND_THIS_POINT:
	ctr++;
	printf(" My ctr value contains the value %d\n", ctr);

	if (ctr != 10) {
		goto BEYOND_THIS_POINT;
	}

	printf(" End of program.\n");
	return EXIT_SUCCESS;
}
