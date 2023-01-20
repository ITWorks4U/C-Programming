#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

/*
	signal handling allows you to react / interact, when
	a signal at any time on any event may appear. Some signals can
	be handled, however, not every signal is able to
	handle. It depends on your system, the compiler, etc.

	You also may block an incoming signal, whereas not every
	signal is able to block. It also depends on your system,
	compiler, etc.

	A signal handling can also be used for "exception handling".
*/

void signal_callback_function(int signum);																//	any function of type void
																										//	with one argument of type int

void signal_callback_function(int signum) {
	printf("I got that signal: %d <=> %s\n", signum, strsignal(signum));								//	strsignal(int) (from string.h)
																										//	allows you to print the current
																										//	signal
	exit(signum);																						//	by default, an application exit
																										//	is recommended, otherwise
																										//	you have have to wait for an
																										//	infinite time, depending on
																										//	your previous action :o)
}

int main(void) {
	/*	registering a possible incoming signal to handle	*/
	signal(SIGINT, signal_callback_function);
	signal(SIGTERM, signal_callback_function);
	signal(SIGKILL, signal_callback_function);

	char BUFFER[200];
	memset(BUFFER, '\0', strlen(BUFFER));
	printf("Enter something: ");
	fgets(BUFFER, 200, stdin);

	printf("%s\n", BUFFER);

	/*
		By pressing Ctrl + C on fgets(), similar to
		an another functions with a waiting procedure,
		an interrupt appears. Since we're handling
		a signal, we're still in our application.

		For fgets() just press "Enter" to continue
		or terminate your application by another way.

		Depending on to the situation when, where and
		why a signal appears, an undefined behavior
		may occur.
	*/

	return EXIT_SUCCESS;
}