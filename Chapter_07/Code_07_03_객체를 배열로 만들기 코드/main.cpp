#include "mbed.h"
AnalogIn adc[4] = { A0,A1,A2,A3 };

int main() {
    while (1) {
        for (int i = 0; i < 4; i++) {
            float voltage = adc[i] * 3.3f;
            printf("A%d = %5.3f V, ", i, voltage);
        }
        printf("\n"); wait(0.1);
    }
}