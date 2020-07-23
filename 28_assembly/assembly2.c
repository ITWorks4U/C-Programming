/**
*	How to combine assembly with C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b);

int sum(int a, int b) {
	int sum = a + b;
	return sum;
}

int main() {
	printf(" sum = %d\n", sum(10,20));

	return EXIT_SUCCESS;
}
