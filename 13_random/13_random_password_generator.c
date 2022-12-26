#include <stdio.h>
#include <stdlib.h>
#include <time.h>									/*	for C					*/
// #include <ctime>									/*	for C++					*/
#include <unistd.h>									/*	for Linux only			*/
// #include <windows.h>								/*	for Windows only		*/
#include <string.h>									/*	for memset() function	*/

void random_password_generator(int multiply) {
	char BUFFER[101];
	char start_sign = '!';
	char end_sign = ('z' - 32);
	memset(BUFFER, '\0', 101);						//	memset is much more better than bzero()
													//	bzero() works for Linux only

	for(int i = 0; i < multiply; i++) {
		int number = ((rand() % (int)end_sign) + (int)start_sign);
		BUFFER[i] = (char) number;
	}

	printf("random password with %d characters: %s\n", multiply, BUFFER);
}

int main() {
	time_t t;
	srand(time(&t));

	for(int i = 1; i <= 10; i++) {
		random_password_generator(i * 10);

		sleep(1);									//	for Linux only: 1 second
		// Sleep(1000);								//	for Windows only: 1000 milliseconds
	}

	return EXIT_SUCCESS;
}