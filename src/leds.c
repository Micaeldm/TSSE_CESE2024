#include <stdint.h>
#include "leds.h"

#define LSB 0x0001
#define LED_OFFSET 1
#define ALL_LEDS_OFF 0X0000
static uint16_t *puerto;

uint16_t LedstoMask(int led){
  return LSB << (led-LED_OFFSET);
}
void LedsCreate(uint16_t *direccion){
  puerto=direccion;
 *puerto = ALL_LEDS_OFF ;
}

void LedsSetOn( int led){
 // *puerto=1<<5;
  *puerto |= LedstoMask(led);
}

void LedsSetOff( int led){
  //*puerto=0;
  *puerto &=~LedstoMask(led);
}