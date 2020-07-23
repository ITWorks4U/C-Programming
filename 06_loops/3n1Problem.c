/**
*	This file contains an implementation of
*	the Collatz conjecture by using a
*	recursion and loop to compare which
*	one is faster.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define LONG_DIGIT  unsigned long long

/*  NUMBER_TO_TEST = 8,753,954,347,574,347,623  */
#define NUMBER_TO_TEST  8753954347574347623

/*  method definitions  */
void collatzRecursive(LONG_DIGIT number);
void collatzIteration(LONG_DIGIT number);
void printCurrentNumber(LONG_DIGIT number);

int main() {
    clock_t start;
    clock_t end;

    /*  by using recursive way  */
    start = clock();
    collatzRecursive(NUMBER_TO_TEST);
    end = clock();
    printf("\n\nI needed %050lf seconds for this method!\n", (double) (end - start) / CLOCKS_PER_SEC);

    start = 0;
    end = 0;

    /*  by using a loop */
    start = clock();
    collatzIteration(NUMBER_TO_TEST);
    end = clock();
    printf("\n\nI needed %050lf seconds for this method!\n", (double) (end - start) / CLOCKS_PER_SEC);    

    return EXIT_SUCCESS;
}

/*  Calculating collatz problem by recursive way.
*
*   param:      number
*               any positive number > 0
*/
void collatzRecursive(LONG_DIGIT number) {
    if (number == 1) {
        printCurrentNumber(number);
    } else if ((number % 2) == 0) {
        printCurrentNumber(number);
        collatzRecursive(number / 2);
    } else {
        printCurrentNumber(number);
        collatzRecursive(3 * number + 1); 
    }
}

/*  Calculating collatz problem by using a loop.
*
*   param:      number
*               given positive number > 0
*/
void collatzIteration(LONG_DIGIT number) {
    while (number >= 1) {
        if (number == 1) {
            printCurrentNumber(number);
            break;
        } else if ((number % 2) == 0) {
            printCurrentNumber(number);
            number = (number / 2);
        } else {
            printCurrentNumber(number);
            number = (3 * number + 1);
        }
    }   
}

/*  Just print the current number on the console.   */
void printCurrentNumber(LONG_DIGIT number) {
    printf("%llu\n", number);
}
