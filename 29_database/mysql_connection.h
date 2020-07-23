/**
*	How to use mysql connection in C.
*
*	@author			ITWorks4U
*/

#ifndef MYSQL_CONNECTION_H
#define MYSQL_CONNECTION_H

/*	global includes for every source file	*/
#include <mysql.h>
#include <my_global.h>

#define	LENGTH	16

/*	will hold login data for database	*/
typedef struct SLoginHolder {
	char address[LENGTH];
	char userName[LENGTH];
	char userPasswd[LENGTH];
	char databaseName[LENGTH];
	unsigned int portNumber;
	char *socket;
	unsigned long clientFlag;
}Login;

/*	data for functions below	*/
typedef enum EFunctionResult {
	SUCCESS = 0,
	FAILURE_SRC = 1,
	FAILURE_CONN = 2,
	FAILURE_QUERY = 4
}FunctionResult;

/*	function prototypes	*/
FunctionResult connectToDatabase(MYSQL *connection);
FunctionResult runSQLQuery(MYSQL *connection);

#endif
