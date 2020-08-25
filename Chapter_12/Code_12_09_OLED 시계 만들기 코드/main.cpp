#include "mbed.h"
#include "Adafruit_SSD1306.h"
#define REG_SEC (0x02) // sec Register
#define REG_MIN (0x03) // min Register
#define REG_HOUR (0x04) // hour Register
#define PCF8563_ADDR (0xA2) //PCF8563 i2c address

I2C i2c(I2C_SDA, I2C_SCL);
DigitalOut myled(LED1);
void writeByte(uint8_t address, uint8_t subAddress, uint8_t data);
char readByte(uint8_t address, uint8_t subAddress);
uint8_t bcdToDec(uint8_t val);
uint8_t decToBcd(uint8_t val);
Adafruit_SSD1306_I2c Oled(i2c, D4, 0x78, 32, 128);

int main() {
	Oled.begin();
	Oled.setTextSize(1);
	Oled.printf("15/JUN/2019\r\n\n"); // for Test
	Oled.setTextSize(2);
	while (1) {
		char s = readByte(PCF8563_ADDR, REG_SEC);
		char m = readByte(PCF8563_ADDR, REG_MIN);
		char h = readByte(PCF8563_ADDR, REG_HOUR);
		Oled.printf("%02u:%02u:%02u\r", bcdToDec(h & 0x3F),
			bcdToDec(m & 0x7F), bcdToDec(s & 0x7F));
		Oled.display();
	}
}

void writeByte(uint8_t address, uint8_t regAddress, uint8_t data) {
	char data_write[2];
	data_write[0] = regAddress;
	data_write[1] = data;
	i2c.write(address, data_write, 2, 0);
}

char readByte(uint8_t address, uint8_t regAddress) {
	char data[1]; // 'data' will store the register data
	char data_write[1]; // for assigning register address
	data_write[0] = regAddress;
	i2c.write(address, data_write, 1, 1); // no stop
	i2c.read(address, data, 1, 0);
	return data[0];
}

uint8_t bcdToDec(uint8_t val) {
	return ((val / 16) * 10 + (val % 16));
}
uint8_t decToBcd(uint8_t val) {
	return ((val / 10 * 16) + (val % 10));
}