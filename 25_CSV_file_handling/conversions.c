/**
*	How to read CSV files in C.
*
*	@author			ITWorks4U
*/

#include <string.h>
#include <stdio.h>
#include "csvIO.h"

static char *elementType[] = {"GAS", "LIQUID", "SOLID"};
static char *elementClass[] = {"METAL", "SEMI_METAL", "NO_METAL", "NOBLE_METAL", "NOBLE_GAS"};
static char *elementProperty[] = {"RADIOACTIVE", "NATURAL", "ARTIFICIALLY"};

/**
*	Convert the type of an element from a word into it's specified enumeration.
*/
Type convertToType(char *content) {
	if (strncmp(elementType[0], content, strlen(content)) == 0) {				//	element is a gas
		return GAS;
	} else if (strncmp(elementType[1], content, strlen(content)) == 0) {		//	it's a liquid element
		return LIQUID;
	}

	/*	otherwise element is solid	*/
	return SOLID;
}

/**
*	Convert element class from a word into it's enum value.
*/
Classification convertToClassification(char *content) {
	if (strncmp(elementClass[0], content, strlen(content)) == 0) {				//	metal
		return METAL;
	} else if (strncmp(elementClass[1], content, strlen(content)) == 0) {		//	semi metal
		return SEMI_METAL;
	} else if (strncmp(elementClass[2], content, strlen(content)) == 0) {		//	non metal
		return NO_METAL;
	} else if (strncmp(elementClass[3], content, strlen(content)) == 0) {		//	noble metal
		return NOBLE_METAL;
	}
	
	/*	otherwise it's a noble gas	*/
	return NOBLE_GAS;
}

/**
*	Convert element notification from a word into it's enum value.
*/
Notification convertToNotification(char *content) {
	if (strncmp(elementProperty[0], content, strlen(content)) == 0) {			//	radioactive element
		return RADIOACTIVE;
	} else if (strncmp(elementProperty[1], content, strlen(content)) == 0) {	//	naturally element
		return NATURAL;
	}

	/*	otherwise it's an artificially element	*/
	return ARTIFICIALLY;
}

/**
*	Convert an enumeration value to a word.
*/
char *getElementType(Type type) {
	switch(type) {
		case GAS:
			return elementType[0];
		case LIQUID:
			return elementType[1];
		case SOLID:
			return elementType[2];
	}

	return "unknown element";
}

/**
*	Convert an element class to a word.
*/
char *getElementClassification(Classification classification) {
	switch(classification) {
		case METAL:
			return elementClass[0];
		case SEMI_METAL:
			return elementClass[1];
		case NO_METAL:
			return elementClass[2];
		case NOBLE_METAL:
			return elementClass[3];
		case NOBLE_GAS:
			return elementClass[4];
	}

	return "unknown element class";
}

/**
*	Convert an element notification to a word.
*/
char *getElementNotification(Notification notification) {
	switch(notification) {
		case RADIOACTIVE:
			return elementProperty[0];
		case NATURAL:
			return elementProperty[1];
		case ARTIFICIALLY:
			return elementProperty[2];
	}

	return "unknown notification";
}
