/**
*	Bit operations in C.
*
*	@author			ITWorks4U
*/

#ifndef LOGIC_H
#define LOGIC_H
#define LENGTH 5

typedef enum EBitState {
	_E_AND,		//	logic bitwise and
	_E_OR,		//	logic bitwise or
	_E_XOR,		//	logic bitwise xor
	_E_NOT,		//	logic bitwise not
	_E_NAND,	//	logic bitwise nand
	_E_NOR,		//	logic bitwise nor
	_E_XNOR		//	logic bitwise nxor
}BitState;

typedef enum EStructModifer {
	CREATE,			//	allocate a new memory for given struct below
	DESTROY			//	remove allocated struct below from memory
}Modifer;

typedef struct SNumberHolder {
	int modifiedNumber;
	char numberType[LENGTH];
}Holder;

void modifyWithBit(int number);							/*		modify with bit operation		*/
void modifyWithShift(int number, int bits);				/*		shift operations				*/

char *getNumberResult(int number);						/*		Determine if this number is now an even or an odd number.						*/
char *getModifiedOperationAsWord(BitState state);		/*		Receiving the logic state as word.												*/
void modifyNumberHolder(Modifer operation);				/*		Create a new instance of given structure or remove this instance from memory.	*/

#endif
