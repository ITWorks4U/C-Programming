/**
*	How to use signals in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

#define ARG_ONE		"ALLOW_CTRL_C"
#define	ARG_TWO		"DENY_CTRL_C"
void signalFunction(int signal);										/*	function prototype	*/

void signalFunction(int signal) {
	printf("\n **** I received signal #%d! It was identified as: %s ***\n", signal, strsignal(signal));
	exit(signal);
}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf(" Usage: %s argument, where argument is %s or %s\n", argv[0], ARG_ONE, ARG_TWO);
		return EXIT_FAILURE;
	}

	if (strncmp(argv[1], ARG_ONE, strlen(ARG_ONE)) == 0) {				//	allow to use CTRL+C (^C)
		signal(SIGINT, signalFunction);									//	notify CTRL+C
//		signal(SIGKILL, signalFunction);								//	may be ignored by kill -9 PID
		signal(SIGTERM, signalFunction);								//	notify, whenever the program was termianted with "kill PID"

	} else if (strncmp(argv[1], ARG_TWO, strlen(ARG_TWO)) == 0) {		/*	You won't have a chance to quit the program with CTRL+C		*/
		signal(SIGINT, SIG_IGN);										//	ignores CTRL+C
//		signal(SIGKILL, SIG_IGN);										//	BE CAREFUL!! YOU COULD DENY TO KILL THE PROCESS! Depending on C compiler and machine
		puts(" Now you can't terminate the program with \"CTRL + C\" (:");
	}

	int i;
	while (1) {
		printf(" Try to terminate the program with \"CTRL + C\"...");

		for (i = 0; i < 60; i++) {
			printf("\r");												//	"deletes" the output above from terminal
		}
	}

	return EXIT_SUCCESS;
}
