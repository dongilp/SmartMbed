#include "mbed.h"
Serial pc(USBTX, USBRX);
DigitalOut led(LED1);

void serialEvent() {
    if (pc.readable()) {
        pc.putc(pc.getc());
    }
}

int main() {
    printf("Loop back program start!\n");
    pc.attach(&serialEvent);
    while (1) {
        led = !led;
        wait(0.1);
    }
}