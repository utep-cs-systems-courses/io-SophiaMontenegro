#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggle_red(char state)
{
  
  switch (state) {

  case 0:
    red_on = 0;
    state = 1;
    break;

  case 1:
    red_on = 0;
    state = 2;
    break;

  case 2:
    red_on = 1;
    state = 1;
    break;
  }

  return state; 

}



char toggle_green(char state)
{
  switch (state) {

  case 0:
    green_on = 0;
    state = 1;
    break;

  case 1:
    green_on = 1;
    state = 2;
    break;

  case 2:
    green_on = 0;
    state = 1;
    break;
  }
  return state;

}

void state_advance()/* alternate between toggling red & green */
{
  char state = 0;

  static enum {R=0, G=1} color = G;

  switch (led_state) {

  case 0: state = toggle_green(led_state); color = R; break;

  case 1: state = toggle_red(led_state); color = G; break;

  case 2: state = toggle_green(led_state); color = R; break;
  }
  
  led_state = state;
  led_update();
}
