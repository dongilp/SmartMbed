#include "mbed.h"
DigitalOut led(LED1);
DigitalIn but(D2, PullUp);

int main() {
	while (1) {
		if (!but) {
			led = !led;
			wait(0.3);
		}
	}
}