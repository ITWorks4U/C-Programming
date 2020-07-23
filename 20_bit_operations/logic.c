/**
*	Bit operations in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "logic.h"

static Holder *holder = NULL;
static char numberType[LENGTH];


#define MASK 0b1001001								//	binary mask for number 73
/*	logical bit operations	*/
void modifyWithBit(int number) {
	modifyNumberHolder(CREATE);
	assert(holder != NULL);

	BitState state;
	for (state = _E_AND; state <= _E_XNOR; state++) {
		switch(state) {
			case _E_AND: {
				holder->modifiedNumber = (number & MASK);
				strcpy(holder->numberType, getNumberResult(holder->modifiedNumber));
				break;
			} case _E_OR: {
				holder->modifiedNumber = (number | MASK);
				strcpy(holder->numberType, getNumberResult(holder->modifiedNumber));
				break;
			} case _E_XOR: {
				holder->modifiedNumber = (number ^ MASK);
				strcpy(holder->numberType, getNumberResult(holder->modifiedNumber));
				break;
			} case _E_NOT: {
				holder->modifiedNumber = ~number;
				strcpy(holder->numberType, getNumberResult(holder->modifiedNumber));
				break;
			} case _E_NAND: {
				holder->modifiedNumber = ~(number & MASK);
				strcpy(holder->numberType, getNumberResult(holder->modifiedNumber));
				break;
			} case _E_NOR: {
				holder->modifiedNumber = ~(number | MASK);
				strcpy(holder->numberType, getNumberResult(holder->modifiedNumber));
				break;
			} case _E_XNOR: {
				holder->modifiedNumber = ~(number ^ MASK);
				strcpy(holder->numberType, getNumberResult(holder->modifiedNumber));
				break;
			}
		}

		printf(" Using modification \"%s\" on number %d. Modified number: %d. This number is %s.\n",
			getModifiedOperationAsWord(state), number, holder->modifiedNumber, holder->numberType);
	}
}

/*	shift operations	*/
void modifyWithShift(int number, int bits) {
	assert(holder != NULL);

	/*	left shift	*/
	holder->modifiedNumber = (number << bits);
	strcpy(holder->numberType, getNumberResult(holder->modifiedNumber));
	printf(" Using modification \"LEFT SHIFT\" on number %d. Modified number: %d. This number is %s.\n",
		number, holder->modifiedNumber, holder->numberType);

	/*	right shift	*/
	holder->modifiedNumber = (number >> bits);
	strcpy(holder->numberType, getNumberResult(holder->modifiedNumber));
	printf(" Using modification \"RIGHT SHIFT\" on number %d. Modified number: %d. This number is %s.\n",
		number, holder->modifiedNumber, holder->numberType);

	modifyNumberHolder(DESTROY);
}

/*		Determine if this number is now an even or an odd number.	*/
char *getNumberResult(int number) {
	if (number % 2 == 0) {
		strcpy(numberType, "EVEN");
	} else {
		strcpy(numberType, "ODD");
	}

	/*	Also works with bitwise AND.
	if ((number & 1) == 0) {
		strcpy(numberType, "EVEN");
 	} else {
		strcpy(numberType, "ODD");
	}
	*/

	return numberType;
}

void modifyNumberHolder(Modifer operation) {
	if (operation == CREATE) {
		holder = (Holder *) malloc(sizeof(Holder));
	} else {
		free(holder);
	}
}

char *getModifiedOperationAsWord(BitState state) {
	switch(state) {
		case _E_AND:
			return "AND";
		case _E_OR:
			return "OR";
		case _E_XOR:
			return "XOR";
		case _E_NOT:
			return "NOT";
		case _E_NAND:
			return "NAND";
		case _E_NOR:
			return "NOR";
		case _E_XNOR:
			return "XNOR";
	}

	return NULL;
}
