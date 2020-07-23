/**
*	This file contains the definition
*	of an enumeration in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>

/*  default enumeration    */
enum SystemState {
    WORKING, FAILED, TERMINATED
};

/*  extended enumertion */
enum Week {
    MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

int main() {
    int i;
    enum SystemState state;

    for (i = WORKING; i < 3; i++) {
        state = i;
        printf("state = %d\n", state);
    }

    for (i = MONDAY; i <= SUNDAY; i++) {
        printf("day = %d\n", i);
    }

    return EXIT_SUCCESS;
}
