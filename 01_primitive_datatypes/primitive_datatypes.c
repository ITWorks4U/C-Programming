/**
*	Prints the sizes of the basic
*	primitive datatypes in C.
*
*	@author		ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("char: %lu bytes\n", sizeof(char));
    printf("short: %lu bytes\n", sizeof(short));
    printf("int: %lu bytes\n", sizeof(int));
    printf("long: %lu bytes\n", sizeof(long));
    printf("float: %lu bytes\n", sizeof(float));
    printf("double: %lu bytes\n", sizeof(double));
    printf("unsigned int: %lu bytes\n", sizeof(unsigned int));
    printf("unsigned long long: %lu bytes\n", sizeof(unsigned long long));

    return 0;
}
