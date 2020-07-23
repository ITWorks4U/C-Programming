all:				mysql.a
					gcc -g -Wall -o mysql.run mysql.a `mysql_config --cflags --libs`
					rm mysql.a

mysql.a:			mysql.o mysql_connection.o mysql_sql.o
					ar -cr mysql.a mysql.o mysql_connection.o mysql_sql.o
					rm *.o

mysql.o:			mysql.c mysql_connection.h
					gcc -c mysql.c `mysql_config --cflags --libs`

mysql_connection.o:	mysql_connection.c mysql_connection.h
					gcc -c  mysql_connection.c `mysql_config --cflags --libs`

mysql_sql.o:		mysql_sql.c mysql_connection.h
					gcc -c mysql_sql.c `mysql_config --cflags --libs`

clean:
					rm mysql.run
					
