/*
	Macros allows you to use short instructions with an expected clean workflow,
	however, you it's much easier to do it wrong.
*/
#include <stdio.h>
#include <stdlib.h>

/*
	A simple macro function, right? Wrong!

	A macro, even a macro function, is typeless. This allows you to work with any types,
	but without caring of undefined behaviors.

	This function has also a wrong way to handle. What happens, when for argument x or y or both
	a number to calculate, e.g. x = 4-9, y = 3 is given? Would you calculate (4-9)/3 => -5/3 => -1.666666667...?
	No. You would calculate 4-9/3 => 9/3 = 3 => 4-3 = 1 instead. Because "x" would be handled as 4-9 as two different
	numbers only. To fix that issue, x,y shall be written as: (x)/(y) =>	#define	DIVIDE(x,y) (x)/(y)

	By the way, this macro function has also another pitfalls. What happens, if y = 0? Dividing by 0 (for integers)
	a SIGFPE >>MAY<< be triggered, depending on the C version, OS, C compiler, ... => Depending on how to
	to compile your application, a signal may also differ to the expected fired signal.
	
	Usually, a SIGFPE (signal floating point exception) is going to raise.
	When you compile your application with optimization, e. g. -O2+, a SIGILL
	(illegal instruction (core dumped)) appears instead. You may handle this with a signal handling mechanism, however,
	what are you doing next?

	What happens, when x or y or both doesn't contain numbers?
*/
#define	DIVIDE(x,y) x/y

/*
	What about this macro function? We're adding x and y. For numbers, it works almost well.
	What happens, when x or y is a char / C-string instead?
	What happens, if x and y are chars instead?
	What happens, if x and y are C-strings instead? => In our case the program didn't compile.
*/
#define	ADD(x,y) x+y

#include <signal.h>
#include <string.h>

void sig_handler(int signum) {
	printf("got that signal: %d <=> %s\n", signum, strsignal(signum));
	exit(EXIT_FAILURE);
}

int main(void) {
	signal(SIGFPE, sig_handler);						//	Will this always be triggered by division with 0 for: b = 0?
	signal(SIGILL, sig_handler);						//	Huh? What's this? (by using -O2 / -O3 by compiling => maximize optimization)

	int a = 10;
	int b = 5;

	printf("%d / %d = %d\n", a, b, DIVIDE(a,b));

	//	usually, you can also use floating point numbers as well
	double c = 3.14159265358979323846;
	double d = 2.71828182845904523536;

	printf("%lf / %lf = %lf\n", c, d, DIVIDE(c,d));
	
	//	What's that?!?
	char e = 'f';
	int f = 0xFF;
	printf("%d (%c) / %d (%c) = %d (%c)\n", e, e, f, f, DIVIDE(e,f), DIVIDE(e,f));

	// char g[] = "Hello World!";						//	finally, this can't be used
	// printf("%d (%s) / %d (%c) = %d (%c)\n", g, g, f, f, DIVIDE(g,f), DIVIDE(g,f));
	
	//	We're going mad... o_O
	char h = 'A';
	int i = 0xFF;
	char j = 'A';

	printf("%d (%c) + %d (%c) = %d (%c)\n", h, h, i, i, ADD(h,i), ADD(h,i));
	printf("%d (%c) + %d (%c) = %d (%c)\n", h, h, j, j, ADD(h,j), ADD(h,j));

	/*
	char k[] = "Hello World!";
	char l[] = "How are you?";

	printf("%d (%s) + %d (%s) = %d (%s)\n", k, k, l, l, ADD(k,l), ADD(k,l));
	*/

	return EXIT_SUCCESS;
}