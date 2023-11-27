#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

// Declare the default LED pin
const uint LED_PIN = 25;

// Connect Wiegand D0 to Raspberry Pi Pico GP6 to read Wiegand data
const uint W_D0 = 6;

// Connect Wiegand D1 to Raspberry Pi Pico GP7 to read Wiegand data
const uint W_D1 = 7;

#define MAX_BITS 100                 // max number of bits 
#define WEIGAND_WAIT_TIME  3000      // time to wait for another weigand pulse.  

unsigned char databits[MAX_BITS];    // stores all of the data bits
unsigned char bitCount;              // number of bits currently captured
unsigned char flagDone;              // goes low when data is currently being captured
unsigned int weigand_counter;        // countdown until we assume there are no more bits

unsigned long facilityCode = 0;      // decoded facility code
unsigned long cardCode = 0;          // decoded card code

void ISR_INT0();
void ISR_INT1();
void printBits();

// interrupt that happens when INTO goes low (0 bit)
void ISR_INT0()
{
	//printf("0");
	bitCount++;
	flagDone = 0;
	weigand_counter = WEIGAND_WAIT_TIME;

}

// interrupt that happens when INT1 goes low (1 bit)
void ISR_INT1()
{
	//printf("1");
	databits[bitCount] = 1;
	bitCount++;
	flagDone = 0;
	weigand_counter = WEIGAND_WAIT_TIME;
}

// Begin main function
int main(int argc, char const *argv[]){
	stdio_init_all();

	gpio_init(LED_PIN);
	gpio_init(W_D0);
	gpio_init(W_D1);

	gpio_set_dir(LED_PIN, GPIO_OUT);
	// Declare W_D0 as input
	gpio_set_dir(W_D0, GPIO_IN);
	// Declare W_D1 as input
	gpio_set_dir(W_D1, GPIO_IN);

	// Set W_Do and W_D1 to high
	gpio_put(LED_PIN, 1);

	sleep_ms(10000);
	printf("Iniciando...\n");

	// Connect interrupt on falling edge of W_D0
	gpio_set_irq_enabled_with_callback(W_D0, GPIO_IRQ_EDGE_FALL, true, &ISR_INT0);
	// Connect interrupt on falling edge of W_D1
	gpio_set_irq_enabled_with_callback(W_D1, GPIO_IRQ_EDGE_FALL, true, &ISR_INT1);

	weigand_counter = WEIGAND_WAIT_TIME;

	while (true) {
		if (!flagDone) {
			if (--weigand_counter == 0) flagDone = 1;
		}

		// if we have bits and we the weigand counter went out
		if (bitCount > 0 && flagDone) {
			unsigned char i;

			printf("\n\nRead ");
			printf("%d", bitCount);
			printf(" bits: ");

			// we will decode the bits differently depending on how many bits we have
			// see www.pagemac.com/azure/data_formats.php for mor info
			if (bitCount == 35)
			{
			// 35 bit HID Corporate 1000 format
			// facility code = bits 2 to 14
			for (i = 2; i < 14; i++)
			{
				facilityCode <<= 1;
				facilityCode |= databits[i];
			}

			// card code = bits 15 to 34
			for (i = 14; i < 34; i++)
			{
				cardCode <<= 1;
				cardCode |= databits[i];
			}

			printBits();
			}
			else if (bitCount == 26)
			{
			// standard 26 bit format
			// facility code = bits 2 to 9
			for (i = 1; i < 9; i++)
			{
				facilityCode <<= 1;
				facilityCode |= databits[i];
			}

			// card code = bits 10 to 23
			for (i = 9; i < 25; i++)
			{
				cardCode <<= 1;
				cardCode |= databits[i];
			}

			printBits();
			}
			else if (bitCount == 36){
			// 35 bit HID Corporate 1000 format
			// facility code = bits 2 to 14
			for (i = 2; i < 14; i++)
			{
				facilityCode <<= 1;
				facilityCode |= databits[i];
			}

			// card code = bits 15 to 34
			for (i = 14; i < 34; i++)
			{
				cardCode <<= 1;
				cardCode |= databits[i];
			}

			printBits();
			}
			else if (bitCount == 50){
			// facility code = bits 6 to 17
			for (i = 5; i < 17; i++){
				facilityCode <<=1;
				facilityCode |= databits[i];
			}
			
			// card code = bits 18 to 49
			for (i = 17; i < 49; i++){
				cardCode <<=1;
				cardCode |= databits[i];
			}

			printBits();
			}
			else if (bitCount == 51) {
			// facility code = bits 6 to 17
			for (i = 5; i < 17; i++){
				facilityCode <<=1;
				facilityCode |= databits[i];
			}

			// card code = bits 19 to 50
			for (i = 18; i < 50; i++){
				cardCode <<=1;
				cardCode |= databits[i];
			}

			printBits();

			for (int x = 0; x < bitCount; x++) {
				printf("%d", databits[x]);
			}
			}
			else if (bitCount == 54) {
			unsigned char databits2[MAX_BITS];
			for (int x = 0; x < MAX_BITS; x++) databits2[x] = 0;
			for (int x = 1; x < bitCount - 1; x++) {
				databits2[x - 1] = databits[x];
			}
			for (int x = 0; x < bitCount - 1; x++) {
				printf("%d", databits2[x]);
			}
			}
			else {
			// you can add other formats if you want!
			printf("\nUnknown format. ");
			for (int x = 0; x < bitCount; x++) {
				printf("%d", databits[x]);
			}
			}

			// cleanup and get ready for the next card
			bitCount = 0;
			facilityCode = 0;
			cardCode = 0;
			for (i = 0; i < MAX_BITS; i++)
			{
			databits[i] = 0;
			}
		}
	}
	
	return 0;
}

void printBits()
{
  // I really hope you can figure out what this function does
  printf("\n\n-----------------------");
  printf("FC = ");
  printf("%d", facilityCode);
  printf(", CC = ");
  printf("%d", cardCode);
  printf("\n-----------------------\n\n\n");
}