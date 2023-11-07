	.arch msp430g2553
	.p2align 1, 0
	.text
	.global led_init
	.extern P1OUT


red_on:	 .byte 0
green_on: .byte 0
led_changed:	 .byte 0
	;static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};??
led_init:
	BIS.b #LEDS, P1DIR	;P!DIR |= LEDS ???
	mov.b #1, &led_changed	;led_changed = 1 do I need &
	call led_update
	
	.global led_update
led_update:	
	cmp.b #0, &led_changed 	;if(led_changed)
	jz nothing		;it should do nothing if false
	;; char ledFlags = redVal[red_on] | greenVal[green_on];??
	
	mov 0xff, r13 		;temp1 =0xff ??
	;; ??
	mov.b #0, &led_changed 	;led_changed = 0
	pop r0

nothing:
	pop r0
