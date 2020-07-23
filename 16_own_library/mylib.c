/**
*	Implementation of custom library functions.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

/**	Print an element to the console.	*/
void printElement() {
	/*	example: gold (lat. aurum)	*/
	Element *periodicElement = (Element *) malloc(sizeof(Element));

	periodicElement->elementID = 79;
	strcpy(periodicElement->elementName, "Aurum");
	strcpy(periodicElement->elementSymbol, "AU");
	periodicElement->atomicWeight = 196.97F;
	periodicElement->electricNegativity = 2.4F;
	periodicElement->type = SOLID;
	periodicElement->classification = NOBLE_METAL;
	periodicElement->notification = NATURAL;

	/*	print the element to the console....	*/
	printf("\nELEMENT:\n");
	printf(" ID: %d\n", periodicElement->elementID);
	printf(" name: %s\n", periodicElement->elementName);
	printf(" symbol: %s\n", periodicElement->elementSymbol);
	printf(" atomic weight: %.2lf g/cm^3\n", periodicElement->atomicWeight);
	printf(" atomic electrical negativity value: %.2lf\n", periodicElement->electricNegativity);
	printf(" atomic type: %s\n", getElementType(periodicElement->type));
	printf(" atomic classification: %s\n", getElementClassification(periodicElement->classification));
	printf(" atomic notification: %s\n", getElementNotification(periodicElement->notification));

	free(periodicElement);
}

/**
*	Returning the element type of given type for each element.
*
*	param:
*		type - the element type from enumeration
*
*	return:
*		the element type in words
*/
char *getElementType(Type type) {
	switch (type) {
		case GAS:
			return "GAS";
		case LIQUID:
			return "LIQUID";
	}

	return "SOLID";
}

/**
*	Returning the element classification of given element in words.
*
*	param:
*		classification - the element classification
*
*	return:
*		the element classification in words
*/
char *getElementClassification(Classification classification) {
	switch (classification) {
		case METAL:
			return "METAL";
		case SEMI_METAL:
			return "SEMI METAL";
		case NONMETAL:
			return "NONMETAL";
		case NOBLE_METAL:
			return "NOBLE METAL";
	}

	return "NOBLE GAS";
}

/**
*	Returning the element notification of given element in words.
*
*	param:
*		notification - the element notification
*
*	return:
*		the element notification in words
*/
char *getElementNotification(Notification notification) {
	switch (notification) {
		case RADIOACTIVE:
			return "RADIOACTIVE ELEMENT";
		case NATURAL:
			return "NATURAL ELEMENT";
	}

	return "ARTIFICIALLY ELEMENT";
}
