#ifndef _HCSR04_H
#define _HCSR04_H

#define HCSR04_GPIO GPIOB
#define HCSR04_ECHO_PIN GPIO_PIN_6
#define HCSR04_TRIGGER_PIN GPIO_PIN_8

void hcsr04_init();
float hcsr04_echo();

#endif
