#include <msp430.h>
#include "stateMachines.h"

void

switch_interrupt_handler()

{

  char p1val = P1IN;/* switch is in P1 */



  /* update switch interrupt sense to detect changes from current buttons */

  P1IES |= (p1val & SWITCHES);/* if switch up, sense down */

  P1IES &= (p1val | ~SWITCHES);/* if switch down, sense up */



  /* up=red, down=green */

  if (p1val & SW1) {

    P1OUT |= LED_RED;

    P1OUT &= ~LED_GREEN;

  } else {

    P1OUT |= LED_GREEN;

    P1OUT &= ~LED_RED;

  }

}





/* Switch on P1 (S2) */

void

__interrupt_vec(PORT1_VECTOR) Port_1(){

  if (P1IFG & SWITCHES) {      /* did a button cause this interrupt? */

    P1IFG &= ~SWITCHES;      /* clear pending sw interrupts */

    switch_interrupt_handler();/* single handler for all switches */

  }

}
