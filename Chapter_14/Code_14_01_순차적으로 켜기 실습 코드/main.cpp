#include "mbed.h"
#define LED_PINS 9
BusOut leds(D4, D5, D6, D7, D8, D9, D10, D11, D12);

int main() {
	leds = 0x1FF; // access all of the leds to turn off
	while (true) {
		for (int i = 0; i < LED_PINS; i++) {
			leds[i] = 0; // access one by one
			wait(0.1);
			leds[i] = 1;
		}
	}
}