#include <stdio.h>
#include <stdlib.h>
#include <string.h>																//	required for strerror() function

int main() {
	/*	prints anything to stdout; doesn't handle empty words; without \n the next output is on the same line	*/
	printf("");

	/*	prints anything to stdout; unlike to printf() no formatted output can be handled here; adds a newline by default	*/
	puts("");

	/*	works like printf(), whereas the destination stream can be modified	*/
	fprintf(stdout, "");

	/*	perror allows you to give a detailed error message on any runtime error	*/
	perror("");

	/*	prints an error message by given error number	*/
	fprintf(stderr, "%s\n", strerror(100));

	/*	atcs like puts(), whereas the destination stream can be modified	*/
	fputs("", stdout);

	/*	prints a single character to given stream	*/
	putc('?', stdout);

	/*	almost identical to putc(); has more secure handling for buffer storage	*/
	fputc('?', stdout);

	/*	prints a single character to stdout by default	*/
	putchar('?');

	return EXIT_SUCCESS;
}