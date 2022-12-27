#include <stdio.h>
#include <stdlib.h>
#include "18_header.h"

int main() {
	int a = 100;
	int b = 200;

	//	calling external functions from main
	printf("%d + %d = %d\n", a, b, add(a,b));
	printf("%d - %d = %d\n", a, b, subtract(a,b));
	printf("%d * %d = %d\n", a, b, multiply(a,b));
	printf("%d / %d = %d\n", a, b, divide(a,b));
	printf("%d %% %d = %d\n", a, b, modulo(a,b));				//	%% for a single %

	return EXIT_SUCCESS;
}