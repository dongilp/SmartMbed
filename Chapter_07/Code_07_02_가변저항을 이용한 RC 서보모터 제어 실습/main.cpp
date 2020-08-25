#include "mbed.h"
PwmOut rcServo(D6);
AnalogIn POT(A0);

void turn(PwmOut& rc, float deg);

template <class T>
T map(T x, T in_min, T in_max, T out_min, T out_max);

int main() {
    float ang = 0., inc = 0.1;
    rcServo.period_ms(10); // 주기 10ms
    turn(rcServo, 0);
    while (1) {
        inc = 2.0f * POT - 1.0f; // [0,1] => [-1,1]
        ang += inc;
        if (ang > 180.0f) ang = 180.0f; //회전범위 제한
        else if (ang < 0.0f) ang = 0.0f;
        turn(rcServo, ang);
        wait_ms(10);
    }
}

void turn(PwmOut& rc, float deg) {
    uint16_t pulseW = map<float>(deg, 0., 180., 600., 2400.);
    rc.pulsewidth_us(pulseW);
}

template <class T>
T map(T x, T in_min, T in_max, T out_min, T out_max) {
    return (x - in_min) * (out_max - out_min)
        / (in_max - in_min) + out_min;
}