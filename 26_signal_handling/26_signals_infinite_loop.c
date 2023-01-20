#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <stdbool.h>

void signal_callback_function(int signum);

void signal_callback_function(int signum) {
	printf("I got that signal: %d <=> %s\n", signum, strsignal(signum));
	exit(signum);																						//	strictly required,
																										//	otherwise you waits
																										//	paitently for eternity :P
}

int main(void) {
	signal(SIGINT, signal_callback_function);
	signal(SIGTERM, signal_callback_function);
	signal(SIGKILL, signal_callback_function);

	while(true) {																						//	best practise for signal handling
		puts("Never ending story...?");
	}

	return EXIT_SUCCESS;
}