	.arch msp430g2553
	.p2align 1, 0
	
	.text

	.global blinkUpdate
	.extern P1OUT
	.extern greenControl
	
blinkUpdate:
				;parameter is in r12
	mov #0, r13		;blinkCount = 0
	add #1, r13		;blinkCount++
	cmp r13, r12		;blinkCount>=blinkLimit
	jl else			;jump to else if r13 < r12

	mov #0, r13		;blinkCount = 0
	mov #1, r12
	call greenControl
	pop r0
	jmp out

else:
	mov #0, r12
	;its gonna go to out :)
out:
	call greenControl
	pop r0
	
	
