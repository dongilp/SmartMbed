#include "mbed.h"
AnalogIn POT(A0);

int main()
{
    while (1)
    {
        float voltage = POT * 3.3f;
        uint16_t value = POT.read_u16();
        printf("POT Value = %u, Voltage= %f \n", value, voltage);
        wait(0.5);
    }
}