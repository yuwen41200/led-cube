#include "stm32l4xx.h"
#include "stm32l4xx_nucleo.h"
#include "74hc595.h"
#include "hcsr04.h"

led_t leds[5][5][5] = {0};
int state = 0;
float distance = 2;
int speed = 100;
int update = 0;

int main() {
	HAL_Init();
	HAL_SYSTICK_Config(12000000);
	_74hc595_cube_init();
	hcsr04_init();
	while (1) {
		if (update) {
			update = 0;
			distance = hcsr04_echo();
			speed = distance > 0 ? (int) distance * 50 : speed;
			speed = speed < 100 ? 100 : speed > 1000 ? 1000 : speed;
		}
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
		for (int i = 0; i < speed; ++i)
			_74hc595_cube_send(leds);
	}
}
