#include "mbed.h"
Timeout tmo;
DigitalOut led1(LED1);
DigitalOut led2(D7, 1);

void flip() {
    led2 = !led2;
}

int main() {
    tmo.attach(&flip, 10.0); // flip after 10 seconds
    while (1) {
        led1 = !led1;
        wait(0.1);
    }
}