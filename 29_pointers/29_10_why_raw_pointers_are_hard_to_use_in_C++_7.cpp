#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

/*	It wouldn't been better in C++. Instead of using a signal handling
	an exception handling is also unable to release allocated memory.
*/

struct Math {
	int a;
	int b;
	int result;

	Math() {	cout << "creating a new math instance..." << endl;	}
	~Math() {	cout << "destroying math instance..." << endl;		}
	int divide(int a, int b);
};

int Math::divide(int a, int b) {
	if (b == 0) {
		invalid_argument e("Division by 0 detected.");
		throw e;
	}

	return a/b;
}

int main() {
	try {
		for(int i = 10; i >= -10; i -= 2) {
			Math *m = new Math();
			m->a = 10;
			m->b = i;

			m->result = m->divide(m->a, m->b);
			cout << m->a << " / " << m->b << " = " << m->result << endl;

			/*	Even an exception handling is in use here, this allocated memory is not going to
				release, thus a memory leak also exists here.
			*/

			delete m;
		}
	} catch(const invalid_argument &e) {
		cerr << "argument error: " << e.what() << endl;
	} catch(const exception &e) {
		cerr << "critical error: " << e.what() << endl;
	}

	return 0;
}