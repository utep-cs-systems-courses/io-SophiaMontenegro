#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void state_advance(unsigned char currState)
{
  int secondCount = 0;
  switch (currState) {
  case 0:
    secondCount++;
    if(secondCount >= 100){
      secondCount = 0;
      P1OUT ^= LED_GREEN;
      P1OUT ^= LED_RED;//demo 3
    }
    //toggle green and red
    break;
  case 1:
 
    //blinking green
    secondCount++;
    if(secondCount >= 100){
      secondCount = 0;
      P1OUT ^= LED_GREEN;
    }
    break;
  case 2:
    //blinking red
    secondCount++;
    if(secondCount >= 100){
      secondCount = 0;
      P1OUT ^= LED_RED;
    }
    break;
  case 3:
    //random combo of both red and green
    break;
  }

  // led_changed = changed;//might need to delete the next two lines
  // led_update();
}
