#include "mbed.h"
DigitalIn but(BUTTON1);

int main()
{
    srand(time(NULL));
    while (true)
    {
        if (!but)
        {
            printf("%u \n", rand() % 6 + 1);
            wait(0.2);
        }
    }
}