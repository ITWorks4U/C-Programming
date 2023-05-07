#include "message_collector.h"
#include <stdio.h>

void print_error_message(ErrorCollector collector) {
	switch(collector) {
		case NO_ERROR:
			break;
		case FILE_NOT_FOUND:
			break;
		case NO_READ_ACCESS:
			break;
		case NO_WRITE_ACCESS:
			break;
		case MEMORY_ERROR:
			break;
		case SIMULATION_INIT_ERROR:
			puts("error: initialisation for moon landing simulator failed");
			break;
		case PLANET_INIT_ERROR:
			break;
		case ERROR_SAVE_FILE:
			break;
		default:
			break;
	}
}