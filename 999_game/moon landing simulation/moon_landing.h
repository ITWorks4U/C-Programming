#ifndef MOON_LANDING_H
#define	MOON_LANDING_H

//	---------------
//	constants and new types
//	---------------
// #define	BUFFER_SIZE			4									//	max length for input buffer
#define	MOON_GRAVITY		1.634391667								//	m / s^2
#define	HOUR_CONVERT		3.6										//	3,600 m / s = 3.6 km / h
#define	GROUND_ZERO			0.0
#define	START_HEIGHT		1000
#define	START_SPEED			42
// #define	REGEX_FILTER		"^[0-9]{1,3}\\0$"					//	only a valid input between 0 and 9; 1 to 3 times followed by a null termination character
typedef unsigned int uint_t;

#include <stdbool.h>												//	to use bool type in C

//	---------------
//	data structures
//	---------------
typedef struct {
	double height;
	double speed;
	double acceleration;
	uint_t amount_of_fuel;
} SpaceShip;

//	---------------
//	functions
//	---------------
void update_speed(uint_t fuel_amount);
void print_status(uint_t elapsed_seconds);
void print_summary(void);
void moon_landing_simulation(void);
// void init_setup(void);
void clear_cache(void);

uint_t fuel_input(void);

bool on_fuel_left(void);
double calculate_height(double a, double v0, double h0);
double calculate_speed(double a, double v0);
#endif