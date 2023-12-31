#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

/* Switch on P1 (S2) */

void

__interrupt_vec(PORT1_VECTOR) Port_1(){

  if (P1IFG & SWITCHES) {      /* did a button cause this interrupt? */
    
    P1IFG &= ~SWITCHES;      /* clear pending sw interrupts */
    state_advance();
    // switch_interrupt_handler();/* single handler for all switches */

  }

}
