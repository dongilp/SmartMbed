#include "mbed.h"
Serial pc(USBTX, USBRX);
int main() {
	int n, m;
	while (1) {
		pc.printf("Type two integers:");
		pc.scanf("%d%d", &n, &m);
		pc.printf("\nYou typed %d and %d\n", n, m);
	}
}