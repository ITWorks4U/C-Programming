#include "library.h"
#include <stdio.h>

void print_element(Element e) {
	printf(
		"%d,\n%s,\n%s,\n%.6lf K,\n%.9lf K,\nelement is: ",
		e.Id, e.name, e.symbol, e.melting_point, e.boiling_point
	);

	switch(e.t) {
		case SOLID:
			puts("solid, ");
			break;
		case LIQUID:
			puts("liquid, ");
			break;
		default:
			puts("gas, ");
			break;
	}

	printf("class: ");

	switch(e.c) {
		case METAL:
			puts("metal, ");
			break;
		case SEMI_METAL:
			puts("semi metal, ");
			break;
		case NON_METAL:
			puts("no metal, ");
			break;
		case NOBLE_METAL:
			puts("noble metal, ");
			break;
		default:
			puts("noble gas, ");
			break;
	}

	printf("notofication: ");
	switch(e.n) {
		case NATURAL:
			puts("natural element");
			break;
		case ARTIFICIALLY:
			puts("artifically element");
			break;
		default:
			puts("radioactive element");
			break;
	}
}