#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>																							//	allows us to use
																											//	jmp_buf structure,
																											//	longjmp() and setjmp()
																											//	functions

static jmp_buf divZeroJumper;																				//	in use to jump, if required

void division_zero_catcher(int denominator) {																//	in case of denominator is zero
	fprintf(stderr, "denominator = %d => not allowed for calculation\n", denominator);						//	we're now able to handle this
	longjmp(divZeroJumper,1);																				//	exception, whereas the normal
																											//	workflow is guaranteed, because
																											//	divZeroJumper is not set with
																											//	value 1
}

int main(void) {
	int numerator = 100;

	for(int denominator = 10; denominator >= -10; denominator -= 2) {
		/*
			While divZeroJumper is still unset we're trying to calculate our stuff.
			At any point denominator is zero, whereas a zero division exception
			appears, but we're now able to handle this specific exception and
			we can still continue our workflow here. 
		*/
	
		if (!setjmp(divZeroJumper)) {
			if (denominator == 0) {
				division_zero_catcher(denominator);
			} else {
				printf("%d / %d = %d\n", numerator, denominator, numerator / denominator);
			}
		}
	}

	puts("You'll never see this text on runtime... Oh, wait!");

	return EXIT_SUCCESS;
}
