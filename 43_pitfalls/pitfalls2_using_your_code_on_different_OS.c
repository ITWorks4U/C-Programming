/*	Same code for different operating systems ("OS").
*
*	Don't think, that your code works identical on different operating systems.
*
*	Depending on which operating system you're working on, you need
*	a preprocessing argument to mark a code as executeable only, if
*	the correct operating system is in use.
*/

#include <stdio.h>
#include <stdlib.h>

/*	Depending on which C / C++ version is in use, the preprocessor commands
*	might be different as well, e. g.: __WIN32__, _WIN32, __MSDOS__, ...
*
*	Usually, _WIN32 can be used for Windows 32 bit and also for 64 bit, whereas
*	_WIN64 is only for Windows 64 bit.
*/

#ifdef _WIN32
/*	this library below is only available for Windows	*/
#include <windows.h>
#elif __unix__
/*	this library below is only available for UNIX/Linux
*
*	by the way, you can also use #ifdef linux, because __unix__ is (very) old,
*	but not every Linux system can handle "linux"
*/
#include <unistd.h>
#else
/*	In case of no match above has been detected, a common error on building your application results instead.	*/
#error "No valid operating system has been found. Terminating..."
#endif

int main(void) {
	/*	Simple program:	loop 10 times and sleep for one second, however, the sleep function (which is deprecated, too),
	*	does not work on all operating systems.
	*/
	for(int i = 0; i < 10; i++) {
		printf("i: %d\n", i);

		/*	Determine, which OS is in use here to call the correct function.
		*	On Windows Sleep(int millis) is in use.
		*	Linux uses sleep(int seconds) instead.
		*
		*	special case (Linux):
		*	When you try to pause your application for some milliseconds, you can use usleep():
		*	int usleep(int microseconds);
		*
		*	However, this function, like many other C functions, is deprecated.
		*	Use nanosleep (from time.h) instead.
		*/

		#ifdef _WIN32
		Sleep(1000);
		#elif __unix__
		sleep(1);
		#endif
	}

	return EXIT_FAILURE;
}