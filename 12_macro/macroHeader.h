/**
*	Contains macros and preprocessing
*	commands.
*
*	@author			ITWorks4U
*/

#ifndef MAKRO_HEADER_H
#define MAKRO_HEADER_H

#define LENGTH 20										/*	similar to a constant			*/
#define SUPER_LONG unsigned long long					/*	can be used for an alias, too	*/

struct SData {
	SUPER_LONG userID;
	char name[LENGTH];
	char lastName[LENGTH];
	char location[LENGTH];
	/*	...	*/
};
#undef LENGTH											/*	LENGTH is no longer known		*/
#define LENGTH 35

#define CHECK_NUMBER_OF_50(X) ((X) < 50)				/*	definition of a macro function	*/

#endif
