/**
*	How to use mysql connection in C.
*
*	@author			ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include "mysql_connection.h"

/*	global definitions	*/
#define	LOGIN_SRC		"loginFile.cnf"											//	the login file to use
#define	NBR_OF_WORDS	3														//	every line should hold three words only
#define	WORD_LENGTH		16														//	where the length for each word must not exeed 15 characters (+1 for '\0')
#define	NO_SOCKET		"none"													//	symbolic alias, if no socket is set
static char tmpWords[NBR_OF_WORDS][WORD_LENGTH];

/*	Connect to a database by given connenction and the loginFile.cnf	*/
FunctionResult connectToDatabase(MYSQL *connection) {
	int errCode;																//	holds an error code for function below
	FILE *src = fopen(LOGIN_SRC, "r");
	if (src == NULL) {
		errCode = errno;
		fprintf(stderr, " error code %d; ", errCode);
		perror("LOGIN_SRC");
		return FAILURE_SRC;
	}

	int res = 0;																//	only in use for fscanf() function
	int ctr = 0;																//	determine which member of struct SLogin is going to modify
	size_t strLen;																//	required for "cleaning operation"
	Login login;																//	the structure to hold data from login file

	do {
		res = fscanf(src, "%s %s %s", tmpWords[0], tmpWords[1], tmpWords[2]);
		if (res == EOF) {
			break;
		}

		strLen = strlen(tmpWords[1]);
		switch(ctr) {
			case 0:
				strncpy(login.address, tmpWords[1], strLen);					//	the current word may contain any characters left,
				login.address[strLen] = '\0';									//	thus make sure to "cut" the characters left out
				break;
			case 1:
				strncpy(login.userName, tmpWords[1], strLen);
				login.userName[strLen] = '\0';
				break;
			case 2:
				strncpy(login.userPasswd, tmpWords[1], strLen);
				login.userPasswd[strLen] = '\0';
				break;
			case 3:
				strncpy(login.databaseName, tmpWords[1], strLen);
				login.databaseName[strLen] = '\0';
				break;
			case 4:
				login.portNumber = strtol(tmpWords[1], NULL, 0);
				break;
			case 5:
				if (strcmp(tmpWords[1], NO_SOCKET) == 0) {
					login.socket = NULL;
				} else {
					login.socket = calloc(1, sizeof(char) * strLen);
					assert(login.socket != NULL);				

					strncpy(login.socket, tmpWords[1], strLen);
					login.socket[strLen] = '\0';
				}

				break;
			case 6:
				login.clientFlag = strtol(tmpWords[1], NULL, 0);
				break;
		}

		ctr++;
	} while(res != EOF);

	fclose(src);

	/*	MYSQL *mysql_real_connect(MYSQL *mysql, const char *host, const char *user, const char *passwd, const char *db,
	 *							unsigned int port, const char *unix_socket, unsigned long client_flag)
	 *
	 *	try to connect to the given mysql database, where:
	 *	mysql			:=	the MYSQL alias
	 *	host			:=	host name (e. g. IP-address);
	 *		Windows:	the client connects using a shared-memory connection, if the server has enabled shared-memory connections
	 *		UNIX/Linux: the client connects using an UNIX socket file
	 *	user			:=	the user to log in
	 *	passwd			:=	the user's password
	 *	db				:=	the database to connect to
	 *	port			:=	(OPTIONAL) the port number
	 *	unix_socket		:= 	(OPTIONAL) specifies the socket or named pipe; the host determines the type of the connection
	 *	client_flag		:=	(OPTIONAL) is usually 0, can be modified with some flags (see: https://dev.mysql.com/doc/refman/5.7/en/mysql-real-connect.html)
	*/
	if (mysql_real_connect(connection, login.address, login.userName, login.userPasswd, login.databaseName, login.portNumber, login.socket, login.clientFlag) == NULL) {
		fprintf(stderr, " error: %s\n", mysql_error(connection));
		return FAILURE_CONN;
	}

	return SUCCESS;
}

