/*	for Linux only => might also work on macOS	*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>

#define MAX_ITEMS	30
#define FLAGS_FOR_ECHO (ECHO | ECHOE | ECHOK | ECHONL)
#define SHOW_INPUT	1
#define HIDE_INPUT	0

static char buffer[MAX_ITEMS];

void toggle_input(int fd, int mode) {
	struct termios t;

	if (tcgetattr(fd, &t) < 0) {
		perror("tcgetattr()");
		exit(EXIT_FAILURE);
	}

	if (mode == SHOW_INPUT) {
		t.c_lflag |= FLAGS_FOR_ECHO;
	} else {
		t.c_lflag &= ~FLAGS_FOR_ECHO;
	}

	/*
		TCSANOW = 0, the change shall occur immediately

		TCSADRAIN = 1, the change shall occur after all output written to fildes is transmitted.
		This function should be used when changing parameters that affect output.

		TCSAFLUSH = 2, the change shall occur after all output written to fildes is transmitted,
		and all input so far received but not read shall be discarded before the change is made.
	*/
	if (tcsetattr(fd, TCSAFLUSH, &t) < 0) {
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}
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
	
	toggle_input(STDIN_FILENO, HIDE_INPUT);
	user_input();
	printf("hidden input: %s\n", buffer);

	/*	---		restore			---	*/
	puts("\t---\trestored\t---\t");
	
	toggle_input(STDIN_FILENO, SHOW_INPUT);
	user_input();
	printf("visible input: %s\n", buffer);

	return EXIT_SUCCESS;
}