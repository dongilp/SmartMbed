#include "mbed.h"
#include <Thread.h>
DigitalOut led1(LED1);
DigitalOut led2(D7);
Thread thread;
void led1_thread() {
	while (true) {
		led1 = !led1;
		wait(0.1);
	}
}
int main() {
	thread.start(led1_thread);
	while (true) {
		led2 = !led2;
		wait(0.5);
	}
}