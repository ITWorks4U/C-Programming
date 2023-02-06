#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

/*
	By using a signal you MAY have luck
	and can handle an exception here, however,
	this won't work here.

	In that case the possible signal never triggers,
	such that the signal_handler function is never
	called.
	
	The pointer will be NULL and you're trying to
	close a NULL stream, thus you'll receive a
	segmentation fault here.
*/

void signal_handler(int signum) {
	fprintf(stderr, "%d <=> %s\n", signum, strerror(signum));
	exit(signum);
}

int main(void) {
	/*
		In signum-generic.h SIGIO is defined as SIGPOLL,
		which is defined with the constant expression
		of 23.
	*/
	signal(SIGIO, signal_handler);																				//	planned to handle an I/O signal

	FILE *source = fopen("not found or not access to a file or else...", "r");
	
	//	Normal workflow here...?
	fclose(source);

	return EXIT_SUCCESS;
}