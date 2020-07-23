/*	demonstration to run a new process with some parameters
*
*	@author				ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <assert.h>

int main(int argc, char **argv) {
	if (argc < 2) {													/*	expected number of paramters are at least 2 or more	*/
		fprintf(stderr, " usage: %s program_to_run program_arguments\n", argv[0]);
		return EXIT_FAILURE;
	} else if (strcmp(argv[0], argv[1]) == 0) {						/*	we don't accept to run our program with our program	*/
		fprintf(stderr, " \"%s\" is not allowed as parameter\n", argv[1]);
		return EXIT_FAILURE;
	}

	pid_t pid = fork();
	switch (pid) {
		case -1: {													/*	an error occurred									*/
			fprintf(stderr, " Error with \"fork()\": %s\n", strerror(errno));
			break;
		} case 0: {													/*	here we are in our child process					*/
			puts(" --- child process ---	");
			printf(" Child process: PID: %3d | parent process: %3d\n", getpid(), getppid());
			int ctr = 0;
			char **arguments = calloc(argc, argc * sizeof(char *));
			assert(arguments != NULL);

			while (ctr < (argc - 1)) {								/*	let's copy all given parameters to arguments		*/
				arguments[ctr] = argv[ctr + 1];
				ctr++;
			}

			/*
			 *	int exec(*)(const char *path, const char *arg, ...); allows you to run a new main process,
			 *	which is no more a child process of the current parent process. The exec(*) functions are quite
			 *	different, where `(*)` offers:
			 *
			 *	e := an enviroment list of type of a vector is expected (exece)
			 *	l := command line arguments are in form of a list (execl)
			 *	v := command line arguments are in form of a vector (execv)
			 *	p := unlinke a path name, a file name is expected (execp)
			 *
			 *	a combination looks like:
			 *	execlp(), execle(), execvp(), execve()
			 *
			 *	returns:
 			 *	-1, if an error occurred, otherwise there is NO returning sequence to the current parent process,
			 *	which means the "new" programming is running now.
			*/
			execvp(argv[1], arguments);
			printf(" Are you able to see this output?");			/*	← You won't see this output.							*/
			break;

		} default: {												/*	here we are in our parent process					*/
			puts(" --- parent process ---	");
			puts(" Nothing to do... ");

			if ((pid != waitpid(pid, NULL, 0))) {
				fprintf(stderr, " Error with waitpid(): %s\n", strerror(errno));
				return EXIT_FAILURE;				
			}
		}			
	}

	return EXIT_SUCCESS;
}
