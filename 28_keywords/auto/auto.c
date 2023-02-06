
#include <stdio.h>
#include <stdlib.h>

/*
	In C the keyword 'auto' has become obsolete
	and it's hardly used.
	
	It's still available for the previous programming
	language 'B' and it's useful for backward compability.
	
	Every variable, data type etc. with the keyword 'auto'
	specifies a storage duration. When you create an auto
	variable it has an "automatic storage duration".
	
	It's the same as "local variables", where in C all
	variables in functions are local by default.

	Attention: Unlike in C++ in C auto doesn't support
	an "anonymous" variable, like auto value = 123 or else,
	because this won't work. Your compiler gives you a
	warning followed by a suggestion, that this value is
	>>always<< interpreted as an integer.

	May also cause an undefined behavior!
*/

int main(void) {
	int a = 100;
	auto int b = 42;
	// auto c = 0;																				//	gives you a warning
	// auto d = "Hello World!";																	//	*cough*

	printf("a = %d, b = %d\n", a, b);

	return EXIT_SUCCESS;
}