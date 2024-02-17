/*
	Usually, there're three different ways to define a constant expression:
	const, #define, using an anonymous enumeration.

	However, const doesn't really define a constant expression...
*/
#include <stdio.h>
#include <stdlib.h>

/*
	Does this also affect the constant expression when using a function?
	Luckily, no... well, not really. °(^-^)
*/

/*
	Usually, you should define the arguments with const keyword to make sure
	not to be able to modify the argument. It doesn't matter which kind of
	function you're using.
*/
void function1(const int i) {
	int *ptrForI = &i;
	printf("before: i = %d (%p), ptrForI = %p (%d)\n", i, &i, ptrForI, ptrForI[0]);
	
	// ptrForI++;
	*ptrForI = 0xBEEF3000;
	printf("after: i = %d (%p), ptrForI = %p (%d)\n", i, &i, ptrForI, ptrForI[0]);
}

int function2(int i) {
	int *ptrForI = &i;
	printf("before: i = %d (%p), ptrForI = %p (%d)\n", i, &i, ptrForI, ptrForI[0]);
	
	//ptrForI++;
	*ptrForI = 0xBEEF3000;
	printf("after: i = %d (%p), ptrForI = %p (%d)\n", i, &i, ptrForI, ptrForI[0]);
	return i;
}

int main(void) {
	const int i = 100;

	puts("----------------------");
	function1(i);
	puts("----------------------");
	printf("\"i\" after function2: %d <=> \"original i\": %d\n", function2(i), i);
	puts("----------------------");

	return EXIT_SUCCESS;
}