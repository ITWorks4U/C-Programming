/**
*	This source file shows you some math functions.
*
*	Linux: Make sure to link this library with -lm command
*	for the compiler.
*
*	@author				ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int number;
    double squareRoot;
    double power;
	double sine, cosine, tangens;

    /*  Force the user to enter a number.   */
    printf("Please enter an integer number: ");
    scanf(" %d", &number);

    /*  using some math functions in math.h  */
	squareRoot = sqrt(number);
	power = pow(number, 7.0);
	sine = sin(number);
	cosine = cos(number);
	tangens = tan(number);
	
	printf(" square root: %f\n power: %f\n sine: %f\n cosine: %f\n tangens: %f\n",
	squareRoot, power, sine, cosine, tangens);

    return EXIT_SUCCESS;
}
