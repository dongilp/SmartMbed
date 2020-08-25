#include "mbed.h"
I2C i2c(I2C_SDA, I2C_SCL);

int main() {
    uint8_t count = 0;
    while (1) {
        printf("\nScanning I2C devices....\n");
        count = 0;
        for (int adr = 0; adr < 256; adr++) {
            if (i2c.read(adr, 0, 0) == 0) { //check ACK
                count++;
                printf("found @ 0x%02X \n", adr);
            }
            wait(0.005);
        }
        printf("\n Total %2d devices are found\n", count);
        wait(1.0); // 1 second
    }
}