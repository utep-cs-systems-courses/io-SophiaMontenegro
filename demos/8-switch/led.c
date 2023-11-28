#include <msp430.h>

#include "led.h"



unsigned char red_on = 0, green_on = 0;

unsigned char led_state = 0;



static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};





void led_init()

{

  P1DIR |= LEDS;// bits attached to leds are output
  P1OUT &= ~LEDS;/* leds initially off */
  led_state = 0;//starts at 0

  led_update();//not sure if i need

}
void switch_init(){
  P1REN |= SWITCHES;/* enables resistors for switches */

  P1IE |= SWITCHES;/* enable interrupts from switches */

  P1OUT |= SWITCHES;/* pull-ups for switches */

  P1DIR &= ~SWITCHES;/* set switches' bits for input */
}



void led_update()//sets leds
{
  if(led_state) {
    char ledFlags = redVal[red_on] | greenVal[green_on];
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;     // set bit for on leds
  }
}
