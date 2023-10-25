	.arch msp430g2553
	.p2align 1, 0
	.text
	.global led_s
	.extern P1OUT

led_init:
	bis #64,
	
