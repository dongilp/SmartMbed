#include "mbed.h"
class Blinker {
    DigitalOut _led;
    Ticker _tick;
    void blink() {
        _led = !_led;
    }
public:
    Blinker(PinName pin) : _led(pin) {
        _led = 0;
    }
    void begin(float sec) {
        _tick.attach(callback(this, &Blinker::blink), sec);
    }
};

Blinker blink(LED1);
Blinker blink2(D7);

int main() {
	blink.begin(0.1);
	blink2.begin(1.0);
	while (true) {}
}