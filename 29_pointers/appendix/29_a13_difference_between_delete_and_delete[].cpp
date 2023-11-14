#include <iostream>

/*	By using raw pointers in C++ instead of free() delete is in use,
	however, what happens in case of delete[]?

	delete is in use, if and only if, a single object instance is in use.
	delete[] is in use, if and only if, a field of object instances is in use.

	You MAY use delete for a field or delete[] for a single object, however,
	it causes an undefined behavior and memory leaks often occurs.

	Recommendation: Don't use raw pointers in C++.
*/

int main() {
	int *i_ptr = new int;

	/*
		Do whatever you want to do with this single instance, even it's an integer field.
		Since it's a pointer with a size of 8 bytes, it "only" has an allocated size of
		4 bytes (integer only) => similar to C: int *i_ptr = malloc(int)

		By using delete only the allocated memory in bytes are going to release.
		By using delete[] you're also going to release memory, which hasn't been used
		for the allocation process => You don't know, what may happen!
	*/
	delete i_ptr;

	//	-----------------------

	int *i_field = new int[20];

	/*
		Since i_field is an integer field with an amount of 20 elements with each size of
		4 bytes, this field must be released element for element => delete[] does this job.

		By using delete you'll only delete the first element, however, the 19 elements left
		still exists. => Memory leak.
	*/

	delete []i_field;
	
	/*	Since [] and * are often interpreted as the same, this won't work.	*/
	// delete *i_field;

	return 0;
}