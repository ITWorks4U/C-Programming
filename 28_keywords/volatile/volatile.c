#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>

/*
	The volatile keyword is a qualifier that is applied to
	a variable when it's declared. It tells the compiler
	that the value of the variable may change at any time.

	Without any action being taken by the code the compiler
	finds nearby. The implications of this are quite serious.

	However, a variable should be declared volatile whenever it's
	value could change unexpectedly. In practice, only three
	types of variables could change:

	-	memory mapped peripheral registers
	-	global variables modified by an interrupt service routine (demonstraded here)
	-	global variables accessed by multiple tasks within a
		multi-threaded application.

	To receive the signal, compile your application without optimizations,
	in that case with -O2 flag.

	To see the difference, try to compile your application without
	the volatile keyword, but WITH -O2 flag. In that case you'll
	receive your signal, however, your infinite loop is still
	available and you'll never see the end of your application,
	unless you'll kill your current process.
*/

volatile static bool signal_flag = false;

void signal_handler(int signum) {
	printf("received that signal: %s (%d)\n", strsignal(signum), signum);

	if (signum == SIGINT) {
		signal_flag = true;
	}
}

int main(void) {
	signal(SIGINT, signal_handler);
	puts("waiting patiently...");

	while(!signal_flag) {
		//	nothing to do here
	}

	puts("Signal received. End of application.");
	return EXIT_SUCCESS;
}