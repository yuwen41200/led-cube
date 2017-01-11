#ifndef _74HC595_H
#define _74HC595_H

#define _74HC595_GPIO GPIOA
#define _74HC595_SHCP_PIN GPIO_PIN_6
#define _74HC595_STCP_PIN GPIO_PIN_7
#define _74HC595_DS_PIN GPIO_PIN_8

void _74hc595_init();
void _74hc595_send(uint8_t);

#endif
