#include "mbed.h"
#include "Adafruit_SSD1306.h"
#include "sonar.h"
I2C i2c(I2C_SDA, I2C_SCL);
DigitalOut myled(LED1);
Serial pc(SERIAL_TX, SERIAL_RX);
Adafruit_SSD1306_I2c Oled(i2c, D4, 0x78, 64, 128);
Sonar sonar(D5, D6); //trigger_pin, echo_pin
int main() {
    Oled.begin();
    Oled.setTextSize(1);
    Oled.printf("Distance\r\n\n");
    Oled.setTextSize(2);
    sonar.start();
    while (1) {
        Oled.printf("%7.2fcm\r", sonar.read());
        Oled.display();
        pc.printf("%7.2f cm \r\n", sonar.read());
        wait(0.1f);
    }
}