#include "mbed.h"
#include "Adafruit_SSD1306.h"
I2C i2c(D14, D15); // SDA, SCL
Adafruit_SSD1306_I2c myOled(i2c, D4, 0x78, 32, 128);

int main() {
    uint16_t q = 0;
    i2c.frequency(400000);
    myOled.begin();
    myOled.printf("%ux%u \n\r\n", myOled.width(), myOled.height());
    myOled.printf("First sample\r\n");
    myOled.display();
    while (1) {
        myOled.printf("%u\r", q++);
        myOled.display();
        printf("q = %u \n", q);
        wait(1.0);
    }
}