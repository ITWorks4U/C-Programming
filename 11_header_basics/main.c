/**
*	Holds the main function only.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include "headerFile.h"

int main() {
	struct SExample *example_S = (struct SExample *) malloc(sizeof(struct SExample));

	addDataToStruct(example_S);
	printToConsole(example_S);

	free(example_S);

	return EXIT_SUCCESS;
}
