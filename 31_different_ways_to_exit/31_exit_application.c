/*
	What happens, when your application code reaches EXIT_SUCCESS / EXIT_FAILURE?

	Have you ever thought about how the application is going to
	terminate after certain conditions?	There're many ways to do this,
	however, the results differs!

	Explanation:
	By reaching return 0 / return 1 / return EXIT_SUCCESS / return EXIT_FAILURE / return .... in the main
	your application returns to the shell, where you've launched the application or to the
	operating system, where you've (double) clicked your application. - The classic way.

	However, the main automatically calls the exit() function, which calls _exit() to
	clearly terminate your application.
	
	So you can terminate your application by calling exit() or _exit(), ..., but the results differs.

	Since you're reaching an exit way too early, almost every other code behind is not going to execute.
*/

#include <stdio.h>
#include <stdlib.h>

/*	only for UNIX/Linux for _exit(int __status)
	in Windows _exit() is defined in stdlib.h
*/
#if __unix__
#include <unistd.h>
#endif

/*	for assert() function (C89) / assert() macro (C99 and newer)	*/
#include <assert.h>

/*	a simple struct with almost every data types inside	*/
struct Test {
	short s;
	int i;
	long l;
	long long ll;
	
	unsigned short us;
	unsigned int ui;
	unsigned long ul;
	unsigned long long ull;

	float f;
	double d;
	char c;
	char c_string[10];
	char *c_ptr;
};

/*	internal declaration for struct Test	*/
static struct Test *t = NULL;

/// @brief Releases the allocated memory. But NOT on every situation!
void cleanUpFunction(void) {
	puts("clean up....");
	free(t);
	t = NULL;
}

int main(void) {
	/*	normal instructions here...	*/
	puts("This text can be seen.");
	t = (struct Test *) malloc(sizeof(struct Test));

	/*
		-----------------
		Since you've decided to terminate your application earlier,
		every other code won't be executed by default.
		-----------------
	*/

	/*	Registering a "clean up" to ensure to release your allocated memory,
		but it works only with exit() and return statement!
	*/
	atexit(cleanUpFunction);

	/*	Different ways to terminate your application:	*/

	/*
		void exit(int exit_code); (until C11)
		_Noreturn void exit(int exit_code); (C11-C23)
		[[noreturn]] void exit( int exit_code ); (C23+)

		Mark to terminate your application. Automatically called by return
		statement in your main. If you have registered and clean up functions
		by using atexit(), then these functions are called before the application
		is really terminated by _exit().
	*/
	exit(EXIT_SUCCESS);
	
	/*
		void _exit(int __status);

		The real exit for your application. This function DOES NOT clean up
		any resources! Make sure you've cleaned up it before.

		In UNIX/Linux the library <unistd.h> is required.
		For Windows this function is defined in <stdlib.h> instead.
	*/
	_exit(EXIT_SUCCESS);

	/*
		void abort(void);

		Terminate your application abnormally and create a >core dumped< expression on the terminal.
		The abort() function first unblocks the SIGABRT signal, and then raises that signal
		for the calling process. Does NOT clean up any resources.

		If the SIGABRT signal is ignored, or caught by a handler that returns, the abort() function will
		still terminate the process. It does this by restoring the default disposition
		for SIGABRT and then raising the signal for a second time.

		The return value for abort() is 134.
	*/
	abort();
	
	int test = 0;

	/*
		up tp C-version C89:	void assert(int expression);
		C99 and newer:			void assert(scalar expression);

		Asserting, that a condition is true. If so, then the application process continues.
		If the condition is false, then an assert error is raised. This automatically calls
		the abort() function and has the same behavior like abort() itself.

		In case of an assertion error, this function also returns 134.

		If the macro NDEBUG is defined at the moment <assert.h> was last included, then assert() generates no code,
		and hence does nothing at all. It is not recommended  to  define NDEBUG if using assert()
		to detect error conditions since the software may behave non-deterministically.
	*/
	assert(test != 0);

	/*
		int at_quick_exit(void (*__func)(void)); (C11+)

		Works like atexit() function to register at least 32 functions
		to do a "clean up job" before the application is going to terminate.

		Works in combination with quick_exit();

		The registered functions will not be called on normal program termination, like return / exit().
		If a function need to be called in that case, atexit must be used. 
	*/
	at_quick_exit(cleanUpFunction);

	/*
		_Noreturn void quick_exit( int exit_code ); (C11 - C23)
		[[noreturn]] void quick_exit( int exit_code ); (C23+)

		Calls all functions, which are registered by at_quick_exit() before.
		Finally, the process is going to terminate by given status.

		Functions passed to atexit() or signal handlers passed to signal are not called.
	*/
	quick_exit(EXIT_SUCCESS);

	/*
		void _Exit(int __status);

		Works like _exit() with the same behavior. This function is defined in <stdlib.h>.
	*/
	_Exit(EXIT_FAILURE);
	
	puts("What about this text here?");

	/*	basic way to terminate your application	*/
	return EXIT_SUCCESS;
}