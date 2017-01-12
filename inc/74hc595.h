#ifndef _74HC595_H
#define _74HC595_H

#define _74HC595_GPIO GPIOA
#define _74HC595_SHCP_PIN GPIO_PIN_6
#define _74HC595_STCP_PIN GPIO_PIN_7
#define _74HC595_DS_PIN GPIO_PIN_8

#define _74HC595_DS0_PIN GPIO_PIN_8
#define _74HC595_DS1_PIN GPIO_PIN_9
#define _74HC595_DS2_PIN GPIO_PIN_10
#define _74HC595_DS3_PIN GPIO_PIN_11
#define LED_ON 1;
#define LED_OFF 0;
typedef uint8_t led_t;

void _74hc595_init();
void _74hc595_send(uint8_t);
void _74hc595_cube_send(led_t[5][5][5]);

#endif
