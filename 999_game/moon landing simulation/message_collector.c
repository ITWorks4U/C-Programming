#include "message_collector.h"
#include <stdio.h>

void print_error_message(const int err_num) {
	switch(err_num) {
		case ERR_IO_FILE:
			//TODO:	implementing...
			break;
		case ERR_IO_READ:
			//TODO:	implementing...
			break;
		case ERR_IO_WRITE:
			//TODO:	implementing...
			break;
		case ERR_INIT_GAME:
			puts("error: Initialisation for moon landing simulator failed.");
			break;
		case ERR_INIT_PLANET:
			//TODO:	implementing...
			break;
		case ERR_REGEX:
			puts("error: Creating the regex object failed. Unable to continue...");
			break;
	}
}