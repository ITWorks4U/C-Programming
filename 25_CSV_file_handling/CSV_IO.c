/**
*	How to read CSV files in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "csvIO.h"

/**
*	write all element informations to a CSV file
*/
void writeToCSV(void) {
	FILE *dest = fopen(CSV_FILE, "w+");
	assert(dest != NULL);
	Element *tmp = dataList;

	while (tmp->next != NULL) {
		/*	The function fprintf() allows to write content to any file
		 *	which is a type of text, where you may write content to a *.csv file, too.
		*/
		fprintf(dest, " %3d, %10s, %10s, %.3f, %.3f, %10s, %10s, %10s\n",
			tmp->elementID, tmp->elementName, tmp->elementSymbol, tmp->atomicWeight, tmp->electricNegativity,
			getElementType(tmp->type), getElementClassification(tmp->classification), getElementNotification(tmp->notification)
		);

		tmp = tmp->next;
	}

	fclose(dest);
}

/*	The functions getElement*(...) converts an enumeration value into a C-String.	*/
