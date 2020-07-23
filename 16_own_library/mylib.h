/**
*	In use for an own library.
*
*	@author			ITWorks4U
*/

#ifndef MYLIB_H
#define MYLIB_H

/*	a set of element type for each element	*/
typedef enum EElementType {
	GAS,
	LIQUID,
	SOLID
} Type;

/*	a set of different element classifications	*/
typedef enum EClassification {
	METAL,
	SEMI_METAL,
	NONMETAL,
	NOBLE_METAL,
	NOBLE_GAS
} Classification;

/*	a set of possible bonus notifications	*/
typedef enum EBonusNotification {
	RADIOACTIVE,
	NATURAL,
	ARTIFICIALLY
} Notification;

/*	the structure for each element	*/
typedef struct SElement {
	int elementID;													//	element ID number
	char elementName[20];											//	the element name
	char elementSymbol[2];											//	the element symbol (may be a single character or two characters)
	double atomicWeight;											//	the formal short value
	double electricNegativity;										//	the atomic electronegativity
	Type type;														//	the element type (may be gas, liquid or solid only)
	Classification classification; 									//	the element classificaiton (may be a metal, semi metal, nonmetal or a noble gas)
	Notification notification;										//	a bonus notificaion for the current element
} Element;

void printElement();												//	create an element and print to the console

char *getElementType(Type type);									//	returning the element type in words
char *getElementClassification(Classification classification);		//	returning the element classification in words
char *getElementNotification(Notification notification);			//	returning the element notification in words
#endif
