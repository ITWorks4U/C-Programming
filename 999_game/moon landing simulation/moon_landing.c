#include "moon_landing.h"
#include "message_collector.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <regex.h>

//	---------------
//	static global fields
//	---------------
static SpaceShip *ship = NULL;
static const double current_time = 1.0;
static ErrorCollector collector = NO_ERROR;
static const uint_t init_fuel = 5000;
// static char input[BUFFER_SIZE];
// static regex_t regular_expression;

//	---------------
//	moon landing simulation
//	---------------

/// @brief initialisation stuff
// void init_setup(void) {
// 	regcomp(&regular_expression, REGEX_FILTER, REG_EXTENDED | REG_NOSUB);
// }

/// @brief Updating the new speed for the space ship.
/// @param fuel_amount amount of fuel for current time
void update_speed(uint_t fuel_amount) {
	if (fuel_amount > 100) {																	//	correction, if this value exceeds 100
		fuel_amount = 100;																		//	set its value to 100 instead
	}

	ship->acceleration = MOON_GRAVITY - (fuel_amount * 0.04);									//	new acceleration

	if (fuel_amount <= ship->amount_of_fuel) {													//	Do we have enough fuel left?
		ship->amount_of_fuel -= fuel_amount;													//	updating fuel left
	} else {																					//	otherwise use the fuel left
		fuel_amount = ship->amount_of_fuel;														//	from your space ship
		ship->amount_of_fuel = 0;
	}

	ship->height = calculate_height(ship->acceleration, ship->speed, ship->height);
	ship->speed = calculate_speed(ship->acceleration, ship->speed);
}

/// @brief Print current status.
/// @param elapsed_seconds elapsed amount of time in seconds
void print_status(uint_t elapsed_seconds) {
	printf(
		"\ntime: %u s\nheight: %.2lf m\nspeed: %.2lf km/h\nfuel left: %u\n\n",
		elapsed_seconds, ship->height, -1 * (ship->speed * HOUR_CONVERT), ship->amount_of_fuel
	);
}

/// @brief Print the summary, when you've reached the moon surface... or you made your own funeral. (:
void print_summary(void) {
	puts("\n***summary***\n");
	printf(
		"fuel left: %u liters\nspeed left: %.2lf km/h\nheight left: %.2lf meters\n\n",
		ship->amount_of_fuel, (-1 * ship->speed * HOUR_CONVERT), ship->height
	);

	bool on_moon_drill = (ship->height < -2.0);

	if (on_moon_drill) {
		puts("Congratulations! You've proved, that moles exists on the moon!... You're one of them!");
	} else {
		double reversed_speed = -1 * ship->speed;
		bool almost_stopped = (reversed_speed < 15.0);

		if (almost_stopped) {
			puts("Excellent!");
		} else {
			puts("Do you have a health insurance? Just asking...");
		}
	}
	
	puts("Game over.");
}

/// @brief Running the moon landing simulation. 
void moon_landing_simulation(void) {
	ship = calloc(1, sizeof(SpaceShip));
	if (ship == NULL) {
		collector = SIMULATION_INIT_ERROR;
		print_error_message(collector);
	} else {
		// init_setup();

		//	---------------
		//	random values for
		//	the current simulation
		//	---------------
		ship->amount_of_fuel = init_fuel;
		ship->height = (double) (rand() % START_HEIGHT + START_HEIGHT);
		ship->speed = (double) (-1 * (rand() % START_SPEED + 1));
		ship->acceleration = MOON_GRAVITY;

		uint_t seconds = 0;
		uint_t fuel_amount = 0;
		bool mission_failed = false;

		while(ship->height > GROUND_ZERO) {
			seconds++;
			update_speed(fuel_amount);
			print_status(seconds);

			if (ship->height <= GROUND_ZERO) {
				break;
			}

			bool fuel_left = (ship->amount_of_fuel > 0);

			if (!fuel_left) {
				puts("No more fuel left. Game over.");
				mission_failed = true;
				break;
			}

			fuel_amount = fuel_input();
		}

		if (!mission_failed) {
			print_summary();
		}

		free(ship);
	}
}

/// @brief Check, if enough fuel is left.
/// @return true, if fuel left,
///			false, otherwise
bool on_fuel_left(void) {
	return ship->amount_of_fuel > 0;
}

/// @brief		Calculating the new height depending on current values.
/// @param a	acceleration
/// @param v0	starting speed
/// @param h0 	current height
/// @return 	new calculated height
double calculate_height(double a, double v0, double h0) {
	return ((-0.5 * a) * (current_time * current_time) + (v0 * current_time) + h0);
}

/// @brief 		Calculating the new speed depending on current values.
/// @param a 	acceleration
/// @param v0 	starting speed
/// @return 	new calculated speed
double calculate_speed(double a, double v0) {
	return (-a * current_time + v0);
}

/// @brief Entering a new fuel amount. Must be within a range of 0 and 100.
/// @return the fuel input to use
uint_t fuel_input(void) {
	printf("\nHow many speed (0-100)?: ");

	/*
	 * experimental implementation by using a buffer and try to pass that
	 * trough the regular expression filter
	 *
	while(true) {
		memset(input, '\0', BUFFER_SIZE);
		fgets(input, BUFFER_SIZE, stdin);
		// clear_cache();

		for(size_t i = 0; i < BUFFER_SIZE; i++) {
			if (input[i] == '\n') {
				input[i] = '\0';
				break;
			}
		}

		if ((regexec(&regular_expression, input, 0, NULL, 0)) == 0) {
			break;
		}
	}

	return (uint_t) strtoul(input, NULL, 10);
	*/
	
	/*	it's primitive, but works better than the regular expression variant ¯\_(ツ)_/¯ */
		int result_value = -1;
		uint_t fuel_amount;
		
		do {
			result_value = scanf("%u", &fuel_amount);
			char c = '\0';

			do {
				c = getchar();
			} while(c != '\n');
		} while (result_value != 1);

		return fuel_amount;
	/**/
}

/// @brief Clear input cache.
///	@deprecated Won't work as expected.
void clear_cache(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

//	---------------
//	end of the game
//	---------------