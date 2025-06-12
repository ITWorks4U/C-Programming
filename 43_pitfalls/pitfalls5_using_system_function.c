/*	The function int system(const char *command); allows you to run a shell command,
*	depending on which OS you're working on. However, this function does not care
*	about the size limitation of your command and it can't determine which OS is
*	now in use here.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("Take a look into your current directory structure...");

	/*	What happens, if you try to use a command from a foreign OS?
	*	Mostly, this command does not work and you'll get an error
	*	on runtime, however, this command can also modify settings on the
	*	machine, you're working on. Use this with care.
	*/

	#ifdef _WIN32
	system("dir /S");
	#elif linux
	system("ls -alhr");
	#elif __unix__
	system("ls -alhr");
	#endif

	return EXIT_FAILURE;
}
