#include <iostream>
#include <memory>
using namespace std;

/*	shared_ptr is in use to gain access by 2,3,...n more instances, which
	accessing on the same memory address. It's similar to a raw pointer
	usage, however, these pointers are going to release automatically,
	when these are out of scope, e. g. before application termination.

	You're also welcome to release an certain pointer by your own by
	using reset(). => this pointer can STILL be used, however, it
	has no longer a reference to an address.
*/

class Example {
	public:
		void printToConsole() {
			cout << "Hello there!" << endl;
		}

		Example() {		cout << "creating object..." << endl;	}
		~Example() {	cout << "destroying object..." << endl;	}
};

int main() {
	cout << "---------------------" << endl;
	cout << "1st instance:" << endl;
	shared_ptr<Example> e0(new Example());
	e0->printToConsole();
	cout << "address of e0 " << e0.get() << "H" << endl;

	cout << "---------------------" << endl;
	cout << "2st instance:" << endl;
	shared_ptr<Example> e1(e0);

	/*	Since shared_ptr also comes with move(e0), the result, however,
		will be different in contrast to the normal usage.
	*/

	cout << "address of e0 " << e0.get() << "H" << endl;
	cout << "address of e1 " << e1.get() << "H" << endl;

	cout << "---------------------" << endl;
	cout << "deleting e1 instance:" << endl;
	e1.reset();

	cout << "---------------------" << endl;
	cout << "deleting e0 instance:" << endl;
	e0.reset();

	/*	in comparison with raw pointers	*/
	Example *ex0 = new Example();
	ex0->printToConsole();

	Example *ex1 = ex0;
	ex1->printToConsole();

	cout << "address of ex0 " << ex0 << "H" << endl;
	cout << "address of ex1 " << ex1 << "H" << endl;

	//	Since ex1 is going to delete, ex0 is also affected
	//	and these pointers STILL points to the allocated
	//	memory address!
	delete ex1;

	return 0;
}