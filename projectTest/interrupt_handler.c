#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){

  if(P2IFG & SWITCHES){      /* did a button cause this interrupt? */

    P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */

    unsigned char state = switch_interrupt_handler();/* single handler for all switches */
    state_advance(state);
  }
}
