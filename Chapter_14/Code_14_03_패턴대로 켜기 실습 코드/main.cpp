#include "mbed.h"
#define LED_PINS 9
#define Ndata 9
Ticker tic;
BusOut leds(D4, D5, D6, D7, D8, D9, D10, D11, D12);

uint16_t data[] = { 0b110110110, 0b101101101, 0b011011011, // red, green, blue
0b100100100, 0b001001001, 0b010010010, // yellow,cyan,magenta
0b011101110, 0b101110011, 0b110101011 }; // BGR, GRB, RGB
volatile int cnt = 0;

void colorGen() {
    leds = data[cnt];
    cnt++; cnt %= Ndata;
}

int main() {
    leds = 0x1FF; // access all of the leds to turn off
    tic.attach(&colorGen, 1.0);
    while (true) {}
}