/*
	in C/C++ there're
	tree different ways
	to create and use
	constants, whereas
	macros are often
	used for a
	constant expression
*/

#include <stdio.h>
#include <stdlib.h>

/*
	1st way:	using const keyword

	fun fact:	in C a constant expression
				can also have no value
				in C++: it's illegal

	Basicly, you shouldn't use "const" to expect a constant expression.
	For more informations take a look to "32_constant-part2".
*/
const int	expression_const = 123;

/*
	2nd way:	using macro
*/
#define		expression_macro	123

/*
	3rd way:	using anonymous enumeration
				rareley used
*/

enum {
	expression_enum = 123
};

int main() {
	printf(
		"%d, %d, %d\n",
		expression_const, expression_macro, expression_enum
	);

	return EXIT_SUCCESS;
}