/*	demonstration of a process, which has no more parent process
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
			sleep(3);																			/*	←	let's pause the child process						*/
			printf(" Child process: PID: %3d | parent process: %3d\n", getpid(), getppid());
			break;
		} default: {
			printf(" parent process: %3d\n", getpid());
			sleep(1);																			/*	←	after one second the parent process will terminate	*/

			printf(" Parent process will now terminate.\n");
			exit(EXIT_SUCCESS);
		}
	}

	return EXIT_SUCCESS;
}
