	.arch msp430g2553
	.p2align 1, 0
	.data

red_on:	 .byte 0
green_on: .byte 0
led_changed:	 .byte 0
	
redVal:	 .byte 0
	.byte LED_RED
	
greenVal:	.byte 0
	.byte LED_GREEN
	;; move redVal and greenVal into registers for index 
	.text
	.global led_init
	.extern P1OUT

led_init:
	BIS.b #LEDS, P1DIR	;P1DIR |= LEDS ???
	mov.b #1, &led_changed	;led_changed = 1 do I need &
	call led_update
	
	.global led_update
led_update:	
	cmp.b #0, &led_changed 	;if(led_changed)
	jz nothing		;it should do nothing if false
	;; char ledFlags = redVal[red_on] | greenVal[green_on];??
	call red_on
	mov.b red_on, redVal
	mov.b redVal, r13 	;r13=ledFlags?

	call green_on
	mov.b green_on, greenVal
	BIS.b greenVal, r13 	;ledFlags |= greenVal[green_on]

	mov #0xff, r14 		;temp = r14 = 0xff
	xor.b LEDS, r14		;r14 ^= LEDS
	bis.b r13, r14		;r14 |= ledFlags
	and.b r14, P1OUT	;P1OUT &= r14

	bis.b r13, P1OUT 	;P1OUT |= r13
	
	mov.b #0, &led_changed 	;led_changed = 0
	pop r0

nothing:
	pop r0
