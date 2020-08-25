#include "mbed.h"
DigitalOut led(LED1);

int main() {
	srand(time(NULL));
	while (true) {
		float v = (float)rand() / RAND_MAX;
		led = (v < 0.1f) ? 1 : 0;
		wait(0.01);
	}
}