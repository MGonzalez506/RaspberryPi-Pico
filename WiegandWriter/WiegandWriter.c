#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

// Connect Wiegand D0 to Raspberry Pi Pico GP4
const uint W_D0 = 4;

// Connect Wiegand D1 to Raspberry Pi Pico GP5
const uint W_D1 = 5;

// Declare the function that will send 26 bit Wiegand data
void sendWiegand26(uint32_t data);
void outwiegbit(unsigned int b); // output one Wiegand bit

// Begin main function
int main(int argc, char const *argv[]){

    gpio_init(W_D0);
    gpio_init(W_D1);

    gpio_set_dir(W_D0, GPIO_OUT);
    gpio_set_dir(W_D1, GPIO_OUT);
    // Set W_Do and W_D1 to high
    gpio_put(W_D0, 1);
    gpio_put(W_D1, 1);

	const uint LED_PIN = PICO_DEFAULT_LED_PIN;
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);
	while (true) {
		gpio_put(LED_PIN, 1);
        uint32_t card = 33;
        sendWiegand26(card);
		sleep_ms(2000);
		gpio_put(LED_PIN, 0);
		sleep_ms(5000);
	}
    
	return 0;
}

void outwiegbit(unsigned int b){
    uint sel = b == 0 ? W_D0 : W_D1;
    gpio_put(sel, 0);
    sleep_us(80);
    gpio_put(sel, 1);
    sleep_us(240);
}

void sendWiegand26(uint32_t data){
    uint32_t tmp = data;
    unsigned int p_even = 0;
    unsigned int p_odd = 1;

    for (int n = 0; n < 12; ++n){
        p_odd ^= (tmp & 1);
        tmp >>= 1;
    }

    for (int n = 12; n < 24; ++n){
        p_even ^= (tmp & 1);
        tmp >>= 1;
    }

    outwiegbit(p_even);
    for (int n = 0; n < 24; ++n){
        outwiegbit((data >> (23 - n)) & 1);
    }

    outwiegbit(p_odd);
}