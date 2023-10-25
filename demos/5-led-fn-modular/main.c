//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT &= ~ LED_RED;//changed

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}

void greenControl(int on)
{
  if (on) {
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }
}

void redControl(int on)
{
  if (on) {
    P1OUT |= LED_RED;
  } else {
    P1OUT &= ~LED_RED;
  }
}

// blink state machine
static int blinkLimitG = 5;   //  state var representing reciprocal of duty cycle
static int blinkLimitR = 5;
void blinkUpdate() // called every 1/250s to blink with duty cycle 1/blinkLimit
{
  static int blinkCountG = 0; // state var representing blink state
  static int blinkCountR = 0;
  blinkCountG ++;
  blinkCountR ++;
  if (blinkCountG >= blinkLimitG) {
    blinkCountG = 0;
    greenControl(1);
  } else
    greenControl(0);
  if(blinkCountR >= blinkLimitR){
    blinkCountR = 0;
    redControl(1);
  }else
    redControl(0);
}

void oncePerSecond() // repeatedly start bright and gradually lower duty cycle, one step/sec
{
  blinkLimitR ++;  // reduce duty cycle
  if (blinkLimitR >= 8)  // but don't let duty cycle go below 1/7.
    blinkLimitR = 0;
  blinkLimitG --;
  if(blinkLimitG <= 0)
    blinkLimitG = 8;
}

void secondUpdate()  // called every 1/250 sec to call oncePerSecond once per second
{
  static int secondCount = 0; // state variable representing repeating time 0…1s
  secondCount ++;
  if (secondCount >= 250) { // once each second
    secondCount = 0;
    oncePerSecond();
    // reversePerSecond();//add
  } }

//void timeAdvStateMachines() // called every 1/250 sec
//{
  // blinkUpdate();
  // secondUpdate();
  //}


void __interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  // handle blinking   
  // timeAdvStateMachines();
  blinkUpdate();
  secondUpdate();
} 

