#include "stm32l4xx.h"
#include "stm32l4xx_nucleo.h"
#include "74hc595.h"

void _74hc595_init() {
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.Pin = _74HC595_SHCP_PIN | _74HC595_STCP_PIN | _74HC595_DS_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(_74HC595_GPIO, &GPIO_InitStructure);
}

void _74hc595_cube_init() {
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.Pin = _74HC595_SHCP_PIN | _74HC595_STCP_PIN | _74HC595_DS0_PIN;
	GPIO_InitStructure.Pin |= _74HC595_DS1_PIN | _74HC595_DS2_PIN | _74HC595_DS3_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(_74HC595_GPIO, &GPIO_InitStructure);

	_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;
	_74HC595_GPIO->BRR = _74HC595_STCP_PIN;
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

void _74hc595_cube_send(led_t leds[5][5][5]) {
	for (int i = 0; i < 5; ++i) {
		// 8th bit
		if (leds[i][1][2])
			_74HC595_GPIO->BSRR = _74HC595_DS0_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS0_PIN;
		if (leds[i][3][0])
			_74HC595_GPIO->BSRR = _74HC595_DS1_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS1_PIN;
		if (leds[i][4][3])
			_74HC595_GPIO->BSRR = _74HC595_DS2_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS2_PIN;
		if (leds[i][1][3])
			_74HC595_GPIO->BSRR = _74HC595_DS3_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS3_PIN;
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;
		_74HC595_GPIO->BSRR = _74HC595_SHCP_PIN;
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;

		// 7th bit
		if (leds[i][1][1])
			_74HC595_GPIO->BSRR = _74HC595_DS0_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS0_PIN;
		if (leds[i][2][4])
			_74HC595_GPIO->BSRR = _74HC595_DS1_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS1_PIN;
		if (leds[i][4][2])
			_74HC595_GPIO->BSRR = _74HC595_DS2_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS2_PIN;
		if (leds[i][0][0])
			_74HC595_GPIO->BSRR = _74HC595_DS3_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS3_PIN;
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;
		_74HC595_GPIO->BSRR = _74HC595_SHCP_PIN;
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;

		// 6th bit
		if (leds[i][1][0])
			_74HC595_GPIO->BSRR = _74HC595_DS0_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS0_PIN;
		if (leds[i][2][3])
			_74HC595_GPIO->BSRR = _74HC595_DS1_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS1_PIN;
		if (leds[i][4][1])
			_74HC595_GPIO->BSRR = _74HC595_DS2_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS2_PIN;
		if (i == 4)
			_74HC595_GPIO->BSRR = _74HC595_DS3_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS3_PIN;
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;
		_74HC595_GPIO->BSRR = _74HC595_SHCP_PIN;
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;

		// 5th bit
		if (leds[i][0][4])
			_74HC595_GPIO->BSRR = _74HC595_DS0_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS0_PIN;
		if (leds[i][2][2])
			_74HC595_GPIO->BSRR = _74HC595_DS1_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS1_PIN;
		if (leds[i][4][0])
			_74HC595_GPIO->BSRR = _74HC595_DS2_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS2_PIN;
		if (i == 3)
			_74HC595_GPIO->BSRR = _74HC595_DS3_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS3_PIN;
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;
		_74HC595_GPIO->BSRR = _74HC595_SHCP_PIN;
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;

		// 4th bit
		if (leds[i][0][3])
			_74HC595_GPIO->BSRR = _74HC595_DS0_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS0_PIN;
		if (leds[i][2][1])
			_74HC595_GPIO->BSRR = _74HC595_DS1_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS1_PIN;
		if (leds[i][3][4])
			_74HC595_GPIO->BSRR = _74HC595_DS2_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS2_PIN;
		if (i == 2)
			_74HC595_GPIO->BSRR = _74HC595_DS3_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS3_PIN;
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;
		_74HC595_GPIO->BSRR = _74HC595_SHCP_PIN;
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;

		// 3rd bit
		if (leds[i][0][2])
			_74HC595_GPIO->BSRR = _74HC595_DS0_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS0_PIN;
		if (leds[i][2][0])
			_74HC595_GPIO->BSRR = _74HC595_DS1_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS1_PIN;
		if (leds[i][3][3])
			_74HC595_GPIO->BSRR = _74HC595_DS2_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS2_PIN;
		if (i == 1)
			_74HC595_GPIO->BSRR = _74HC595_DS3_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS3_PIN;
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;
		_74HC595_GPIO->BSRR = _74HC595_SHCP_PIN;
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;

		// 2nd bit
		if (leds[i][0][1])
			_74HC595_GPIO->BSRR = _74HC595_DS0_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS0_PIN;
		if (leds[i][1][4])
			_74HC595_GPIO->BSRR = _74HC595_DS1_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS1_PIN;
		if (leds[i][3][2])
			_74HC595_GPIO->BSRR = _74HC595_DS2_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS2_PIN;
		if (i == 0)
			_74HC595_GPIO->BSRR = _74HC595_DS3_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS3_PIN;
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;
		_74HC595_GPIO->BSRR = _74HC595_SHCP_PIN;
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;

		// 1st bit
		// don't care
		_74HC595_GPIO->BSRR = _74HC595_DS0_PIN;
		// don't care
		_74HC595_GPIO->BSRR = _74HC595_DS1_PIN;
		if (leds[i][3][1])
			_74HC595_GPIO->BSRR = _74HC595_DS2_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS2_PIN;
		if (leds[i][4][4])
			_74HC595_GPIO->BSRR = _74HC595_DS3_PIN;
		else
			_74HC595_GPIO->BRR = _74HC595_DS3_PIN;
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;
		_74HC595_GPIO->BSRR = _74HC595_SHCP_PIN;
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		_74HC595_GPIO->BRR = _74HC595_SHCP_PIN;

		// set one layer
		_74HC595_GPIO->BRR = _74HC595_STCP_PIN;
		_74HC595_GPIO->BSRR = _74HC595_STCP_PIN;
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
		_74HC595_GPIO->BRR = _74HC595_STCP_PIN;
	}
}
