#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;// bits attached to leds are output
  // switch_state_changed = 1;
  led_update();
}

void led_update(){//demo 10
  char ledFlags = 0; /* by default, no LEDs on */
  
  ledFlags |= sw1Down ? LED_RED : 0;
  ledFlags |= sw2Down ? (LED_GREEN) : 0;
  ledFlags |= sw3Down ? (LED_RED | LED_GREEN) : 0;
  ledFlags |= sw4Down ? 0 :(LED_RED | LED_GREEN);

    // P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    // P1OUT |= ledFlags;         // set bits for on leds
  P1OUT &= ~LEDS; //off
  P1OUT |= ledFlags;//set bits
}
