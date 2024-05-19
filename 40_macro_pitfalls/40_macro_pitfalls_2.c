/*
	Macros allows you to use short instructions with an expected clean workflow,
	however, you it's much easier to do it wrong.
*/
#include <stdio.h>
#include <stdlib.h>

/*
	In a macro function (still single line) a condition check MAY help against
	division by zero for integer values, however, the DIVIDE macro can't be
	used in a printf() function, because no else is given. So, you're expecting an else statement, right?
	
	Even an else is given, DIVIDE (and also SAVE_DIVIDE) still can't be used in a printf() function.
	=> "expected expression before 'if'"
	By the way, there's no way to get the result for x/y...

	...SAVE_DIVIDE has a third argument "res", which stores this result, but it's not better that DIVIDE

	By the way, both macro functions comes with an if statement, so what happens, when outside of the
	macro function calls an else block exists?

	In that case this else block will be the else block from the if statement in the certain macro function,
	which results an undefined behavior for you.
*/
#define	DIVIDE(x,y) if ((y) != 0) (x)/(y)
#define	SAVE_DIVIDE(res,x,y) if ((y) != 0) res = (x)/(y)

/*
	What happens, when C-strings are in use instead? Will that work similar to (SAVE_)DIVIDE above? Maybe.
*/
#include <string.h>
#define	TEST	"abc"
#define	STUFF(x) if ((strncmp((x), (TEST), (strlen((x))))) == 0) puts("x is \"abc\"")

/*
	a simple mistake: strncmp expects 3 arguments, but 2 are given => You'll get an expected error
	on build time, however, you may get the information, that STUFF_WRONG(x) itself might be wrong.

	By the way, this error might not appear, when this macro function is never in use.
*/
#define	STUFF_WRONG(x) if ((strncmp((x), (TEST))) == 0) puts("x is \"abc\"")

int main(void) {
	int a = 10;
	int b = 0;

	//	since DIVIDE contains an if statement, this won't longer work
	// printf("%d / %d = %d\n", a, b, DIVIDE(a,b));

	// ret is undefined (on Linux it may be set to 0 by default)
	int ret;
	SAVE_DIVIDE(ret,a,b);
	printf("%d / %d = %d\n", a, b, ret);

	//	What happens here?
	/*
		Are you expecting, that the else statement refers to "if (b != 0)"? Thats wrong.
		Since in (SAVE_)DIVIDE an if statement exists, that else statment referns to
		the if statement in the macro function instead. To fix that issue, use curly brackets.

		=> [...]warning: suggest explicit braces to avoid ambiguous ‘else’
	*/
	if (b != 0)
		DIVIDE(a,b);
	else
		puts("b is zero...");


	//	And what will happen here?
	STUFF("test");
	else {
		puts("oops o.O");
	}

	//	in our case: since this function is never called, no error on build time appears
	// STUFF_WRONG("epic fail");

	return EXIT_SUCCESS;
}