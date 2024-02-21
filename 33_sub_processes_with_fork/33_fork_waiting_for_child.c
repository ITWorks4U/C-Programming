/*
	Creating a mechanism to do a "parallel" work with fork().
	It's not really a way to do parallel work, however, this allows
	you to run your own tasks, which might be independent to this program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/*	required for waitpid()	*/
#include <sys/wait.h>

int main(void) {

	pid_t pid = fork();

	switch(pid) {
		case -1: {
			perror("fork() returned -1");
			break;
		} case 0: {
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());

			puts("child: \"I'm going to sleep!\"");
			for(int i = 0; i < 5; i++) {
				puts("child: \"zzz... zzz... zzz...\"");
				sleep(1);
			}

			puts("child: \"I'm back!\"");

			if (getppid() == 1) {
				puts("child: \"Mommy...?\"");
			}

			break;
		} default: {
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());
			puts("parent: \"Time to go.\"");
			puts("parent: \"Wait...? Did I forgot something?\"");

			/*
				pid_t waitpid(pid_t __pid, int *__stat_loc, int __options);

				Attempt to wait for the child.

				returns:
					-1:		any error (errno is set)
					>= 0:	waiting attempt was sucessfully

				Since your main process is forced to wait for the child process,
				you can handle your child(s) much better. It doesn't now matter if
				your child process has been terminated earlier or later that the main process did.
				However, it depends on HOW YOU handle your child(s)!

				arguments:
				__pid:
					process id, where:

				< -1 = waiting for any child process, whose process group ID is equal to the absolute value of pid
				-1 = just waiting for any child process
				0 = waiting for any child process, whose process group ID is equal to the calling process
				>0 = waiting for the child process, which has been successfully created by THIS parent process

				__stat_loc:
					pointer to the location, where the status information for the terminating process wants to be stored,
					NULL for: "We don't care about these informations."

				__options:
					specifies optional actions for waitpid; the flags can be combined with bit-OR

				WNOHANG := returns immediately if no child exists
				WUNTRACED := also return, if a child process has been stopped in any way;
				status for traced children, which have been stopped, is provided, even if this option is not set
				WCONTINUED := also return, if a stopped child has been resumed by delivery of SIGCONT
			*/

			/*
				Attention: Don't use getpid() instead of pid.
				Otherwise waitpid always returns -1 and your parent process
				do not longer care about any child process(es)!
			*/
			switch (waitpid(pid, NULL, 0)) {
				case -1: {
					perror("parent: \"Hm, I think it wasn't important...\"");
					break;
				} default: {
					puts("parent: \"Ah, there you're! :)\"");
					break;
				}
			}

			break;
		}
	}

	return EXIT_SUCCESS;
}