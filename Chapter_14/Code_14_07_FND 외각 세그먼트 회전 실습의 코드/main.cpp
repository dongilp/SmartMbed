#include "mbed.h"
BusIn pbs(D10, D11, D12, D13);
BusOut fnd(D2, D3, D4, D5, D6, D7, D8, D9);
uint16_t seg[] = { ~0x01, ~0x40, ~0x20, ~0x10, ~0x04, ~0x02 }; //BCDEFA
Timer tmr;

int main() {
    pbs.mode(PullUp);
    fnd = 0xFF; //all Off;
    tmr.start();
    uint16_t n_cnt = 0, cnt = 0, intv = 1;
    while (true) {
        if (tmr.read_us() > 1000) { //every 1ms
            tmr.reset();
            switch (pbs ^ 0x0f) {
            case 1: // PB1
                intv = 10; break;
            case 2: // PB2
                intv = 50; break;
            case 4: // PB3
                intv = 100; break;
            case 8: // PB4
                intv = 500; break;
            }
            if (cnt % intv == 0) {
                fnd = seg[n_cnt++ % 6];
            }
            cnt++;
        }
    }
}