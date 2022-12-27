#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Since an union and a struct
	differs, a "fusion" of both
	data types is also available.

	This example below simulates
	a type modifier.
*/

typedef struct {
	union {
		struct {
			char city[50];
			char zip[10];
			char first_name[50];
			char last_name[50];
		} private;

		struct {
			char city[50];
			char zip[10];
			char first_name[50];
			char last_name[50];
		} public;
	};
} Address; 

int main() {
	printf("Amount of bytes for Address: %lu\n", sizeof(Address));

	/*	Without an array, an accessing on a member it affects an another member!	*/

	Address a[2];
	memcpy(a[0].public.city, "New York", strlen("New York"));
	memcpy(a[0].public.zip, "10001", strlen("10001"));
	memcpy(a[0].public.first_name, "Adam", strlen("Adam"));
	memcpy(a[0].public.last_name, "Johnsons", strlen("Johnsons"));

	memcpy(a[1].public.city, "Miami", strlen("Miami"));
	memcpy(a[1].public.zip, "33101", strlen("33101"));
	memcpy(a[1].public.first_name, "Adam", strlen("Adam"));
	memcpy(a[1].public.last_name, "Johnsons", strlen("Johnsons"));

	printf("private address: %s, %s, %s, %s\n", a[0].private.city, a[0].private.zip, a[0].private.first_name, a[0].private.last_name);
	printf("public address: %s, %s, %s, %s\n", a[1].public.city, a[1].public.zip, a[1].public.first_name, a[1].public.last_name);

	return EXIT_SUCCESS;
}