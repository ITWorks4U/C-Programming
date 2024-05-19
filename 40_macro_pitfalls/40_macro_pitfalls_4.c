/*
	Macros allows you to use short instructions with an expected clean workflow,
	however, you it's much easier to do it wrong.
*/
#include <stdio.h>
#include <stdlib.h>

/*
	Typically, macro (functions) are in use for a clean structure and also for a specific purpose.
	In that case any expected integer number is given and it will be combined with 1 by bitwise AND.
	Is the last bit is 1, then "x" is an odd number, otherwise it's even.

	What will happen, if x is not an integer number? In that case(s) this application is unable to build.
*/
#define	BIT_ONE	0x1
#define	CHECK_IF_ODD_NUMBER(x) (x) & BIT_ONE

void function1(void) {
	int a = 10;
	printf("%d is odd? => %s\n", a, CHECK_IF_ODD_NUMBER(a) ? "yes" : "no");

	//	a long (long) is also an integer, thus this works, too
	printf("%ld is odd? => %s\n", 150000000000000000L, CHECK_IF_ODD_NUMBER(150000000000000000L) ? "yes" : "no");

	//	for floating point numbers this won't work as expected
	//printf("%lf is odd? => %s\n", 2.71828182845904523536, CHECK_IF_ODD_NUMBER(2.71828182845904523536) ? "yes" : "no");

	//	single character(s) can still be used, because these points to their ASCII position (g = 103)
	printf("%c (%d) is odd? => %s\n", 'g', 'g', CHECK_IF_ODD_NUMBER('g') ? "yes" : "no");

	//	luckily, this won't also work
	//printf("%s is odd? => %s\n", "Hello", CHECK_IF_ODD_NUMBER("Hello") ? "yes" : "no");
}

/*
	more for function 2

	Assuming, you're using a 16 bit number (0-65535) and want to check, if on a certain
	bit position a bit is set or not. Imagine, you're working with µc (micro controllers).
	In that case such operation(s) is/are normal.
*/
#include <string.h>
#define	MAX_LEN_BINARY	16
void binary(const int number) {
	char bin_num[MAX_LEN_BINARY];
	memset(bin_num, '\0', MAX_LEN_BINARY);
	int tmp = number;

	/*	a simple way, but also primitive, to convert the decimal integer into a binary integer expression	*/
	for(int i = 0; tmp > 0; i++) {
		if (tmp % 2 == 0) {
			bin_num[i] = '1';
		} else {
			bin_num[i] = '0';
		}

		tmp /= 2;
	}

	printf("0b%s\n", bin_num);
}

void function2(void) {
	//	13 bits
	int number = 4321;
	int bitpos = 7;

	printf("%d <=> ", number);
	binary(number);
	printf("on bitpos %d the bit is %d\n", bitpos, (number >> bitpos) & BIT_ONE);
}

int main(void) {
	//function1();
	function2();

	return EXIT_SUCCESS;
}