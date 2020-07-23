/**
*	This file contains some input
*	possibilities.
*
*	@author		ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	/*  Definition of a string which holds up to 31(!) characters + '\0',
	*	but this C string below will contain random characters at runtime,
	*	unless you assign this with '\0'.
	*/
    char stringLimit[32];

	/*
    *   Posible input functions:        			<stdio.h>
	*
	*	int scanf(const char *format, ...);
	*												The  scanf()  family of functions scans input according to the format.
	*												This format may contain conversion specifications; the results from
	*												such conversions, if any, are stored in the locations pointed to by the
	*												pointer arguments that follow format.  Each pointer argument must be of a
	*												type that is appropriate for the value returned by the corresponding
	*												conversion specification.
	*
    *   char *gets(char *buffer);
    *                                   			Read the complete line; function doesn't know the input size.
    *                                   			Often causes a segmentation fault -> DO NOT USE THIS FUNCTION!!
    *
    *   char *fgets(char *buffer, int n, FILE *file);
    *
    *                                   			Read the complete line until the size of n has been reached.
    *                                   			May also cause a segmentation fault, if the size of the input
    *                                   			exceeds defined limit.
    */

	/*	using scanf function	*/
    printf("Enter any word: ");
    scanf(" %s", stringLimit);
    printf("Your input: %s\n", stringLimit);

    /*	using fgets function	*/
    printf("Enter any word: ");
    fgets(stringLimit, 20, stdin);
    printf("Your input: %s\n", stringLimit);

    /*  equal to return 0   */
    return EXIT_SUCCESS;
}
