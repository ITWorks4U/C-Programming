/**
*	Keywords in C.
*
*	@author			ITWorks4U
*/

#include "extern.h"
#include <stdio.h>

int fnctCtr;										/*	counts the function call; available for outside	using	*/

void exampleExternKeyword() {
	puts(" Hello from exampleExternKeyword()!");
	fnctCtr++;
}
