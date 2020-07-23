/**
*	Implementation of struct and
*	union by using pointers.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SExample {
    int i;
    float f;
    char cString[20];
};

union UExample {
    int i;
    float f;
    char cString[20];
};

int main() {
    struct SExample *example_S = (struct SExample*) malloc(sizeof(struct SExample));

    example_S->i = 10;
    example_S->f = 15.4F;
    strcpy(example_S->cString, "Hello World!");

    printf("OUTPUT:\n\n i = %d\n f = %lf\n cString = \"%s\"\n", example_S->i, example_S->f, example_S->cString);

	free(example_S);

    return EXIT_SUCCESS;
}
