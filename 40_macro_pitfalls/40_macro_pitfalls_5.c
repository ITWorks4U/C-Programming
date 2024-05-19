/*
	Macros allows you to use short instructions with an expected clean workflow,
	however, you it's much easier to do it wrong.
*/
#include <stdio.h>
#include <stdlib.h>

/*
	Finally, in C it's also possible to assign a function into a variable, depending on the
	C version, OS, C compiler, ...

	FUNCTION_CALL is "just" a short form for "print the defined WORD to the console by using puts()".
	In that case after the puts() function no semicolon is given, thus after FUNCTION_CALL the semicolon
	is required, otherwise the application won't be built.
*/
#define	WORD	"Hello there!"
#define	FUNCTION_CALL	puts(WORD)

int main(void) {
	FUNCTION_CALL;

	/*	you can also do this:	*/
	char hello_word[] = WORD;
	printf("hello_word = %s\n", hello_word);

	/*	MAYBE you could also do this:	*/
	char function_word[] = FUNCTION_CALL;

	/*
		On Linux mint 21.1 Cinnamon 64 bit this error was displayed:

		40_macro_pitfalls_5.c: In function ‘main’:
		40_macro_pitfalls_5.c:17:25: error: invalid initializer
		17 | #define FUNCTION_CALL   puts(WORD)
		   |                         ^~~~
		40_macro_pitfalls_5.c:24:32: note: in expansion of macro ‘FUNCTION_CALL’
		24 |         char function_word[] = FUNCTION_CALL;
		   |                                ^~~~~~~~~~~~~
		40_macro_pitfalls_5.c:24:14: warning: unused variable ‘function_word’ [-Wunused-variable]
		24 |         char function_word[] = FUNCTION_CALL;
		   |              ^~~~~~~~~~~~~

		In other words: an assignment of a function to a variable is not allowed, but it's not impossible
	*/

	return EXIT_SUCCESS;
}