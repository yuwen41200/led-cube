#include "stm32l4xx.h"
#include "stm32l4xx_nucleo.h"
#include "74hc595.h"

void _74hc595_init() {
	HAL_Init();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.Pin = _74HC595_SHCP_PIN | _74HC595_STCP_PIN | _74HC595_DS_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(_74HC595_GPIO, &GPIO_InitStructure);
}

void _74hc595_send(uint8_t data) {
	for (int i = 0; i < 8; ++i, data >>= 1) {
		if (data & 1)
			_74HC595_GPIO->BSRR = _74HC595_DS_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS_PIN;
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;
		_74HC595_GPIO->BSRR = _74HC595_SHCP_PIN;
	}
	_74HC595_GPIO->BRR = _74HC595_STCP_PIN;
	_74HC595_GPIO->BSRR = _74HC595_STCP_PIN;
}
