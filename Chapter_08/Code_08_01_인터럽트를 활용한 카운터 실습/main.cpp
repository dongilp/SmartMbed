#include "mbed.h"
DigitalOut led1(LED1);
DigitalOut led2(D7);
InterruptIn btn(BUTTON1);

void flip() {
    led2 = !led2;
}

int main() {
    btn.fall(&flip);
    while (true) {
        led1 = !led1;
        wait_ms(500);
    }
}