#include "stm32l4xx.h"
#include "stm32l4xx_nucleo.h"
#include "hcsr04.h"

void hcsr04_init() {
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.Pin = HCSR04_ECHO_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	GPIO_InitStructure.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(HCSR04_GPIO, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = HCSR04_TRIGGER_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	GPIO_InitStructure.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(HCSR04_GPIO, &GPIO_InitStructure);

	HCSR04_GPIO->BRR = HCSR04_TRIGGER_PIN;
}

float hcsr04_echo() {
	HCSR04_GPIO->BRR = HCSR04_TRIGGER_PIN;
	HCSR04_GPIO->BSRR = HCSR04_TRIGGER_PIN;
	// wait 10 us
	asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
	asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
	asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
	asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
	asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
	asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
	asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
	asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
	asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
	asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
	HCSR04_GPIO->BRR = HCSR04_TRIGGER_PIN;

	int counter = 0;
	while (!(HCSR04_GPIO->IDR & HCSR04_ECHO_PIN))
		if (++counter == 1000000)
			// timeout
			return -1;

	counter = 0;
	while (HCSR04_GPIO->IDR & HCSR04_ECHO_PIN) {
		++counter;
		asm volatile("mov r0, r0; mov r0, r0; mov r0, r0; mov r0, r0;");
	}

	// distance in centimeters
	return counter * 0.0171821;
}
