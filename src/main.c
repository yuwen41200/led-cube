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
		// animation part 1
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
		// animation part 2
		case 10:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[0][i][j] = LED_ON;
			break;
		case 11:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[0][i][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[1][i][j] = LED_ON;
			break;
		case 12:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[1][i][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[2][i][j] = LED_ON;
			break;
		case 13:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[2][i][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[3][i][j] = LED_ON;
			break;
		case 14:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[3][i][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[4][i][j] = LED_ON;
			break;
		case 15:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[4][i][j] = LED_OFF;
			break;
		case 16:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[4][i][j] = LED_ON;
			break;
		case 17:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[4][i][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[3][i][j] = LED_ON;
			break;
		case 18:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[3][i][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[2][i][j] = LED_ON;
			break;
		case 19:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[2][i][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[1][i][j] = LED_ON;
			break;
		case 20:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[1][i][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[0][i][j] = LED_ON;
			break;
		case 21:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[0][i][j] = LED_OFF;
			break;
		case 22:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][0][j] = LED_ON;
			break;
		case 23:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][0][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][1][j] = LED_ON;
			break;
		case 24:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][1][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][2][j] = LED_ON;
			break;
		case 25:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][2][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][3][j] = LED_ON;
			break;
		case 26:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][3][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][4][j] = LED_ON;
			break;
		case 27:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][4][j] = LED_OFF;
			break;
		case 28:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][4][j] = LED_ON;
			break;
		case 29:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][4][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][3][j] = LED_ON;
			break;
		case 30:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][3][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][2][j] = LED_ON;
			break;
		case 31:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][2][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][1][j] = LED_ON;
			break;
		case 32:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][1][j] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][0][j] = LED_ON;
			break;
		case 33:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][0][j] = LED_OFF;
			break;
		case 34:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][0] = LED_ON;
			break;
		case 35:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][0] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][1] = LED_ON;
			break;
		case 36:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][1] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][2] = LED_ON;
			break;
		case 37:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][2] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][3] = LED_ON;
			break;
		case 38:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][3] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][4] = LED_ON;
			break;
		case 39:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][4] = LED_OFF;
			break;
		case 40:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][4] = LED_ON;
			break;
		case 41:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][4] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][3] = LED_ON;
			break;
		case 42:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][3] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][2] = LED_ON;
			break;
		case 43:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][2] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][1] = LED_ON;
			break;
		case 44:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][1] = LED_OFF;
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][0] = LED_ON;
			break;
		case 45:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					leds[i][j][0] = LED_OFF;
			break;
		// animation part 3
		case 46:
			for (int i = 0; i < 5; ++i) {
				leds[4][0][i] = LED_ON;
				leds[3][1][i] = LED_ON;
				leds[2][2][i] = LED_ON;
				leds[1][3][i] = LED_ON;
				leds[0][4][i] = LED_ON;
			}
			break;
		case 47:
		case 55:
			for (int i = 0; i < 5; ++i) {
				leds[4][0][i] = LED_OFF;
				leds[3][1][i] = LED_OFF;
				leds[2][2][i] = LED_OFF;
				leds[1][3][i] = LED_OFF;
				leds[0][4][i] = LED_OFF;
				leds[3][0][i] = LED_ON;
				leds[4][1][i] = LED_ON;
				leds[3][2][i] = LED_ON;
				leds[2][3][i] = LED_ON;
				leds[1][4][i] = LED_ON;
			}
			break;
		case 48:
		case 56:
			for (int i = 0; i < 5; ++i) {
				leds[3][0][i] = LED_OFF;
				leds[4][1][i] = LED_OFF;
				leds[3][2][i] = LED_OFF;
				leds[2][3][i] = LED_OFF;
				leds[1][4][i] = LED_OFF;
				leds[2][0][i] = LED_ON;
				leds[3][1][i] = LED_ON;
				leds[4][2][i] = LED_ON;
				leds[3][3][i] = LED_ON;
				leds[2][4][i] = LED_ON;
			}
			break;
		case 49:
		case 57:
			for (int i = 0; i < 5; ++i) {
				leds[2][0][i] = LED_OFF;
				leds[3][1][i] = LED_OFF;
				leds[4][2][i] = LED_OFF;
				leds[3][3][i] = LED_OFF;
				leds[2][4][i] = LED_OFF;
				leds[1][0][i] = LED_ON;
				leds[2][1][i] = LED_ON;
				leds[3][2][i] = LED_ON;
				leds[4][3][i] = LED_ON;
				leds[3][4][i] = LED_ON;
			}
			break;
		case 50:
		case 58:
			for (int i = 0; i < 5; ++i) {
				leds[1][0][i] = LED_OFF;
				leds[2][1][i] = LED_OFF;
				leds[3][2][i] = LED_OFF;
				leds[4][3][i] = LED_OFF;
				leds[3][4][i] = LED_OFF;
				leds[0][0][i] = LED_ON;
				leds[1][1][i] = LED_ON;
				leds[2][2][i] = LED_ON;
				leds[3][3][i] = LED_ON;
				leds[4][4][i] = LED_ON;
			}
			break;
		case 51:
		case 59:
			for (int i = 0; i < 5; ++i) {
				leds[0][0][i] = LED_OFF;
				leds[1][1][i] = LED_OFF;
				leds[2][2][i] = LED_OFF;
				leds[3][3][i] = LED_OFF;
				leds[4][4][i] = LED_OFF;
				leds[1][0][i] = LED_ON;
				leds[2][1][i] = LED_ON;
				leds[3][2][i] = LED_ON;
				leds[4][3][i] = LED_ON;
				leds[3][4][i] = LED_ON;
			}
			break;
		case 52:
		case 60:
			for (int i = 0; i < 5; ++i) {
				leds[1][0][i] = LED_OFF;
				leds[2][1][i] = LED_OFF;
				leds[3][2][i] = LED_OFF;
				leds[4][3][i] = LED_OFF;
				leds[3][4][i] = LED_OFF;
				leds[2][0][i] = LED_ON;
				leds[3][1][i] = LED_ON;
				leds[4][2][i] = LED_ON;
				leds[3][3][i] = LED_ON;
				leds[2][4][i] = LED_ON;
			}
			break;
		case 53:
		case 61:
			for (int i = 0; i < 5; ++i) {
				leds[2][0][i] = LED_OFF;
				leds[3][1][i] = LED_OFF;
				leds[4][2][i] = LED_OFF;
				leds[3][3][i] = LED_OFF;
				leds[2][4][i] = LED_OFF;
				leds[3][0][i] = LED_ON;
				leds[4][1][i] = LED_ON;
				leds[3][2][i] = LED_ON;
				leds[2][3][i] = LED_ON;
				leds[1][4][i] = LED_ON;
			}
			break;
		case 54:
		case 62:
			for (int i = 0; i < 5; ++i) {
				leds[3][0][i] = LED_OFF;
				leds[4][1][i] = LED_OFF;
				leds[3][2][i] = LED_OFF;
				leds[2][3][i] = LED_OFF;
				leds[1][4][i] = LED_OFF;
				leds[4][0][i] = LED_ON;
				leds[3][1][i] = LED_ON;
				leds[2][2][i] = LED_ON;
				leds[1][3][i] = LED_ON;
				leds[0][4][i] = LED_ON;
			}
			break;
		case 63:
			for (int i = 0; i < 5; ++i) {
				leds[4][0][i] = LED_OFF;
				leds[3][1][i] = LED_OFF;
				leds[2][2][i] = LED_OFF;
				leds[1][3][i] = LED_OFF;
				leds[0][4][i] = LED_OFF;
			}
			break;
		// animation part 4
		case 64:
			leds[4][1][2] = LED_ON;
			leds[4][4][1] = LED_ON;
			leds[4][3][4] = LED_ON;
			leds[0][0][3] = LED_ON;
			leds[0][2][0] = LED_ON;
			leds[0][3][2] = LED_ON;
			break;
		case 65:
			leds[4][4][1] = LED_OFF;
			leds[3][4][1] = LED_ON;
			break;
		case 66:
			leds[3][4][1] = LED_OFF;
			leds[2][4][1] = LED_ON;
			break;
		case 67:
			leds[2][4][1] = LED_OFF;
			leds[1][4][1] = LED_ON;
			break;
		case 68:
			leds[1][4][1] = LED_OFF;
			leds[0][4][1] = LED_ON;
			break;
		case 69:
			leds[0][0][3] = LED_OFF;
			leds[1][0][3] = LED_ON;
			break;
		case 70:
			leds[1][0][3] = LED_OFF;
			leds[2][0][3] = LED_ON;
			break;
		case 71:
			leds[2][0][3] = LED_OFF;
			leds[3][0][3] = LED_ON;
			break;
		case 72:
			leds[3][0][3] = LED_OFF;
			leds[4][0][3] = LED_ON;
			break;
		case 73:
			leds[4][3][4] = LED_OFF;
			leds[3][3][4] = LED_ON;
			break;
		case 74:
			leds[3][3][4] = LED_OFF;
			leds[2][3][4] = LED_ON;
			break;
		case 75:
			leds[2][3][4] = LED_OFF;
			leds[1][3][4] = LED_ON;
			break;
		case 76:
			leds[1][3][4] = LED_OFF;
			leds[0][3][4] = LED_ON;
			break;
		case 77:
			leds[0][2][0] = LED_OFF;
			leds[1][2][0] = LED_ON;
			break;
		case 78:
			leds[1][2][0] = LED_OFF;
			leds[2][2][0] = LED_ON;
			break;
		case 79:
			leds[2][2][0] = LED_OFF;
			leds[3][2][0] = LED_ON;
			break;
		case 80:
			leds[3][2][0] = LED_OFF;
			leds[4][2][0] = LED_ON;
			break;
		case 81:
			leds[4][1][2] = LED_OFF;
			leds[0][4][1] = LED_OFF;
			leds[0][3][4] = LED_OFF;
			leds[4][0][3] = LED_OFF;
			leds[4][2][0] = LED_OFF;
			leds[0][3][2] = LED_OFF;
			break;
		// animation part 5
		case 82:
		case 84:
		case 86:
		case 88:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					for (int k = 0; k < 5; ++k)
						leds[i][j][k] = LED_ON;
			break;
		case 83:
		case 85:
		case 87:
		case 89:
			for (int i = 0; i < 5; ++i)
				for (int j = 0; j < 5; ++j)
					for (int k = 0; k < 5; ++k)
						leds[i][j][k] = LED_OFF;
			break;
		}
		state = state < 89 ? state + 1 : 0;
		for (int i = 0; i < speed; ++i)
			_74hc595_cube_send(leds);
	}
}
