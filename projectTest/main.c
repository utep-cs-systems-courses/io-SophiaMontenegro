#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
//#include "buzzer.h"

//unsigned char curr_state = 0;//variables defined above main should be accessed everywhere

void main(void)
{
  configureClocks();
  switch_init();
  led_init();
  enableWDTInterrupts();
  //  buzzer_init();
  
  or_sr(0x18);  // CPU off, GIE on
}
