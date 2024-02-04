#ifndef MESSAGE_COLLECTOR_H
#define MESSAGE_COLLECTOR_H

/*	only ERR_INIT_GAME and ERR_REGEX are is use at the moment	*/

#define	ERR_IO_FILE		0x1
#define	ERR_IO_READ		0x2
#define	ERR_IO_WRITE	0x4
#define	ERR_INIT_GAME	0xA0
#define	ERR_INIT_PLANET	0xA1
#define	ERR_REGEX		0xB0

void print_error_message(const int err_code);

#endif