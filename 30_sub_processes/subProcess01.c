/*	demonstration program to create a sub process	
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	/*
	 *	pid_t fork() - create a new process, which is called as a child process,
	 *	which runs as a sub process of this current process. A child process is using
	 *	the same program counter, CPU registers, same open files which are in use
	 *	in the parent process.
	 *
	 *	returns:
	 *		-1 -	if the creation of the child process failed
	 *		0  -	if a new child process was successfully created
	 *		0> -	the parent process or caller; the value contains the process ID
	 *				of newly created child process
	 */
	fork();			//	create first child process
	fork();			//	where the child process above might create a new child process, where
	fork();			//	the current parent process will also do the same...
	fork();			//	........

	printf(" Hello World!\n");		//	← How many times will "Hello World!" printed out?

	return EXIT_SUCCESS;
}
