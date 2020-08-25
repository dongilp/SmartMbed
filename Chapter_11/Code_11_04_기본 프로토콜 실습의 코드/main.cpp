#include "mbed.h"
#include <string>
DigitalOut led1(LED1);
Serial pc(USBTX, USBRX);
volatile bool gotPacket = false;
volatile float data[3];

void onSerialRx() {
    static char serialInBuffer[32];
    static int serialCount = 0;
    if (pc.readable()) { // some bytes to read
        char byteIn = pc.getc();
        if (byteIn == '\n') { //end of frame
            serialInBuffer[serialCount] = 0; // to complete string
            float d0, d1, d2;
            if (sscanf(serialInBuffer, "%f,%f,%f", &d0, &d1, &d2) == 3) {
                data[0] = d0; data[1] = d1; data[2] = d2;
                gotPacket = true;
            }
            serialCount = 0; // reset the buffer
        }
        else {
            serialInBuffer[serialCount] = byteIn; // store the characters
            if (serialCount < 32) // increase the counter
                serialCount++;
        }
    }
}

int main() {
    pc.attach(&onSerialRx);
    while (true) {
        if (gotPacket) {
            gotPacket = false;
            pc.printf("data= %.3f, %.3f, %.3f\n\r", data[0], data[1], data[2]);
        }
        led1 = !led1;
        wait(0.02);
    }
}