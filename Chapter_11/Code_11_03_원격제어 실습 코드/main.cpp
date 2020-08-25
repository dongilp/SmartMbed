#include "mbed.h"
InterruptIn btn(BUTTON1);
DigitalOut led(LED1);
Serial pc(USBTX, USBRX);
volatile char c = '\0'; // NULL character
volatile bool pressed = false;

void onReceived() {
    c = pc.getc();
}

void onPressed() {
    pressed = true;
}

int main() {
    pc.attach(&onReceived);
    btn.fall(&onPressed);
    while (true) {
        if (c == '1') {
            c = '\0'; //on one time
            led = 1;
        }
        else if (c == '0') {
            c = '\0'; //on one time
            led = 0;
        }
        if (pressed) {
            pc.putc('b');
            pressed = false; // send one time
        }
    }
}