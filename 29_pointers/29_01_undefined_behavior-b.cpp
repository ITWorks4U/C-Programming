#include <iostream>
using namespace std;

/*
	By using pointers you can directly access to the located memory to work with
	your objects, however, an undefined behavior is still a potentially risk.
	So make sure you know, what to do.

	In this example all three members of the structure is in use.
	While on Linux (in that case) all members can be accessed almost without problems,
	in Windows you might getting in trouble when you try to access to string2.

	It's a pointer, however, without allocating memory for this pointer you don't
	exactly know what's coming next. Especially by using this code in C++ with
	the typical C++ syntax.
*/

struct Example {
	int i_member;
	char string1[100];
	char *string2;
};

int main() {
	Example *ex = new Example();

	/*	It's unusual to use the C-error-check, however, in that case it's plausible to use this.	*/
	if (ex == nullptr) {
		perror("malloc()");
		return 1;
	}

	/*	You don't know what happens, when you're using string2 during runtime!

		It's an undefined behavior! In contrast to the C-syntax, even this has
		been compiled with a C++ - compiler, the behavior may be different
		with the C++ - syntax.
		
		In Linux the output of ex->string2 has been suppressed and when the next
		code is going to print out, this might also be suppressed. Finally,
		working with raw pointers is like a "double-edged sword". It's very easy
		to make mistakes.
	*/

	cout << "i_member: " << ex->i_member << "," << endl
		<< "string1: " << ex->string1 << "," << endl
		<< "string2: " << ex->string2 << endl;
		
	delete ex;

	return 0;
}