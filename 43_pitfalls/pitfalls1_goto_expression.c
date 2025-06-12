/*	Using goto expressions instead of loops.
*
*	Goto expressions MIGHT speed up your code, if you really
*	know what you do. Usually in assembly language goto helps
*	you to jump to other marks.
*
*	In languages, like C, C++, Java, C#, goto can be used as well,
*	however, your code will become a horrible mess.
*
*	Since your code does not follow a clean workflow, you'll get
*	"spaghetti code", where your instructions jumps from begin to end,
*	returning to that line, and then this line, ...
*
*	To avoid such code mess, use a loop instead.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int counter = 0;

	/*	define a mark for a goto command	*/
	beginLabel:

	if (counter < 10) {
		printf("current value: %d\n", counter);
		goto raiseLabel;
	}

	goto endLabel;

	raiseLabel:
	counter++;
	goto beginLabel;

	endLabel:
	return EXIT_FAILURE;
}

// /*	use a loop instead:	*/
// int main(void) {
// 	for (int counter = 0; counter < 10; counter++) {
// 		printf("current value: %d\n", counter);
// 	}

// 	return EXIT_SUCCESS;
// }