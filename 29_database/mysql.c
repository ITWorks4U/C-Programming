/**
*	How to use mysql connection in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include "mysql_connection.h"

int main() {
//	printf(" mysql version: %s\n", mysql_get_client_info());			//	← just print the current mysql version

	/*	void mysql_init(MYSQL *mysql)
	 *
	 *	initializes some global variables that MySQL needs;
	 *	It also calls mysql_thread_init() for this thread.
	 *
	 *	mysql		:=	if NULL, then a new instance is going to create	
	*/
	MYSQL *connection = mysql_init(NULL);
	if (connection == NULL) {
		fprintf(stderr, " error: %s\n", mysql_error(connection));		//	prints a SQL error as string to the console for any error
		mysql_close(connection);										//	whenever an error occurred, you sould close the current connection, too
		return EXIT_FAILURE;
	}
	
	FunctionResult fcnRes;
	fcnRes = connectToDatabase(connection);								//	connect to the database
	if (fcnRes != SUCCESS) {
		mysql_close(connection);
		return EXIT_FAILURE;
	}

	fcnRes = runSQLQuery(connection);									//	run a SQL query statement
	if (fcnRes != SUCCESS) {
		mysql_close(connection);
		return EXIT_FAILURE;
	}

	/*	void mysql_close(MYSQL *mysql)
	 *
	 *	closes the connection
	*/
	mysql_close(connection);											//	closes the connection

	return EXIT_SUCCESS;
}
