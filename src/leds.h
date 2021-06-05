#include <stdint.h>

#define LED_ON 1
#define LED_OFF 0

void Leds_Create(uint16_t * direccion);

void Leds_TurnOn(int led);

void Leds_TurnOff(int led);

void Leds_TurnAllOn(void);

void Leds_TurnAllOff(void);

uint8_t Leds_GetState(int led);