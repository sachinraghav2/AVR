; ******************************************************

;Prob4.3....Design & Write a code to generate Maximum delay using Timer/Counter1.

; ******************************************************



.include "C:\VMLAB\include\m8def.inc"



reset:

   rjmp start
   reti      ; Addr $01
   reti      ; Addr $02
   reti      ; Addr $03
   reti      ; Addr $04
   reti      ; Addr $05
   reti      ; Addr $06        Use 'rjmp myVector'
   reti      ; Addr $07        to define a interrupt vector
   reti      ; Addr $08
   reti      ; Addr $09
   reti      ; Addr $0A
   reti      ; Addr $0B        This is just an example
   reti      ; Addr $0C        Not all MCUs have the same
   reti      ; Addr $0D        number of interrupt vectors
   reti      ; Addr $0E
   reti      ; Addr $0F
   reti      ; Addr $10

; Program starts here after Reset

start:

	LDI R16,HIGH(RAMEND)
	OUT SPH,R16
	LDI R16,LOW(RAMEND)
	OUT SPL,R16
	SBI DDRD,5
	

FOREVER :

	LDI R21,0X20
	OUT PORTD,R21
	CALL DELAY
	LDI R21,0X00
	OUT PORTD,R21
	call DELAY
	RJMP FOREVER


DELAY:

	LDI R20,0X00
	OUT TCNT1H,R20
	LDI R20,0X00
	OUT TCNT1L,R20
	LDI R20,0X00
	OUT TCCR1A,R20
	LDI R20,0X01
	OUT TCCR1B,R20

AGAIN:

	IN R20,TIFR
	SBRS R20,TOV1
	RJMP AGAIN
	LDI R20,0X00
	OUT TCCR1B,R20
	LDI R20,(1<<TOV1)
	OUT TIFR,R20
	RET









