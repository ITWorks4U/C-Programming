#include <iostream>
#include <memory>
using namespace std;

/*	weak_ptr are in use, when an instance may use the resource by its own.
	It's similar to a thread, which uses this critical resource, whereas
	each other thread must not use it as well at the same time.
	Since it's similar to a thread, it's not the same!

	When a weak_ptr is in use, you're unable to call methods from
	Example class, as well as, getting the address of this object.
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
	weak_ptr<Example> e1(e0);
	cout << "address of e0 " << e0.get() << "H" << endl;

	/*	won't work for a weak_ptr	*/
	//cout << "address of e1 " << e1.get() << "H" << endl;
	// e1->printToConsole();
	// e1.printToConsole();

	/*	trying to use an instance, which is planned to use
		the resource by its own => e1 comes with a function lock()
		=> on success, e2 is now able to use this resource

		What about e0? Since e0 is a shared_ptr, it also has
		access to the certain memory address.
	*/
	cout << "---------------------" << endl;
	cout << "3rd instance:" << endl;
	if (shared_ptr<Example> e2 = e1.lock()) {
		cout << "locking active..." << endl;
		cout << "e0..." << e0.get() << "H" << endl;
		cout << "e2..." << e2.get() << "H" << endl;
		cout << "# of instances: " << e2.use_count() << endl;
	} else {
		cout << "unable to block the resource for e2 at the moment..." << endl;
	}

	cout << "---------------------" << endl;
	cout << "deleting e1 instance:" << endl;
	e1.reset();

	cout << "---------------------" << endl;
	cout << "try again..." << endl;
	cout << "---------------------" << endl;
	if (shared_ptr<Example> e2 = e1.lock()) {
		cout << "locking active..." << endl;
		cout << "e0..." << e0.get() << "H" << endl;
		cout << "e2..." << e2.get() << "H" << endl;
		cout << "# of instances: " << e2.use_count() << endl;
	} else {
		cout << "unable to block the resource for e2 at the moment..." << endl;
	}

	cout << "---------------------" << endl;
	cout << "deleting e0 instance:" << endl;
	e0.reset();

	/*	There's no need to delete your example instance, because
		this has been released automatically.
	*/

	return 0;
}