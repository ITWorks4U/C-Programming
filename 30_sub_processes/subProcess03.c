/*	demonstration of a zombie process, which is terminated earlier than the parent process
*
*
*	@author				ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

int main() {
	pid_t pid = fork();

	switch (pid) {
		case -1: {
			perror(" Error with fork()");
			break;
		} case 0: {
			printf(" Child process: PID: %3d | parent process: %3d\n", getpid(), getppid());
			sleep(1);																			/*	←	let's pause the child process			*/
			printf(" Child process will now terminate.\n");
			exit(EXIT_SUCCESS);
		} default: {
			printf(" parent process: %3d\n", getpid());
			sleep(3);																			/*	←	let's pause the parent proces			*/

			puts(" Canceling infinite loop with \"STRG + C\"");
			while(1);																			/*	infinite loop; terminating with STRG + C	*/
		}
	}

	return EXIT_SUCCESS;
}
