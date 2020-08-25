#include "mbed.h"
PwmOut pwm(LED1); //LED1

int main()
{
    int count = 0;
    pwm.period_us(25); // 40kHz
    while (1)
    {
        pwm = count / 100.;
        count++;
        count %= 101;
        wait(0.1);
    }
}