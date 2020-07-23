/**
*	Create a ramdom word.
*
*	@author			ITWorks4U
*/

#ifndef RANDOM_H
#define RANDOM_H
#define NATURAL const unsigned int

#define LINUX __unix__
#define WINDOWS __MDSOS__ || __WIN32__ || __WIN64__

const char *generateRandomWord(NATURAL length);

#endif
