/*
	Macros allows you to use short instructions with an expected clean workflow,
	however, you it's much easier to do it wrong.
*/
#include <stdio.h>
#include <stdlib.h>

/*
	taken from https://gcc.gnu.org/onlinedocs/cpp/Misnesting.html

	It's also possible to combine multiple macros. The expectation is
	that TWICE needs an argument, like CALL_WITH_ONE, but CALL_WITH_ONE
	needs this argument instead, whereas TWICE runs here without an argument.

	Very hard to understand and much hardly in use.
	Best way to handle that issue: Don't do that.
*/
#define	TWICE(x) 2*(x)
#define	CALL_WITH_ONE(x) (x(1))

/*
	We're expecting, that CALL_WITH_ONE is just an another way like ONE, but it isn't.
	Even in CALL_WITH_ONE might define a constant expression, it doesn't and it's also
	still a macro function.
*/
#define	ONE	1

int main(void) {

	//	Usually, the macro TWICE shall be called to handle any numerical value, like CALL_WITH_ONE.
	//	but in that case it won't
	printf("result: %d\n", CALL_WITH_ONE(TWICE));
	/*
		CALL_WITH_ONE(TWICE):
		CALL_WITH_ONE(2*(1))
	*/

	/*
		When you try to run it in the another way, then CALL_WITH_ONE is undefined, which causes more
		confiusion, because it SHALL be defined as expected.
	*/
	// printf("result: %d\n", TWICE(CALL_WITH_ONE));

	//	that runs fine as expected
	printf("result: %d\n", TWICE(ONE));

	return EXIT_SUCCESS;
}