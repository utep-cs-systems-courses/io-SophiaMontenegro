#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"

int sw1Down = 0;
int sw2Down = 0;
int sw3Down = 0;
int sw4Down = 0; /* effectively boolean */
static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;

  //update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);//if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);// if switch down, sense up */

  return p2val;
}

void
switch_init()/* setup switch */
{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE |= SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */

  switch_update_interrupt_sense();
  // switch_interrupt_handler();
  led_update();
}

unsigned char
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();  
  // switch_state_changed = 1;

  int prev1 = sw1Down;

  int prev2 = sw2Down;

  int prev3 = sw3Down;

  int prev4 = sw4Down;
  
  //check if the button has been pressed

  sw1Down = (p2val & SW1) ? 0 : 1;

  sw2Down = (p2val & SW2) ? 0 : 1;

  sw3Down = (p2val & SW3) ? 0 : 1;

  sw4Down = (p2val & SW4) ? 0 : 1;

  unsigned char currState = 0;

  if(prev1 != sw1Down && sw1Down){
    currState = 0;
  }
  else if(prev2 != sw2Down && sw2Down){
    currState = 1;
  }
  else if(prev3 != sw3Down && sw3Down){
    currState = 2;
  }
  else if(prev4 != sw4Down && sw4Down){
    currState = 3;
  }
  led_update();
  // state_advance(currState);
    
  return currState;
}
