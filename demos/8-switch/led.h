#ifndef led_included

#define led_included



#define LED_RED BIT0               // P1.0

#define LED_GREEN BIT6             // P1.6

#define LEDS (BIT0 | BIT6)

#define SW1 BIT3/* switch1 is p1.3 */

#define SWITCHES SW1/* only 1 switch on this board */


extern unsigned char red_on, green_on;

extern unsigned char led_state;



void led_init();

void switch_init();

void led_update();



#endif // included
