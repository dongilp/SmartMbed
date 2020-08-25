#include "mbed.h"
class Sonar {
    DigitalOut trigger;
    InterruptIn echo;
    Timer timer;
    Timeout timeout; // for 10us pulse
    Ticker ticker; // to measure every 100 ms
    int32_t pulse_begin;
    int32_t pulse_end;
    float distance;
public:
    Sonar(PinName trigger_pin, PinName echo_pin) :
        trigger(trigger_pin), echo(echo_pin) { // member initializer
        trigger = 0; distance = -1;
        echo.rise(callback(this, &Sonar::echo_rise)); // rising ISR
        echo.fall(callback(this, &Sonar::echo_fall)); // falling ISR
    }
    void start(void) {
        ticker.attach(callback(this, &Sonar::periodic_start), 0.1f);
    }
    void stop(void) {
        ticker.detach();
    }
    void periodic_start(void) { // Triggering periodically
        trigger = 1;
        timeout.attach_us(callback(this, &Sonar::trigger_off), 10);
    }
    void trigger_off(void) { // to turn off trigger if 10us passed
        trigger = 0;
    }
    void echo_rise(void) { //
        timer.reset();
        timer.start();
        pulse_begin = timer.read_us();
    }
    void echo_fall(void) {
        pulse_end = timer.read_us();
        timer.stop();
        distance = pulse_end - pulse_begin;
    }
    float read(void) {
        return distance / 58.0f;
    }
};