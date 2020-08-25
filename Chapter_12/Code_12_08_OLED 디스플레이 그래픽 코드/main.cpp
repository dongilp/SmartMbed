#include "mbed.h"
#include "Adafruit_SSD1306.h"
I2C i2c(D14, D15); // SDA, SCL
Adafruit_SSD1306_I2c myOled(i2c, D4, 0x78, 32, 128);

int main() {
	int16_t x = 0;
	float inc = 0.0f, force = 1.0f;
	i2c.frequency(400000);
	myOled.begin();
	myOled.printf("Hello World\r\n");
	myOled.display();
	while (1) {
		myOled.fillRect(0, 19, 128, 12, 0);
		myOled.drawRect(x, 20, 10, 10, 1);
		myOled.display();
		inc += 0.1f * force; x += inc;
		if (x > 118 || x < 0) { force = -force; inc = 0.0f; }
		wait(0.01);
	}
}