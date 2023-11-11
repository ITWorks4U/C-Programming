#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

/*
	ATTENTION:
	THIS IS FOR EDUCATIONAL PURPOSE ONLY!
	IT'S NOT A GUIDELINE FOR "How to programming a computer virus" OR ELSE!
	USE THIS AT YOUR OWN RISK!

	YOU SHOULD ALSO KNOW THAT YOUR RUNNING SYSTEM IS ALSO AFFECTED, WHEN NO MORE MEMORY
	IS AVAILABLE. SO YOU HAVE TO REBOOT YOUR SYSTEM! THIS MAY ALSO AFFECT YOUR HARDWARE ON RUNTIME!
*/

int main(void) {
	int gigabyte = 1024*1024*1024;
	int ctr = 0;

	/*	Don't, seriously, don't do this!	*/

	while(true) {
		void *ptr = malloc(gigabyte);

		if (ptr == NULL) {
			fprintf(stderr, "malloc refused after %d GB, error message: %s\n", ctr, strerror(errno));
			return EXIT_FAILURE;
		}

		memset(ptr, 1, gigabyte);
		printf("allocated %d GB...\n", ++ctr);
	}

	return EXIT_SUCCESS;
}