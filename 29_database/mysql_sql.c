/**
*	How to use mysql connection in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysql_connection.h"

#define	SQL_QUERY	"SELECT * from MusicLibrary"

FunctionResult runSQLQuery(MYSQL *connection) {
	/*	int mysql_query(MYSQL *mysql, const char *stmt_str)	:=	starts a query only; doesn't work to modify a table
	 *
	 *	mysql			:=	the MYSQL alias
	 *	stmt_str		:=	the statement string → must not contain the terminating semicolon ';' or \g
	 *
	 *	returning:
	 *		0, if the query was successful
	 *		otherwise values, like "CR_COMMANDS_OUT_OF_SYNC", "CR_SERVER_GONE_ERROR", "CR_SERVER_LOST" or "CR_UNKNOWN_ERROR" 
	*/
	if (mysql_query(connection, SQL_QUERY) != 0) {
		fprintf(stderr, " error: %s\n", mysql_error(connection));
		return FAILURE_QUERY;
	}

	/*	MYSQL_RES *mysql_store_result(MYSQL *mysql) :=	store result set from table and print to the console; works only,
	 *	if a mysql_query() or mysql_real_query() function returned value 0.
	 *
	 *	mysql																:=	the MYSQL alias
	 *
	 *	returning:
	 *		a set of result from given SQL query, or NULL, if any error occurred
	 *
	 *	IMPORTANT:
	 *	Whenever a mysql_store_result(MYSQL *mysql) returns not NULL, after using
	 *	the result set for any purpose the function → void mysql_free_result(MYSQL_RES *result) ←
	 *	must be called to free no more used memory.
	*/
	MYSQL_RES *result = mysql_store_result(connection);
	if (result == NULL) {
		fprintf(stderr, " error: %s\n", mysql_error(connection));
		return EXIT_FAILURE;
	}

	int i, nbrOfFields = mysql_num_fields(result);							//	returing the number of column fields
	MYSQL_ROW row;															//	the row of a result set

	/*	MYSQL_ROW mysql_fetch_row(MYSQL_RES *result)						:=	retrieves the next row of a result set
	 *
	 *	result			:=	the MYSQL_RES result
	 *
	 *	returning:
	 *		the next row of a result set ← it's not a pointer
	*/
	while ((row = mysql_fetch_row(result))) {								//	the current row
		for (i = 0; i < nbrOfFields; i++) {									//	the current column...
			switch(i) {
				case 0:														//	MUSIC_ID
					printf(" ID: %s\n", row[i]);
					break;
				case 1:														//	TITLE
					printf(" title: \"%s\"\n", row[i]);
					break;
				case 2:														//	INTERPRETER
					printf(" interpreter: %s\n", row[i]);
					break;
				case 3:														//	ALBUM
					printf(" album: %s\n", row[i] ? row[i] : "NULL");
					break;
				case 4:														//	PUBLISHED
					printf(" publishing year: %s\n", row[i]);
					break;
				case 5:														//	SONG_LENGTH
					if (strlen(row[i]) == 0) {
						printf(" \"NULL\"\n");
					} else {
						int seconds = strtol(row[i], NULL, 0);
						int minutes = 0;

						if (seconds > 60) {
							minutes = seconds / 60;
							seconds = seconds % (minutes * 60);
						}

						printf(" song length: %d minutes and %d seconds\n", minutes, seconds);
					}

					break;
			}
		}

		printf("\n");
	}

	mysql_free_result(result);												//	frees no more used memory

	return SUCCESS;
}
