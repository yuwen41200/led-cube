#include "stm32l4xx.h"
#include "stm32l4xx_nucleo.h"
#include "74hc595.h"

int main() {
	uint8_t data = 0;
	_74hc595_init();
	while (1) {
		HAL_Delay(1000);
		_74hc595_send(data++);
	}
}
