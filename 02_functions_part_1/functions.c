/**
*	This source file shows you some
*	basic examples with functions in C.
*
*	Be default, in C/C++ the functions
*	must have a prototype to work with
*	the functions in the future.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

void noReturnFunction();
int booleanCondition(int number);
float getMaximumFloatSize();
unsigned long getMaximumLongValue();
long getRegularLongValue();

int main() {
    /*  void function   */
    noReturnFunction();

    long longValue = 4L;

    /*  boolean function    */
    printf("Return value of function = %i\n", booleanCondition(5));

    /*  integer values  */
    printf("Return value of function = %ld\n", longValue);

    /*  system based integer values */
    printf("maximum number of float: %lf\n", getMaximumFloatSize());
    printf("maximum positive long value: %lu\n", getMaximumLongValue());    

    /*  equal to return 0   */
    return EXIT_SUCCESS;
}

void noReturnFunction() {
    puts("This function doesn't need a return command.");
}

int booleanCondition(int number) {
    if (number == 5) {
        return 1;
    }

    return 0;
}

float getMaximumFloatSize() {
    return FLT_MAX;
}

unsigned long getMaximumLongValue() {
    return ULONG_MAX;
}

long getRegularLongValue() {
    return LONG_MAX;
}
