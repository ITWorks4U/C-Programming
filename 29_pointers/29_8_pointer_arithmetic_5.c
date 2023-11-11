#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/*
		Are you tired about pointer arithmetics? Well, there's much more... (:
	*/

	int i = 100;
	int *ptr0 = &i;
	int *ptr1 = &i;

	printf("i = %d (%p) <=> ptr0 = %d (%p) <=> ptr1 = %d (%p)\n", i, &i, ptr0[0], ptr0, ptr1[0], ptr1);

	/*	impossible =>	ptr0 + ptr1 has a different meaning:
		it doesn't add the values of ptr0 and ptr1;
		the + sign has an another priority workflow and this
		is different to a simple addition
	*/
	//i = ptr0 + ptr1;

	/*	MAY work =>		in contrast to ptr0 + ptr1, a substraction
		can work as expected, but it's not guaranteed.
	*/
	//i = ptr0 - ptr1;

	/*	correct usage	*/
	i = *(ptr0) + *(ptr1);
	printf("i = %d (%p) <=> ptr0 = %d (%p) <=> ptr1 = %d (%p)\n", i, &i, ptr0[0], ptr0, ptr1[0], ptr1);

	ptr0++;
	ptr1--;

	printf("i = %d (%p) <=> ptr0 = %d (%p) <=> ptr1 = %d (%p)\n", i, &i, ptr0[0], ptr0, ptr1[0], ptr1);


	return EXIT_SUCCESS;
}