#include "stm32l4xx.h"
#include "stm32l4xx_nucleo.h"
#include "74hc595.h"
#include "hcsr04.h"

led_t leds[5][5][5] = {0};
int state = 0;

int main() {
	HAL_Init();
	_74hc595_init();
	hcsr04_init();
	while (1) {
		switch (state) {
		case 0:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[0][i][j] = LED_ON;
			break;
		case 1:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[1][i][j] = LED_ON;
			break;
		case 2:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[2][i][j] = LED_ON;
			break;
		case 3:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[3][i][j] = LED_ON;
			break;
		case 4:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[4][i][j] = LED_ON;
			break;
		case 5:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[0][i][j] = LED_OFF;
			break;
		case 6:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[1][i][j] = LED_OFF;
			break;
		case 7:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[2][i][j] = LED_OFF;
			break;
		case 8:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[3][i][j] = LED_OFF;
			break;
		case 9:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[4][i][j] = LED_OFF;
			break;
		}
		state = state < 9 ? state + 1 : 0;
		_74hc595_cube_send(leds);
		HAL_Delay(100);
	}
}
