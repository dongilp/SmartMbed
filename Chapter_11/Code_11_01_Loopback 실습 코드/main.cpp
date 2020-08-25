#include "mbed.h"
Serial pc(USBTX, USBRX);

int main() {
    printf("Loop back program start!\n");
    while (1) {
        if (pc.readable()) {
            pc.putc(pc.getc());
        }
        wait(0.001);
    }
}