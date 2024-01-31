/*
	Regular expressions might be hard to understand, however, this is a well made
	way to check an expression against a filter.
*/

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

/*
	Do you think, that "check, if an input is a number" is the only implementation for regular expressions?
	No. Since you now know how to use regular expressions, you can do much more.
*/
#define	REGEX_PATTERN	"^[a-z]{1,10}@(gmail|gmx|hotmail)\\.(com|info|de)$"
#define MAX_CHARS		25

int on_match(const char *string_to_compare);

int main(void) {
	char expression[MAX_CHARS];

	printf("check mail address: ");

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