/**
*	Contains the functions.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerFile.h"

void addDataToStruct(struct SExample *example_S) {
    example_S->i = 10;
    example_S->f = 15.4F;
    strcpy(example_S->cString, "Hello World!");
}

void printToConsole(struct SExample *example_S) {
    printf("OUTPUT:\n\n i = %d\n f = %lf\n cString = \"%s\"\n", example_S->i, example_S->f, example_S->cString);
}
