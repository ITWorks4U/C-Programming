/*	for Windows only => has been tested on a Win10 Home 64 bit (virtualbox) only	*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define MAX_ITEMS	30
#define SHOW_INPUT	1
#define HIDE_INPUT	0

static char buffer[MAX_ITEMS];

void toggle_input(int mode) {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD option;

	/*	similar to tcgetattr()	*/
	GetConsoleMode(hStdin, &option);

	if (mode == SHOW_INPUT) {
		option |= ENABLE_ECHO_INPUT;
	} else {
		option &= ~ENABLE_ECHO_INPUT;
	}

	/*	similar to tcsetattr()	*/
	SetConsoleMode(hStdin, option);
}

void user_input(void) {
	memset(buffer, '\0', MAX_ITEMS);
	int c;
	int ctr = 0;

	printf("enter anything: ");

	do {
		c = getchar();
		if (c != '\n' || c!='\r') {
			buffer[ctr++] = c;
		}
	} while(c != '\n' && c !='\r' && ctr < (MAX_ITEMS - 1));

	buffer[ctr] = '\0';
}

int main(void) {
	/*	---		normal usage	---	*/
	puts("\t---\tnormal\t---\t");
	user_input();
	printf("visible input: %s\n", buffer);

	/*	---		hiding			---	*/
	puts("\t---\thidden\t---\t");
	
	toggle_input(HIDE_INPUT);
	user_input();
	printf("hidden input: %s\n", buffer);

	/*	---		restore			---	*/
	puts("\t---\trestored\t---\t");
	
	toggle_input(SHOW_INPUT);
	user_input();
	printf("visible input: %s\n", buffer);

	return EXIT_SUCCESS;
}