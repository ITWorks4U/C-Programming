#ifndef MESSAGE_COLLECTOR_H
#define MESSAGE_COLLECTOR_H

typedef enum {
	NO_ERROR = 0,
	FILE_NOT_FOUND = 1,
	NO_READ_ACCESS = 2,
	NO_WRITE_ACCESS = 4,
	MEMORY_ERROR = 8,
	SIMULATION_INIT_ERROR = 16,
	PLANET_INIT_ERROR = 32,
	ERROR_SAVE_FILE = 64
} ErrorCollector;

void print_error_message(ErrorCollector collector);

#endif