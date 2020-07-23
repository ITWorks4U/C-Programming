/**
*	This file contains the definition
*	of a struct and an union in C.
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

typedef struct SExample __SExample; 

union UExample {
    int i;
    float f;
    char cString[20];
};

int main() {
    __SExample example_S;
    union UExample example_U;

    example_S.i = 10;
    example_S.f = 15.4F;
    strcpy(example_S.cString, "Hello World!");

    printf("OUTPUT:\n\n i = %d\n f = %lf\n cString = \"%s\"\n", example_S.i, example_S.f, example_S.cString);

    example_U.i = 10;
    example_U.f = 15.4F;
    strcpy(example_U.cString, "Hello World!");

    printf("OUTPUT:\n\n i = %d\n f = %lf\n cString = \"%s\"\n", example_U.i, example_U.f, example_U.cString);    

    return EXIT_SUCCESS;
}
