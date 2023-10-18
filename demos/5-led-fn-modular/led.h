#ifndef led_included
#define led_included
//switched :)
#define LED_RED BIT6               // P1.0
#define LED_GREEN BIT0             // P1.6
#define LEDS (BIT0 | BIT6)

void greenOn(int on);
void redOn(int on);//add

#endif // included
