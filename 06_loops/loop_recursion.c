/**
*	This file contains the difference between
*	a loop and a recursion.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>

/*  recursive function */
int calculateGCDRecursive(int a, int b);

/*  normal loop function    */
int calculateGCDLoop(int a, int b);

int main() {
	/*	for loop	*/
	int i;
	for (i = 0; i < 10; i++) {
		printf(" I was called!\n");
	}

	/*	while loop	*/
	i = 10;
	while (i != 0) {
		printf(" I was called!\n");		
		i--;
	}

	/*	do-while loop	*/
	do {
		i++;
		printf(" I was called!\n");
	} while (i != 10);


	/*	an implemenation with a loop and a recursion	*/
    int a = 14;
    int b = 2;
    
    printf("RECURSIVE: GCD(14,2) = %d\n", calculateGCDRecursive(a,b));
    printf("LOOP: GCD(14,2) = %d\n", calculateGCDLoop(a,b));    

    return EXIT_SUCCESS;
}

int calculateGCDLoop(int a, int b) {
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    int res = (a % b);
    while (res > 0) {
        a = b;
        b = res;
        res = (a % b);
    }

    return b;
}

int calculateGCDRecursive(int a, int b) {
    if (b == 0) {
        return a;
    }

    return (calculateGCDRecursive(b, a % b));
}
