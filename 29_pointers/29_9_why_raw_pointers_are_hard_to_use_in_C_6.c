#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

/*	By using pointers in combination with an "exception handling",
	there's no guarantee, that an allocated memory is going to
	free in case on an exception.
*/

struct Math {
	int a;
	int b;
	int result;
};

/*	handling a set of signals ("exceptions")	*/
void signalHandler(int sigNbr) {
	printf("Received signal %d (%s)\n", sigNbr, strsignal(sigNbr));
	exit(sigNbr);

	//	What happens, when exit(sigNbr) isn't given here?
}

/*	divive a/b => b may be 0... Then what?	*/
int divide(int a, int b) {
	return a/b;
}

int main(void) {
	signal(SIGINT, signalHandler);
	signal(SIGTERM, signalHandler);

	/*	handling our "exception" for division by 0	*/
	signal(SIGFPE, signalHandler);

	for(int i = 10; i >= -10; i -= 2) {
		struct Math *m = (struct Math *) calloc(1, sizeof(struct Math));
		m->a = 10;

		m->b = i;
		m->result = divide(m->a, m->b);
		printf("%d / %d = %d\n", m->a, m->b, m->result);

		/*	In case of division by zero a SIGFPE (floating point exception) is going to raise,
			which will be caught by our signal handler function, however, since the application
			is going to terminate this allocated structure hasn't been released. => Memory leak.
		*/
		free(m);
	}

	return EXIT_SUCCESS;
}