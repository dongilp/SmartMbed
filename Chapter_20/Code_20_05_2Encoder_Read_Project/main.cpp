#include "mbed.h"
#include "QEncoder.h"
QEncoder enco1(D2, D3); // encoder1
QEncoder enco2(D4, D5); //encoder2
DigitalOut led1(LED1);
int main() {
	enco1.init(); enco2.init();
	enco1.setCount(0); enco2.setCount(0);
	while (1) {
		printf("A= %d, B= %d \n", enco1.getCount(), enco2.getCount());
		wait(0.01);
	}
}