#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

/*
	A signal handling may also be used for
	exception handling, however, without
	the exit function, you'll stuck
	forever.
*/

void signal_callback_function(int signum);

void signal_callback_function(int signum) {
	printf("I got that signal: %d <=> %s\n", signum, strsignal(signum));
	exit(signum);
}

int divide(int a, int b) {																						//	may cause an error
	return a / b;																								//	if b is zero
}

int divide_primitive_way(int a, int b) {																		//	alternatively we check, if
	if (b != 0) {																								//	b is unequal to zero to handle
		return a / b;																							//	it correctly, however, this is
	}																											//	a primitive way and doesn't help
																												//	use for handle an error
	return -1;
}

int main(void) {
	signal(SIGFPE, signal_callback_function);																	//	for a floating point exception

	int a = 100;

	for(int i = 10; i >= -10; i-= 2) {
		printf("%d / %d = %d\n", a, i, divide(a, i));
	}

	puts("You'll never see this text on runtime.");

	/*
		Since you're not using a deeper look
		to other signal handling mechanism, e. g. jumping,
		there's no way to continue your loop after division zero
		signal has been detected.
	*/

	return EXIT_SUCCESS;
}