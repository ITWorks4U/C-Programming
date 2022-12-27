#include <stdio.h>
#include <stdlib.h>

/*
	Macro functions allows you to write less code for a big result,
	however, if you don't mind, you'll receive a logic error.
	Logic errors can't be detected by any compiler. On runtime
	you MIGHT see the difference in contrast to the expectation.
*/

#define		QUBIC_WRONG(X) (X * X * X)										//	Missing brackets causes a wrong result!
#define		QUBIC_CORRECT(X) ((X) * (X) * (X))

int qubic_function(int number) {
	return number * number * number;
}

int main() {
	int a = 123;
	int b = 61;

	printf("wrong: (%d - %d)^3 = %d\n", a, b, QUBIC_WRONG(a-b));
	printf("correct: (%d - %d)^3 = %d\n", a, b, QUBIC_CORRECT(a-b));
	printf("by function: (%d - %d)^3 = %d\n", a, b, qubic_function(a-b));

	return EXIT_SUCCESS;
}