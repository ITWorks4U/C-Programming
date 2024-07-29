/*
	Example: Create your own random password generator written in C.

	Attention:
		This application is written in C only.
		It also works with C++.

		The working machine is: Linux Mint 21.1.
		It runs also on any other Linux machine / Windows 10 / macOS (not tested).

	Have fun! :)

	PS:		macros were handled in chapter 17, but these are also implemented here
	PPS:	This is an updated version, which is better to understand.
*/
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
	/*	for C++ recommended	*/
	#include <ctime>
#else
	/*	for C only	*/
	#include <time.h>
#endif

#if	defined(__WIN32__) || defined(__WIN64__)
	/*	for Windows only	*/
	#include <windows.h>
#else
	/*	for Linux only (perhaps also available for macOS)	*/
	#include <unistd.h>
#endif

#include <string.h>									/*	for memset() function	*/

/*	a pool of available characters	=>	'%' must be marked with %%	*/
#define	CHAR_POOL	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!\"$%%&/()=?;,:._-'#*+\\{}[]"

//	---------------
//	---------------
//	---------------

void random_password_generator(int amount_of_chars) {
	char passwd[amount_of_chars];
	int ctr = 0;

	/*	formatting the C-string with certain null termination characters n times	*/
	memset(passwd, '\0', amount_of_chars);

	/*
		amount_of_chars - 1:	remember: you are using C-strings,
		thus the null termination character \0 must be present.
		Otherwise an undefined behavior appears.
	*/
	while(ctr != (amount_of_chars - 1)) {
		int rand_nbr = rand() % strlen(CHAR_POOL);
		passwd[ctr] = CHAR_POOL[rand_nbr];
		ctr++;
	}

	printf("amount of characters: %d <=> random password: %s\n", (amount_of_chars - 1), passwd);
}

int main() {
	time_t t;
	srand(time(&t));
	/* srand(time(NULL)) works, too	*/

	/*
		By using a password length between 1(!) and 200(!) characters WITH a delay of
		ONE SECOND for each iteration your application takes... *drumroll* 200s.

		But why do we start at 2? By using 1 or 0, the application crashes,
		because a C-string-violation attempt is in use.
	*/
	for(int i = 2; i <= 201; i++) {
		random_password_generator(i);

		#if defined(__WIN32__) || defined(__WIN64__)
			/*	Windows:	sleep 1000 milliseconds	*/
			Sleep(1000);
		#else
			/*	Linux / macOS (not tested): sleep 1 second	*/
			sleep(1);
		#endif
	}

	return EXIT_SUCCESS;
}