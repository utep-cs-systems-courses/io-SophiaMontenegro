#include <msp430.h>
#include "libTimer.h"
#include "led.h"



int main(void){
  switch_init();
  led_init();
  configureClocks();
  enableWDTInterrupts();

  or_sr(0x18);  // CPU off, GIE on
}
