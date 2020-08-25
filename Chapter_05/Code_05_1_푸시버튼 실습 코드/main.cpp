#include "mbed.h"
DigitalOut led(LED1);
DigitalIn but(BUTTON1);

int main() {
	while (1) {
		led = !but;
	}
}