#include "mbed.h"
#define WHO_AM_I 0x75 // register address
#define SPI_READ 0x80 // read mask
SPI spi(D11, D12, D13); // mosi, miso, sclk
//SPI spi(SPI_MOSI, SPI_MISO, SPI_SCK); // same pins
DigitalOut ss(D2);

int main() {
    ss = 1; // Chip must be deselected for general setup
    spi.format(8, 3); // 8bit data frame, SPI mode3
    spi.frequency(15000000); // 1Mhz or 15MHz
    while (true) {
        ss = 0; // select device
        spi.write(WHO_AM_I | SPI_READ); // to read slave data
        int whoami = spi.write(0); // send any byte to read
        printf("WHOAMI register = 0x%X\n", whoami);
        ss = 1; // Deselect the device
        wait(0.1);
    }
}