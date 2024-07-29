#include <iostream>
#include <cstring>

/*
	For C++ it's required to cast your header file, too.
	Otherwise your application can be build in C, but
	not in C++.
*/
extern "C" {
	#include "math.h"
}

using namespace std;

int main() {
	int a = 10;
	int b = 20;

	cout << "running under C++..."	<< endl << endl;

	cout << a << " + " << b << " = " << addition(a,b) << endl;
	cout << a << " - " << b << " = " << subtraction(a,b) << endl;
	cout << a << " * " << b << " = " << multiply(a,b) << endl;
	cout << a << " / " << b << " = " << divide(a,b) << endl;

	Data d;
	memset(d.content, '\0', BUFFER);
	memcpy(d.content, STR_CONTENT, strlen(STR_CONTENT));

	cout << d.content << endl;

	return 0;
}