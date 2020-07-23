/*	waiting for child process
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main() {

	pid_t pid = fork();
	switch (pid) {
		case -1: {													/*	an error occureed									*/
			fprintf(stderr, " Error with \"fork()\": %s\n", strerror(errno));
			break;
		} case 0: {													/*	here we are in our child process					*/
			puts(" --- child process ---	");
			printf(" Child process: PID: %3d | parent process: %3d\n", getpid(), getppid());

			int i;
			for (i = 0; i < 10; i++) {
				puts(" Child process is sleeping for a one second.");
				sleep(1);
			}

			printf(" Child process: PID: %3d | parent process: %3d\n", getpid(), getppid());
			break;
		} default: {												/*	here we are in our parent process					*/
			puts(" --- parent process ---	");
			puts(" Since we're running a new process we're also here...");

			int i;
			for (i = 0; i < 5; i++) {
				puts(" waiting for our created child process...");
				sleep(1);
			}

			/*
			 *	pid_t waitpid(pid_t pid, int *status, int options); waiting for the child process and receiving returning value
			 *
			 *	pid		:=	the process ID, where:
			 *		< -1	:=	waiting for any child process, whose process group ID is equal to the absolute value of pid
			 *		-1		:=	waiting for any child process
			 *		0		:=	waiting for any child process, whose process group ID is equal to that of the calling process
			 *		> 0		:=	waiting for the child process, whose process ID is equal to the value of pid
			 *
			 *	status	:=	is a pointer to the location, where status information for the terminating process is to be stored
			 *
			 *	options	:=	specifies optional actions for waitpid function; a set of flags are can be combined with
			 *				a bitwise OR operator
			 *		WNOHANG		:=	return immediately if no child has existed
			 *		WUNTRACED	:=	also return, if a child process has stopped. Status for traced children which have stopped
			 *						is provided even if this option is not specified
			 *		WCONTINUED	:=	also return, if a stopped child has been resumed by delivery of SIGCONT
			*/
			switch (waitpid(pid, NULL, 0)) {
				case -1:
					fprintf(stderr, " Error with waitpid(): %s\n", strerror(errno));
					return EXIT_FAILURE;
				default:
					printf(" Child procss terminated with exit value %d\n", WEXITSTATUS(NULL));
			}			
		}			
	}

	return EXIT_SUCCESS;
}
