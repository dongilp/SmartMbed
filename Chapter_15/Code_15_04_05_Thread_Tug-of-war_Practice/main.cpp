#include "mbed.h"
Mutex mutex;
Thread t2;
Thread t3;
int cnt = 0;
DigitalOut led(LED1);

void showCnt(const char* name, int ct) {
    printf("%s: %3d\n", name, ct);
}

void thread_plus(const char* name) {
    while (true) {
        mutex.lock();
        led = !led;
        showCnt((const char*)name, ++cnt);
        mutex.unlock();
        wait_us(490000);
    }
}

void thread_mius(const char* name) {
    while (true) {
        mutex.lockI();
        showCnt((const char*)name, --cnt);
        mutex.unlock();
        wait_us(1000000);
    }
}

int main() {
    t2.start(callback(&thread_plus, (const char*)"Th 2"));
    t3.start(callback(&thread_mius, (const char*)"Th 3"));
    thread_mius((const char*)"Th 1");
}