/**
*	This file contains some functions to
*	handle with strings in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char stringOne[30];                         //  first string
    char stringTwo[] = "A simple C string.";    //  second string

    /*  concatenation
    *   char *strcat(char *s1, const char *s2);
    *
    *   Doesn't work in C:  stringOne = stringOne + stringTwo
    */
    printf("%s\n", strcat(stringOne, stringTwo));

    /*  comparison
    *   int strcmp(const char *s1, const char *s2);
    */
    printf("%d\n", strcmp(stringOne, "A simple C string!"));

    /*  copy string
    *   char *strcpy(char *s1, const char *s2);
    *
    *   Doesn't work in C:  stringOne = "Hello World!";
    */
    printf("%s\n", strcpy(stringOne, "Hello World!"));

    /*  string length
    *   size_t strlen(const char *s);
    *
    *   size_t := unsigned int
    */
    printf("%lu\n", strlen(stringOne));

    return EXIT_SUCCESS;
}
