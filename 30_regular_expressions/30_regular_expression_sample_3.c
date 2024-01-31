/*
	Regular expressions might be hard to understand, however, this is a well made
	way to check an expression against a filter.
*/

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

						//	decimal number expression |	hexadecimal expression	 |	binary	  |	octal
#define	REGEX_PATTERN	"^(-|\\+)?[0-9]+(,|\\.[0-9]+)?|(0x|0X)?[A-Fa-f0-9]+(H|h)?|(0b|0B)[01]+|(o|O)[0-7]+$"
#define MAX_CHARS		100

int on_match(const char *string_to_compare);

int main(void) {
	char expression[MAX_CHARS];

	printf("enter a decimal number: ");

	fgets(expression, MAX_CHARS, stdin);
	size_t length = strlen(expression);
	expression[length-1] = '\0';
	
	printf("result: \"%s\" does ", expression);

	switch(on_match(expression)) {
		case 0:
			puts("match!");
			break;
		case 1:
			puts("not match!");
			break;
		default:
			puts("not proceed, because there was an error...");
			break;
	}

	return EXIT_SUCCESS;
}

int on_match(const char *string_to_compare) {
	int result = 0;
	regex_t reg;

	if (regcomp(&reg, REGEX_PATTERN, REG_EXTENDED) < 0) {
		return -1;
	}

	result = regexec(&reg, string_to_compare, 0, NULL, 0);
	regfree(&reg);

	return result;
}