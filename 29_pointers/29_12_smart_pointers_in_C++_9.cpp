#include <iostream>
#include <memory>
using namespace std;

/*	unique_ptr is in use to gain access to a resource by one instance only.
	It works like auto_ptr, however, it comes with more options for us.
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
	unique_ptr<Example> e0(new Example());
	e0->printToConsole();
	cout << "address of e0 " << e0.get() << "H" << endl;

	cout << "---------------------" << endl;
	cout << "2st instance:" << endl;

	/*	e1 is now using the resource, whereas e0 is automatically been released	*/
	unique_ptr<Example> e1 = move(e0);
	cout << "address of e0 " << e0.get() << "H" << endl;
	cout << "address of e1 " << e1.get() << "H" << endl;

	cout << "---------------------" << endl;
	cout << "deleting e1 instance:" << endl;
	e1.reset();

	cout << "---------------------" << endl;
	cout << "deleting e0 instance:" << endl;

	/*	it won't throw an exception	*/
	e0.reset();

	/*	There's no need to delete your example instance, because
		this has been released automatically.
	*/

	return 0;
}