#include "mbed.h"
Serial pc(USBTX, USBRX);
MemoryPool<uint32_t, 16> mpool;
Queue <uint32_t, 16> queue;
Thread thread;
Mutex uart_mutex;
DigitalOut led(LED1);
void generator(void) {
	uint32_t i = 0;
	while (true) {
		uint32_t* value = mpool.alloc();
		*value = i;
		queue.put(value);
		uart_mutex.lock();
		pc.printf("Thread: %d\n", *value);
		uart_mutex.unlock();
		wait(0.4); i++;
	}
}

int main() {
	thread.start(generator);
	uint32_t cnt = 0;
	while (true) {
		osEvent evt = queue.get(0);
		if (evt.status == osEventMessage) {
			led = !led;
			uint32_t* value = (uint32_t*)evt.value.p;
			uart_mutex.lock();
			pc.printf("Main: %d\n", *value);
			uart_mutex.unlock();
			mpool.free(value);
		}
		if (cnt % 20 == 0) {
			uart_mutex.lock();
			pc.printf("Main: waiting...\n");
			uart_mutex.unlock();
			wait(2.0);
		}
		wait(0.2);
		cnt++;
	}
}