/**
*	Different ways to terminate a program in C/C++.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>		/*	void exit(int status), void _exit(int status) (for Windows OS), int atexit(void (*function) (void)), void abort(void)	*/
#include <unistd.h>		/*	required for UNIX/Linux OS for given function: void _exit(int status)													*/
#include <assert.h>		/*	required to use function:	void assert(int expression)																	*/
#include "exit.h"		/*	<-- only in use to define the function "testFunction()"; prints: "This function has been called..."						*/

int main() {
	/*
	*	Terminating program immediately by using an integer value. Any open file descriptors
	*	belonging to the process are closed and any children of the process are inherited
	*	by process 1, init, and the process parent is going to send a SIGCHILD signal.
	*	Finally, calls _exit() function.
	*/
	puts(" Terminating program by exit(int) function...");
	exit(EXIT_SUCCESS);																					/*	exit(0) may also work						*/
	printf(" Print line number: %d in function %s to the console instead.\n", __LINE__, __func__);		/*	Should not being printed to the console		*/
	
	/*
	*	Like exit() function this will also terminating the program immediately by using a
	*	given integer value. Unlike exit() function this won't close any open file descriptor,
	*	and doesn't flush all buffers and so on. If you are using a Windows OS, then include
	*	the library "stdlib.h". By using a UNIX/Linux OS you need the library "unistd.h".
	*/
	puts(" Terminating program by _exit(int) function...");
	_exit(EXIT_SUCCESS);
	printf(" Print line number: %d in function %s to the console instead.\n", __LINE__, __func__);		/*	let's see if this will be printed anyway...	*/

	/*
	*	Installing a function handler. Call any function (up to 32 functions) and then terminate
	*	the program with exit().
	*/
	puts(" Terminating program by atexit(*function*) function?");
	atexit(testFunction);
	printf(" Print line number: %d in function %s to the console instead.\n", __LINE__, __func__);		/*	You are able to see this output!			*/
	exit(0);																							/*	Required to terminate your program!!		*/

	/*
	*	Terminating the program abnormal and raise the SIGABRT signal. All functions,
	*	which are registered by atexit() function aren't called.
	*	Possible actions may occur: buffer is not flushed, stream is not closed etc.
	*/
	puts(" Terminating program by abort() function...");
	abort();
	printf(" Print line number: %d in function %s to the console instead.\n", __LINE__, __func__);		/*	impossible to see							*/	

	/*
	*	Test an expression of being true. If the given expression was false, then the program
	*	is going to terminate.
	*
	*	IMPORTANT: You need to include the library "assert.h" to use the function
	*	void assert(int expression).
	*/
	int value = 42;
	puts(" Terminating program by using a wrong assertion...");
	assert(value > 100);
	printf(" Print line number: %d in function %s to the console instead.\n", __LINE__, __func__);		/*	unable to see the output on terminal		*/		
	
	return EXIT_SUCCESS;																				/*	usually the most used termination command	*/
}
