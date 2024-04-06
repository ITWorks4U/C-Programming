/*
	Cleaning a buffer after reading from keyboard or any other input stream
	may reduce the amount of undefined behaviors.

	In contrast to C, C++ has a different behavior by using C-Strings.
	It MAY also work, but it's not proved everywhere.

	In C++ it's recommended to work with strings instead of C-Strings.
*/

#include <iostream>
#include <limits>
#include <cstdio>

#define MAX_LENGTH	30

using namespace std;

int main() {
	//	C++ - strings are more efficient rather that C-strings
	string word1;
	string word2;

	// char word1[MAX_LENGTH];
	// char word2[MAX_LENGTH];

	cout << "enter anything: ";

	/*
		More important by using C-Strings:

		cin:
			Read from keyboard until the enter key has been pressed.
			The whole input until the next occurrence of a space bar
			is going to store to yozr buffer. The other input left will be
			stored into the input buffer => not recommended

		inline std::istream &std::istream::getline(char *__s, std::streamsize __n) => cin.getline():
			Read from keyboard until the enter key has been pressed.
			The whole input with space(s), tab(s), ... will be stored
			into your buffer. There's no secured limitation check, if we're
			exceeding this limit. => not recommended

			By the way, don't be confused with: >>getline(cin, string)<<
			It looks similar, but it has a different effect.

		void std::ios::clear(std::ios_base::iostate __state = (std::ios_base::iostate)0) => cin.clear():
			Attempting to clear the input buffer. It MAY work...
		
		int std::istream::sync() => cin.sync():
			MAY work...

			"Typing “cin.sync()” after the “cin” statement discards all that is left in the buffer.
			Though “cin.sync()” does not work in all implementations (According to C++11 and above standards).
			" (https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/)

		cin >> ws:
			MAY work...
			after using cin >> ws, you won't see the next input attempt by a text, so you
			often don't know what to do next...

			ws := std::istream &std::ws<char, std::char_traits<char>>(std::istream &__is)
			"Typing “cin>>ws” after “cin” statement tells the compiler to ignore buffer
			and also to discard all the whitespaces before the actual content of string or character array."
			(https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/)

		std::basic_istream<char, std::char_traits<char>>::__istream_type &ignore(std::streamsize __n, int __delim) => cin.ignore():
			MAY work...
			often used to really clean the input buffer, UNLESS the maximum number of characters has NOT been exceeded
			has a similar effect like cin >> ws: you need to enter the enter key again to get to the next input attempt

			"cin.ignore(numeric_limits::max(),’\n’); ” :- Typing “cin.ignore(numeric_limits::max(),’\n’);”
			after the “cin” statement discards everything in the input stream including the newline. "
			(https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/)

		And what about while(getchar() != '\n') {}?
			In contrast to C the behavior in C++ differs. So in that case, it may also not work well.

		~~~~~~~~~~~~~~~~~~~~
		Finally, in C++ it's more efficient to work with strings instead of C-strings.
		~~~~~~~~~~~~~~~~~~~~
	*/

	// cin >> word1;
	// cin.getline(word1, MAX_LENGTH);
	// cin.clear();
	// int a = cin.sync();
	// cout << a << endl;
	// cin >> ws;
	// cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// while(getchar() != '\n') {}

	/*
		---------------
		using C++ strings instead
		---------------
	*/
	//	use getline(cin, string) instead of cin.getline(....)
	getline(cin, word1);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "again: ";
	getline(cin, word2);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout <<
		"word1: " << word1 << "| located on: " << &word1 << endl <<
		"word2: " << word2 << "| located on: " << &word2 <<
	endl;

	return 0;
}