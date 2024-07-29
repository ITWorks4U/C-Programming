#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"

/*
	Usually, your application is able to build in C++, but not in C.
	Even the function prototypes and their declarations are in C-style,
	it depends on the source file, where these functions are stored.

	If a C++ - file is in use, the functions will have a different
	expression for the linker. And that's the point, where your application
	can't be build in C.
*/

int main(void) {
	int a = 10;
	int b = 20;

	printf("running under C...\n\n");

	printf("%d + %d = %d\n", a, b, addition(a,b));
	printf("%d - %d = %d\n", a, b, subtraction(a,b));
	printf("%d * %d = %d\n", a, b, multiply(a,b));
	printf("%d / %d = %d\n", a, b, divide(a,b));

	struct Data d;
	memset(d.content, '\0', BUFFER);
	memcpy(d.content, STR_CONTENT, strlen(STR_CONTENT));

	printf("%s\n", d.content);

	return EXIT_SUCCESS;
}