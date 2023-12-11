#ifndef switches_included
#define switches_included

#define SW1 BIT0/* switch1 is p2.0 */
#define SW2 BIT1 //switch p2.1
#define SW3 BIT2 //switch p2.2
#define SW4 BIT3 //switch p2.3
#define SWITCHES (SW1 | SW2 | SW3 | SW4) //all the buttons

void switch_init();
unsigned char switch_interrupt_handler();

extern int sw1Down, sw2Down, sw3Down, sw4Down; /* effectively boolean */
extern int oddPress1, oddPress2, oddPress3, oddPress4;
#endif // included
