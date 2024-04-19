#include "moon_landing.h"
#include "message_collector.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <regex.h>
#include <signal.h>

//	---------------
//	static global fields
//	---------------
static SpaceShip *ship = NULL;
static const double current_time = 1.0;
static const uint_t init_fuel = 5000;

//	---------------
//	moon landing simulation
//	---------------

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
}

/// @brief Running the moon landing simulation. 
void moon_landing_simulation(void) {
	ship = calloc(1, sizeof(SpaceShip));
	if (ship == NULL) {
		print_error_message(ERR_INIT_GAME);
	} else {

		/*	signal registration for application	*/
		signal(SIGINT, handler_function);
		signal(SIGTERM, handler_function);

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

		clean_up_the_mess();
	}
}

/// @brief Handler function for incoming singals, like CTRL + C / termination by terminal (sigkill => without -9)
/// @param signal_number	required for signal function; has no effect here
void handler_function(int signal_number) {
	puts("\nTerminating the application...");
	clean_up_the_mess();
	exit(EXIT_SUCCESS);
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
	bool on_continue = true;
	char input[BUFFER_SIZE];

	do {
		memset(input, '\0', BUFFER_SIZE);
		printf("How many speed (0-100)?: ");
		fgets(input, BUFFER_SIZE, stdin);

		/*	discards any input buffer left	*/
		while(getchar() != '\n') {}

		/*	getting rid of \n from fgets()	*/
		size_t length = strlen(input);
		input[length-1] = '\0';

		int ret = on_match(input);

		if (ret == 0) {
			on_continue = false;
		} else if(ret == -1) {
			print_error_message(ERR_REGEX);
			clean_up_the_mess();
		} else {
			puts("Input was out of range...");
		}
	} while (on_continue);

	return (uint_t) strtoul(input, NULL, 10);
}

/// @brief Checks, if the certain input passes trough the regular expression filter.
/// @param input input to check
/// @return 0 on match, 1 on not match, -1 on regcomp() error
int on_match(const char *input) {
	int result = 1;
	regex_t reg;

	if (regcomp(&reg, REGEX_FILTER, REG_EXTENDED) < 0) {
		return -1;
	}
	
	result = regexec(&reg, input, 0, NULL, 0);
	regfree(&reg);

	return result;
}

/// @brief Removing the allocated memory.
void clean_up_the_mess(void) {
	free(ship);
	ship = NULL;
	puts("Game over...");
}

//	---------------
//	end of the game
//	---------------