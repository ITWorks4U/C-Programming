/**
*	How to read CSV files in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include "csvIO.h"

/**
*	Running program.
*/
int main(void) {
	//defaultOperations();					//	default operations...

	//writeToCSV();							//	write everything from struct SElement to result.csv
	loadValuesFromFile(E_CSV_FILE);			//	read the file "result.csv" and transfer data to struct SElement
	printElements();						//	print to console

	return EXIT_SUCCESS;
}

