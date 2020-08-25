#include "mbed.h"
#define SAMPLE_INTERVAL 10000
Timer tmr;
DigitalOut led(LED1);

int main() {
    tmr.start();
    while (1) {
        if (tmr.read_us() > SAMPLE_INTERVAL) {
            tmr.reset();
            led = !led;
        }
    }
}