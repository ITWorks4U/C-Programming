/*
 *	Using a keyword, which comes with C++, to initialize a variable.
 *	In C you may use a C++ keyword without a problem, but you'll get
 *	in struggle to use a C++ compiler.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	char class = 'C';					//	class is a keyword in C++
	printf(" class contains: %c\n", class);

	return EXIT_SUCCESS;
}
