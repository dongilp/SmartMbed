#include "mbed.h"
#include <string>
DigitalOut led1(LED1);
Serial pc(USBTX, USBRX);
volatile bool gotPacket = false;
volatile float data[3];

void onSerialRx() {
    static char serialInBuffer[32];
    static int data_cnt = 0, buff_cnt = 0;
    if (pc.readable()) {
        char byteIn = pc.getc();
        if (byteIn == ',') {
            serialInBuffer[buff_cnt] = '\0';
            data[data_cnt++] = atof(serialInBuffer);
            buff_cnt = 0;
        }
        else if (byteIn == '\n') {
            serialInBuffer[buff_cnt] = '\0';
            data[data_cnt] = atof(serialInBuffer);
            buff_cnt = 0; data_cnt = 0;
            gotPacket = true;
        }
        else {
            serialInBuffer[buff_cnt++] = byteIn;
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