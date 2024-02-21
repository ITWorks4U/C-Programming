/*
	Creating a mechanism to do a "parallel" work with fork().
	It's not really a way to do parallel work, however, this allows
	you to run your own tasks, which might be independent to this program.

	Attention:
	A child process has the same access to program counter, CPU registers,
	same open files which are in use in the parent process.

	Warning:
	When you're using fork(), then YOU have to ensure to handle your
	child process(es)!
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {

	/*
		pid_t fork(void);

		Attempting to create a new process.
	
		returns:
		-1:		any error (errno is set)
		0:		child process has been successfully created
		>0:		parent process as caller
	*/
	pid_t pid = fork();

	switch(pid) {
		case -1: {
			perror("fork() returned -1");
			break;
		} case 0: {
			puts("child process here...");

			/*
				pid_t getpid(void);
				Returns the process-ID of the caller.

				pid_t getppid(void);
				Returns the parent process-ID of the caller.
			*/
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());
			break;
		} default: {
			puts("parent process here...");
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());

			/*
				At this point we didn't care about our child process,
				thus your child process might be terminated earlier than
				the main process or vice versa. This affects the state of
				your child process.
				
				child has been terminated earlier than the main process:
					child has become to a zombie process

				child has been terminated later than the main process:
					child has become to an orphan process
					=> will automatically being handled by the init process
			*/

			break;
		}
	}

	return EXIT_SUCCESS;
}