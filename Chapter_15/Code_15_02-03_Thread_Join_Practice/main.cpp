#include "mbed.h"
#include <Thread.h>

Thread thread;
DigitalOut led1(LED1);
DigitalOut led2(D7);
volatile bool running = true;

void blink(DigitalOut* led) {
    while (running) {
        *led = !*led;
        wait_ms(20);
    }
}

int main() {
    thread.start(callback(blink, &led1));
    led2 = 1;
    wait(5);
    running = false; // 스레드 끄기.
    thread.join();
    led2 = 0;
}