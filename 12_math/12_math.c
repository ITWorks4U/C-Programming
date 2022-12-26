/*
	For Linux: The linker needs -lm as additional compiler command,
	otherwise the functions can't be used correctly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>																/*	for C only	*/
// #include <cmath>																/*	for C++ recommended	*/

void calculate_area_circle(int radius) {
	printf("area: %e\n", M_PI * radius * radius);
}

void calculate_volume_circle(int radius) {
	printf("volume: %e\n", 4/3 * M_PI * radius * radius * radius);
}

int main() {
	for(int i = 0; i < 50; i++) {
		calculate_area_circle(i);
		calculate_volume_circle(i);
		printf("power of %d = %e\n", i, pow((double)i, (double)i));			//	casting is recommended
		printf("square root of %d = %e\n", i, sqrt((double) i));
		printf("sine of %d = %e\n", i, sin((double) i));

		//	many other functions here...
	}

	return EXIT_SUCCESS;
}