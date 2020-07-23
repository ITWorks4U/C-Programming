/**
*	This file contains the difference
*	between a struct and an union in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
enum Type { INTS, FLOATS, DOUBLE };

/*  first structure: without using union    */
struct S1 {
    enum Type s_type;

    int intArr[2];
    float floatArr[2];
    double sDouble;
};

/*  second structure: with using union      */
struct S2 {
    enum Type s_type;

    union {
        int intArr[2];
        float floatArr[2];
        double sDouble;
    };
};

int main() {
    /*  What is going to print to the terminal? */
    printf("size of S1 = %lu bytes\n", sizeof(struct S1));
    printf("size of S2 = %lu bytes\n", sizeof(struct S2));
    printf("size of Type = %lu bytes\n", sizeof(enum Type));

    return EXIT_SUCCESS;
}
