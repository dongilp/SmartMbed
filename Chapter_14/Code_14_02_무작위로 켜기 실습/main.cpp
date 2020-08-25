#include "mbed.h"
#define LED_PINS 9
BusOut leds(D4, D5, D6, D7, D8, D9, D10, D11, D12);

int main() {
    leds = 0x1FF; // access all of the leds to turn them off
    while (true) {
        leds = rand(); //assign random number to leds
        wait(1);
    }
}