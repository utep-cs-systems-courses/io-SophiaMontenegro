#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"

char switch_state_down, switch_state_changed; /* effectively boolean */
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
  switch_state_changed = 1;

  unsigned char currState = 0;
  int switches = 0;
  switches = p2val & SWITCHES;

  if(switches & SW1){
    currState = 0;
  }
  else if(switches & SW2){
    currState = 1;
  }
  else if(switches & SW3){
    currState = 2;
  }
  else if(switches & SW4){
    currState = 3;
  }
  else{//no button pressed?
    switch_state_changed = 0;
  }
  led_update();
  // state_advance(currState);
    
  return currState;
}
