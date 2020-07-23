/**
*	How to read CSV files in C.
*
*	@author			ITWorks4U
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "csvIO.h"

/**	will hold all words from a line	*/
static char dummyWords[NBR_OF_WORDS][WORD_LENGTH];

/**
*	Load all values from a file, depending on given Selector,
*	to the linked list.
*/
void loadValuesFromFile(const Selector s) {
	FILE *src = NULL;

	if (s == E_DEFAULT) {
		src = fopen(DFL_SRC, "r");
	} else if (s == E_CSV_FILE) {
		src = fopen(CSV_FILE, "r");
	}

	assert(src != NULL);
	int res = 0;

	do {
		res = fscanf(src, "%s %s %s %s %s %s %s %s",
			dummyWords[0], dummyWords[1], dummyWords[2], dummyWords[3],
			dummyWords[4], dummyWords[5], dummyWords[6], dummyWords[7]
		);

		readValues(dummyWords, s);
	} while(res != EOF);
	fclose(src);
}

/**
*	Whenever a full line has been read, transfer the data to
*	a linked list.
*/
void readValues(char word[NBR_OF_WORDS][WORD_LENGTH], Selector s) {
	Element *tmp = (Element *)	calloc(1, sizeof(Element));
	assert(tmp != NULL);
	char dummyWord[2][WORD_LENGTH] = {"\0", "\0"};

	int i;
	for (i = 0; i < NBR_OF_WORDS; i++) {
		switch(i) {
			case 0:
				tmp->elementID = strtol(word[i], NULL, 0);
				break;
			case 1:
				if (s == E_CSV_FILE) {
					strncpy(tmp->elementName, word[i], (strlen(word[i]) -1));
				} else {
					strncpy(tmp->elementName, word[i], strlen(word[i]));
				}

				break;
			case 2:
				if (s == E_CSV_FILE) {
					strncpy(tmp->elementSymbol, word[i], (strlen(word[i]) -1));
				} else {
					strncpy(tmp->elementSymbol, word[i], strlen(word[i]));
				}

				break;
			case 3:
				tmp->atomicWeight = strtod(word[i], NULL);
				break;
			case 4:
				tmp->electricNegativity = strtod(word[i], NULL);
				break;
			case 5:
				if (s == E_CSV_FILE) {
					strncpy(dummyWord[0], word[i], (strlen(word[i]) -1));
					tmp->type = convertToType(dummyWord[0]);
				} else {
					tmp->type = convertToType(word[i]);
				}

				break;
			case 6:
				if (s == E_CSV_FILE) {
					strncpy(dummyWord[1], word[i], (strlen(word[i]) -1));					
					tmp->classification = convertToClassification(dummyWord[1]);
				} else {
					tmp->classification = convertToClassification(word[i]);
				}

				break;
			case 7:
				tmp->notification = convertToNotification(word[i]);

				break;
		}
	}

	/*	Now all required members has been set. Add this new tmp set to structure SElement.	*/
	if (dataList == NULL) {
		dataList = (Element *) calloc(1, sizeof(Element));
		assert(dataList != NULL);

		dataList->elementID	= tmp->elementID;
		strncpy(dataList->elementName, tmp->elementName, strlen(tmp->elementName));
		strncpy(dataList->elementSymbol, tmp->elementSymbol, strlen(tmp->elementSymbol));
		dataList->atomicWeight = tmp->atomicWeight;
		dataList->electricNegativity = tmp->electricNegativity;
		dataList->type = tmp->type;
		dataList->classification = tmp->classification;
		dataList->notification = tmp->notification;

		dataList->next = NULL;
	} else {
		Element *newElement = dataList;
		while (newElement->next != NULL) {
			newElement = newElement->next;
		}

		newElement->next = (Element *) calloc(1, sizeof(Element));
		newElement = newElement->next;

		newElement->elementID = tmp->elementID;
		strcpy(newElement->elementName, tmp->elementName);
		strcpy(newElement->elementSymbol, tmp->elementSymbol);
		newElement->atomicWeight = tmp->atomicWeight;
		newElement->electricNegativity = tmp->electricNegativity;
		newElement->type = tmp->type;
		newElement->classification = tmp->classification;
		newElement->notification = tmp->notification;

		newElement->next = NULL;
	}

	free(tmp);
}

/**
*	Print all data from the linked list to the console.
*/
void printElements(void) {
	assert(dataList != NULL);
	Element *tmp = dataList;

	while (tmp->next != NULL) {
		printf(" %3d | %15s | %2s | %.3lf\t | %.3lf\t | %15s | %15s | %15s\n",
			tmp->elementID, tmp->elementName, tmp->elementSymbol, tmp->atomicWeight, tmp->electricNegativity,
			getElementType(tmp->type), getElementClassification(tmp->classification), getElementNotification(tmp->notification)
		);

		tmp = tmp->next;
	}
}

void defaultOperations(void) {
	loadValuesFromFile(E_DEFAULT);
	printElements();
}

