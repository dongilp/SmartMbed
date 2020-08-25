#include "mbed.h"
#include "Lidar.h"
DigitalOut led1(LED1);
Lidar tf(PC_6, PC_7); \\TX, RX
Serial pc(USBTX, USBRX, 230400);
int main() {
	while (true) {
		pc.printf("%5d, %5d\n", tf.getDistance(), tf.getStrength());
		wait(0.01);
	}
}