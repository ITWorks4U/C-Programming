/**
*	Bit operations in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

int main() {
	//printf("Size of int value = %d\n", sizeof(int));		//	in this case an integer has a size of 4 bytes
	/*	==>	maximum size of an integer value of type int: 2,147,483,647; binary representation: 11111111 11111111 11111111 11111111	*/

	int valueOne = 127;				/*	00000000 01111111	*/
	int valueTwo = 4349;			/*	00010000 11111101	*/
	puts(" ***********************");
	modifyWithBit(valueOne);
	modifyWithShift(valueOne, 5);

	puts(" ***********************");
	modifyWithBit(valueTwo);
	modifyWithShift(valueTwo, 5);

	return EXIT_SUCCESS;
}
