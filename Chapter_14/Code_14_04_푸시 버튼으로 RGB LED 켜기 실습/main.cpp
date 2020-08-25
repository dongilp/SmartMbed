#include "mbed.h"
BusIn pbs(D14, D15);
BusOut leds(D4, D5, D6, D7, D8, D9, D10, D11, D12);
uint16_t data[] = { 0b110101011, 0b101110011, // BGR, GRB,
0b110011101, 0b111111111 }; //RBG, All Off

int main() {
    pbs.mode(PullUp);
    while (true) {
        leds = data[pbs];
    }
}