#include <iostream>
#include <memory>
using namespace std;

/*	auto_ptr is in use to gain access to a resource by one instance only.
	In C++ 11 and higher this pointer handling has been marked as deprecated.
	It's recommended to use unique_ptr.

	The idea of an auto_ptr:
	Only 1 pointer has access to a certain resource. When a second pointer wants
	to use this resource, pointer1 moves this resource to pointer2 and pointer1
	is automatically released.
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
	auto_ptr<Example> e0(new Example());
	e0->printToConsole();
	cout << "address of e0 " << e0.get() << "H" << endl;

	cout << "---------------------" << endl;
	cout << "2st instance:" << endl;

	/*	e1 is now using the resource, whereas e0 is automatically been released	*/
	auto_ptr<Example> e1(e0);
	cout << "address of e0 " << e0.get() << "H" << endl;
	cout << "address of e1 " << e1.get() << "H" << endl;

	cout << "---------------------" << endl;
	cout << "deleting e1 instance:" << endl;
	e1.reset();

	cout << "---------------------" << endl;
	cout << "deleting e0 instance:" << endl;

	/*	it won't throw an exception	*/
	e0.reset();

	return 0;
}