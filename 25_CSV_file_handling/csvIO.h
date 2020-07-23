/**
*	How to read CSV files in C.
*
*	@author			ITWorks4U
*/

#ifndef _CSV_IO_H
#define _CSV_IO_H
#include "ElementProperties.h"						//	comes with a set of enumerations for struct below

/*	***	definitions	***	*/
#define DFL_SRC		"data.txt"						//	hold data from a default file
#define CSV_FILE	"result.csv"					//	will hold data from a specific file

/**	the structure for each element	*/
typedef struct SElement Element;

struct SElement {
	/*	required members		*/
	int elementID;									//	element ID number
	char elementName[20];							//	the element name
	char elementSymbol[2];							//	the element symbol (may be a single character or two characters)
	double atomicWeight;							//	the formal short value
	double electricNegativity;						//	the atomic electronegativity

	/*	optional enum members	*/
	Type type;										//	the element type (may be GAS, LIQUID or SOLID only)
	Classification classification; 					//	the element classificaiton (may be a METAL, SEMI_METAL, NO_METAL or a NOBLE_GAS)
	Notification notification;						//	a bonus notificaion for the current element, like RADIOACTIVE, ARTIFICIALLY or NATURAL

	/*	pointer					*/
	Element *next;									//	points to the next element information
};

Element *dataList;									//	the list which holds all elements

void writeToCSV(void);								//	write all element informations to a .csv file

#endif
