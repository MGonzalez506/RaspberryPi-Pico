//##############################################################################
/*
	*	Project:    Todos los pines configurados como salidas
	*	Title:      Todos los pines configurados como salidas
	*	Created:    06/07/2023 13:03:35
	*	Updated:    06/07/2023 13:03:35
	*   Author:    Miguel González - dev@mgonzalez506.com
    *   Version:   0.0.1
    *	Organization: ioT506.com
*/
//##############################################################################

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "pico/stdlib.h"

/* <--- OUTPUTS ---> */
uint8_t gpio_01 = 1;
uint8_t gpio_02 = 2;
uint8_t gpio_03 = 3;
uint8_t gpio_04 = 4;
uint8_t gpio_05 = 5;
uint8_t gpio_06 = 6;
uint8_t gpio_07 = 7;
uint8_t gpio_08 = 8;
uint8_t gpio_09 = 9;
uint8_t gpio_10 = 10;
uint8_t gpio_11 = 11;
uint8_t gpio_12 = 12;
uint8_t gpio_13 = 13;
uint8_t gpio_14 = 14;
uint8_t gpio_15 = 15;
uint8_t gpio_16 = 16;
uint8_t gpio_17 = 17;
uint8_t gpio_18 = 18;
uint8_t gpio_19 = 19;
uint8_t gpio_20 = 20;
uint8_t gpio_21 = 21;

int main(){
	stdio_init_all();
	sleep_ms(3000);
    // Print software version
    printf("-----------------------------------------------------------------------\n");
    printf("Todos los pines como salidas\n");
    printf("Versión: \t0.0.0\n");
	printf("Company: \tioT506.com\n");
	printf("Author: \tMiguel González - dev@mgonzalez506.com\n");
    printf("-----------------------------------------------------------------------\n");

	// Configuración de pines como salidas
	gpio_init(gpio_01);
	gpio_init(gpio_02);
	gpio_init(gpio_03);
	gpio_init(gpio_04);
	gpio_init(gpio_05);
	gpio_init(gpio_06);
	gpio_init(gpio_07);
	gpio_init(gpio_08);
	gpio_init(gpio_09);
	gpio_init(gpio_10);
	gpio_init(gpio_11);
	gpio_init(gpio_12);
	gpio_init(gpio_13);
	gpio_init(gpio_14);
	gpio_init(gpio_15);
	gpio_init(gpio_16);
	gpio_init(gpio_17);
	gpio_init(gpio_18);
	gpio_init(gpio_19);
	gpio_init(gpio_20);
	gpio_init(gpio_21);

	// Set pin direction to output
	gpio_set_dir(gpio_01, true);
	gpio_set_dir(gpio_02, true);
	gpio_set_dir(gpio_03, true);
	gpio_set_dir(gpio_04, true);
	gpio_set_dir(gpio_05, true);
	gpio_set_dir(gpio_06, true);
	gpio_set_dir(gpio_07, true);
	gpio_set_dir(gpio_08, true);
	gpio_set_dir(gpio_09, true);
	gpio_set_dir(gpio_10, true);
	gpio_set_dir(gpio_11, true);
	gpio_set_dir(gpio_12, true);
	gpio_set_dir(gpio_13, true);
	gpio_set_dir(gpio_14, true);
	gpio_set_dir(gpio_15, true);
	gpio_set_dir(gpio_16, true);
	gpio_set_dir(gpio_17, true);
	gpio_set_dir(gpio_18, true);
	gpio_set_dir(gpio_19, true);
	gpio_set_dir(gpio_20, true);
	gpio_set_dir(gpio_21, true);

	while (true){
		// All gpio high
		printf("All gpio high\n");
		gpio_put(gpio_01, 1);
		gpio_put(gpio_02, 1);
		gpio_put(gpio_03, 1);
		gpio_put(gpio_04, 1);
		gpio_put(gpio_05, 1);
		gpio_put(gpio_06, 1);
		gpio_put(gpio_07, 1);
		gpio_put(gpio_08, 1);
		gpio_put(gpio_09, 1);
		gpio_put(gpio_10, 1);
		gpio_put(gpio_11, 1);
		gpio_put(gpio_12, 1);
		gpio_put(gpio_13, 1);
		gpio_put(gpio_14, 1);
		gpio_put(gpio_15, 1);
		gpio_put(gpio_16, 1);
		gpio_put(gpio_17, 1);
		gpio_put(gpio_18, 1);
		gpio_put(gpio_19, 1);
		gpio_put(gpio_20, 1);
		gpio_put(gpio_21, 1);
		sleep_ms(3000);
		printf("All gpio low\n");
		gpio_put(gpio_01, 0);
		gpio_put(gpio_02, 0);
		gpio_put(gpio_03, 0);
		gpio_put(gpio_04, 0);
		gpio_put(gpio_05, 0);
		gpio_put(gpio_06, 0);
		gpio_put(gpio_07, 0);
		gpio_put(gpio_08, 0);
		gpio_put(gpio_09, 0);
		gpio_put(gpio_10, 0);
		gpio_put(gpio_11, 0);
		gpio_put(gpio_12, 0);
		gpio_put(gpio_13, 0);
		gpio_put(gpio_14, 0);
		gpio_put(gpio_15, 0);
		gpio_put(gpio_16, 0);
		gpio_put(gpio_17, 0);
		gpio_put(gpio_18, 0);
		gpio_put(gpio_19, 0);
		gpio_put(gpio_20, 0);
		gpio_put(gpio_21, 0);
		sleep_ms(3000);
	}

}