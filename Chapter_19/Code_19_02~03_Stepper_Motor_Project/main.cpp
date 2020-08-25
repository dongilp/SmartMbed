#include "mbed.h"
#include "DRV8825.h"
#define MOTOR_STEPS_PER_REV 400 // 모터 회전당 기본 스텝수
#define MICRO_STEP_DIV 32 // 마이크로 스텝 분할수
#define MICRO_STEP_PER_REV (MOTOR_STEPS_PER_REV*MICRO_STEP_DIV) //회전당 총마이크로스텝
#define DESIRED_STEPS_PER_SEC (1000/20) //50
#define DESIRED_MICRO_STEPS_PER_SEC (32*DESIRED_STEPS_PER_SEC) // 1600
#define SAMPLE_TIME (1000000L/DESIRED_MICRO_STEPS_PER_SEC) //625
#define MAX_STEP (MICRO_STEP_PER_REV/2) // Half revolution
Serial pc(USBTX,USBRX,115200);
InterruptIn bot(BUTTON1);
DigitalOut led(LED1);
volatile bool f_run=false;
Timer tmr;
DRV8825 stepper(D7,D6);

void botPress(){ // Stop by pressing button
    f_run=!f_run;
}

int main() {
    bot.fall(&botPress);
    tmr.start();
    while (1) {
        if (tmr.read_us() > SAMPLE_TIME) {
            tmr.reset(); // time = 0
            if (f_run) {
                stepper.scan(0, MAX_STEP);
                int32_t steps = stepper.getSteps();
                if (steps % MICRO_STEP_DIV == 0) {
                    led = !led;
                    pc.printf("step= %d\n", steps / MICRO_STEP_DIV);
                }
            }
        }
    }
}