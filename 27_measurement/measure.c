/**
*	How to measure a time for anything in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>															/*	using for clock_t type and clock() function									*/
#include <limits.h>															/*	holds the maximum limit for integers and many more							*/

#define	STR_SIZE	64
#define	WORD1		" Look, what is there? Maybe an inportant message..."
#define WORD2		" C programming is hard, but still oldschool."

int main() {
	clock_t start;
	clock_t end;
	unsigned int ctr = 0;
	char BUFFER[STR_SIZE] = {'\0'};

	start = clock();														/*	start time measure															*/

	while (ctr != UINT_MAX) {												/*	UINT_MAX := 4,294,967,295; may be depending on the running maschine			*/
		strncpy(BUFFER, WORD1, strlen(WORD1));								/*	copy content of WORD1 to BUFFER												*/
		strncpy(BUFFER, WORD2, strlen(WORD2));								/*	overwrite BUFFER with WORD2													*/		
		ctr++;
	}

	end = clock();															/*	stop time measure															*/
	double runningTime = ((double) (end - start) / CLOCKS_PER_SEC);			/*	CLOCKS_PER_SEC := specifies the relation between a clock tick and a second	*/
	printf(" Elapsed time for program: %.6lf seconds.\n", runningTime);	

	return EXIT_SUCCESS;
}
