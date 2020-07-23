/**
*	How to read CSV files in C.
*
*	@author			ITWorks4U
*/

#ifndef ELEMENT_PROPERTIES_H
#define ELEMENT_PROPERTIES_H

/**	a set of element type for each element	*/
typedef enum EElementType {
	GAS,
	LIQUID,
	SOLID
} Type;

/**	a set of different element classifications	*/
typedef enum EClassification {
	METAL,
	SEMI_METAL,
	NO_METAL,
	NOBLE_METAL,
	NOBLE_GAS
} Classification;

/**	a set of possible bonus notifications	*/
typedef enum EBonusNotification {
	RADIOACTIVE,
	NATURAL,
	ARTIFICIALLY
} Notification;

/**	an identification which source is selected	*/
typedef enum ESourceSelector {
	E_DEFAULT = 511,
	E_CSV_FILE = 1023
}Selector;

#define WORD_LENGTH		16
#define	NBR_OF_WORDS	8
void loadValuesFromFile(const Selector s);							//	load data from a file
void readValues(char word[NBR_OF_WORDS][WORD_LENGTH], Selector s);	//	transfer data to a linked list
void printElements(void);											//	print result
void defaultOperations(void);

Type convertToType(char *content);									//	convert to Type
Classification convertToClassification(char *content);				//	convert to Classification
Notification convertToNotification(char *content);					//	convert to Notification

char *getElementType(Type type);									//	returning the element type in words
char *getElementClassification(Classification classification);		//	returning the element classification in words
char *getElementNotification(Notification notification);			//	returning the element notification in words
#endif
