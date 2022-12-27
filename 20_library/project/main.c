/*
	Contains the main function only.
	The library has been created before.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../library/library.h"

int main() {
	//	----------
	//	Gold
	//	----------
	Element gold;
	memset(gold.name, '\0', sizeof(gold.name));
	memset(gold.symbol, '\0', sizeof(gold.symbol));

	gold.Id = 79;
	memcpy(gold.name, "Gold", strlen("Gold"));
	memcpy(gold.symbol, "Au", strlen("Au"));
	gold.melting_point = 1337.33;
	gold.boiling_point = 3129.0;
	gold.t = SOLID;
	gold.c = NOBLE_METAL;
	gold.n = NATURAL;

	print_element(gold);

	puts("\n****************\n");

	//	----------
	//	Radium
	//	----------
	Element radium;
	memset(radium.name, '\0', sizeof(radium.name));
	memset(radium.symbol, '\0', sizeof(radium.symbol));

	radium.Id = 88;
	memcpy(radium.name, "Radium", strlen("Radium"));
	memcpy(radium.symbol, "Ra", strlen("Ra"));
	radium.melting_point = 973.0;
	radium.boiling_point = 1413.0;
	radium.t = SOLID;
	radium.c = METAL;
	radium.n = RADIOACTIVE;

	print_element(radium);

	return EXIT_SUCCESS;
}