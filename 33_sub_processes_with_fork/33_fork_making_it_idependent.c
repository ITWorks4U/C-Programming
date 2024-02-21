/*
	Creating a mechanism to do a "parallel" work with fork().
	It's not really a way to do parallel work, however, this allows
	you to run your own tasks, which might be independent to this program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
	using arguments for the main application, which
	are planned to use for the child process only
*/
int main(int argc, char **argv) {

	pid_t pid = fork();

	switch(pid) {
		case -1: {
			perror("fork() returned -1");
			break;
		} case 0: {
			puts("child process here...");
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());
			puts("I'm going to be independent! :)");

			int ctr = 0;
			char **args = calloc(argc, argc * sizeof(char *));

			while(ctr < (argc - 1)) {
				args[ctr] = argv[ctr + 1];
				ctr++;
			}

			/*
				int exec*(...)
				Allows you to make your sub process to an own independent process.

				from "man exec, there're different exec*(...) functions:

				l - execl(), execlp(), execle()
					The const char *arg and subsequent ellipses can be thought of as arg0, arg1, ..., argn.
					Together they describe a list of one or more pointers to null-terminated strings that
					represent the argument list available to the executed program.
					The first argument, by convention, should point to the filename associated with the file being executed.
					The list of arguments must be terminated by a null pointer, and, since these are variadic functions, this pointer must be cast (char *) NULL.

					By contrast with the 'l' functions, the 'v' functions (below) specify the command-line arguments of the executed program as a vector.

				v - execv(), execvp(), execvpe()
					The char *const argv[] argument is an array of pointers to null-terminated strings that represent the argument
					list available to the new program. The first argument, by  convention, should point to the filename associated with
					the file being executed. The array of pointers must be terminated by a null pointer.

				e - execle(), execvpe()
					The environment of the caller is specified via the argument envp. The envp argument is an array of pointers
					to null-terminated strings and must be terminated by a null pointer.

					All other exec() functions (which do not include 'e' in the suffix) take the environment for the
					new process image from the external variable environ in the calling process.

				p - execlp(), execvp(), execvpe()
					These functions duplicate the actions of the shell in searching for an executable file if the specified filename
					does not contain a slash (/) character. The file is sought in the colon-separated list of directory pathnames specified in the
					PATH environment variable. If this variable isn't defined, the path list defaults to a list that includes the directories
					returned by confstr(_CS_PATH) (which typically returns the value "/bin:/usr/bin") and possibly also the current working directory

					If the specified filename includes a slash character, then PATH is ignored, and the file at the specified pathname is executed.

					In addition, certain errors are treated specially.

					If  permission is denied for a file (the attempted execve(2) failed with the error EACCES), these functions will continue searching
					the rest of the search path. If no other file is found, however, they will return with errno set to EACCES.

					If the header of a file isn't recognized (the attempted execve(2) failed with the error ENOEXEC), these functions will execute the
					shell (/bin/sh) with the path of the file as its first argument. (If this attempt fails, no further searching is done.)

					All other exec() functions (which do not include 'p' in the suffix) take as their first argument a (relative or absolute) pathname
					that identifies the program to be executed.


				returns:
				-1, on any error (errno is set)
				0 on success => You're unable to see this result, because at this
				point your sub process is no longer a part of your current application.
			*/
			execvp(argv[1], args);

			/*
				Attention:	You're creating dynamic allocated memory on the heap,
							which are no longer accessable and can't be freed()!

							You could also use a static string, located on the stack,
							however, your exec*() function might not work.
							Even, if 0 has returned.
			*/

			puts("Are you still able to see this text here?");

			break;
		} default: {
			puts("parent process here...");
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());
			sleep(3);
			puts("parent process ends now");
			puts("Wait...? Where's my child?");

			/*
				However, your main application might still be able to wait for
				your child process. In that case a waitpid() is no longer required.
			*/

			switch (waitpid(pid, NULL, 0)) {
				case -1: {
					perror("unable to wait for child...");
					break;
				} default: {
					puts("Ah, there you're! :)");
					break;
				}
			}

			break;
		}
	}

	return EXIT_SUCCESS;
}