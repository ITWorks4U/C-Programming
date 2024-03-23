#include <stdio.h>
#include <stdlib.h>

#define LAMBDA(lambda$_ret, lambda$_args, lambda$_body) ({\
	lambda$_ret lambda$__anon$ lambda$_args lambda$_body &lambda$__anon$;\
})

static double collection[] = {3.141, 2.713, 9e3, 3e-5};
static int int_collection[] = {1,2,3,4,5,6,7,8,9,10};
static char word[] = "You can also use lambda expressions in C! These are rather difficult than in C++.";

double average_apply(double (*fn)(double)) {
	double avg = 0.0;
	int nbrOfElements = sizeof(collection)/sizeof(collection[0]);

	for (int i=0; i < nbrOfElements; i++) {
		avg += fn(collection[i]);
	}

	return avg/nbrOfElements;
}

int summary_apply(int (*fn)(int inp)) {
	int sum = 0;
	int nbrOfElements = sizeof(int_collection)/sizeof(int_collection[0]);

	for(int i = 0; i < nbrOfElements; i++) {
		sum += fn(int_collection[i]);
	}

	return sum;
}

char word_apply(char (*fn)(char inp)) {
	char sign = '\0';
	int nbrOfElements = sizeof(word)/sizeof(word[0]);

	for(int i = 0; i < nbrOfElements; i++) {
		sign += fn(word[i]);
	}

	return sign;
}

int main(void) {
	printf("average = %lf\n",average_apply(LAMBDA(double, (double x), {return x;})));
	printf("average = %lf\n",average_apply(LAMBDA(double, (double x), {return x*x;})));
	printf("average = %lf\n",average_apply(LAMBDA(double, (double x), {return x/3;})));

	printf("sum = %d\n", summary_apply(LAMBDA(int, (int x), {return x;})));

	char ret = word_apply(LAMBDA(char, (char x), {return x;}));
	printf("sign = %c (%d)\n", ret, (int) ret);

	return EXIT_SUCCESS;
}