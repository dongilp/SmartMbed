#include "platform/platform.h"
#include "hal/gpio_api.h"
#include "platform/mbed_critical.h"

class DigitalOut {
public:
	DigitalOut(PinName pin) : gpio() { // 생성자
		gpio_init_out(&gpio, pin);
	}
	DigitalOut(PinName pin, int value) : gpio() { // 생성자
		gpio_init_out_ex(&gpio, pin, value);
	}
	void write(int value) {
		gpio_write(&gpio, value);
	}
	int read() {
		return gpio_read(&gpio);
	}
	DigitalOut& operator= (int value) { // = 연산자 우변 정수
		write(value);
		return *this;
	}
	DigitalOut& operator= (DigitalOut& rhs) { // = 연산자 우변 객체
		core_util_critical_section_enter();
		write(rhs.read());
		core_util_critical_section_exit();
		return *this;
	}
	operator int() { //int() 연산자
		return read();
	}
protected:
	gpio_t gpio;
};