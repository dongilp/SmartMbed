#include "mbed.h"
#include "VL53L0X.h"
Serial pc(USBTX, USBRX, 115200);
VL53L0X sensor(I2C_SDA, I2C_SCL, D12);
DigitalOut led(LED1);
void setPerform();
int main() {
	sensor.init();
	//sensor.setTimeout(500); // for polling
	sensor.setApplication(VL53L0X::LONG_FAST);
	sensor.startContinuous();
	while (1) {
		led = !led; // Toggle LED
		pc.printf("Range %d ", sensor.readRange());
		if (sensor.timeoutOccurred())
		{
			pc.printf("TIMEOUT !!!");
		}
		pc.printf("\n");
	}
}