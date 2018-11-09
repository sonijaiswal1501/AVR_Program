; ******************************************************

;Prob 4.1.........Write a delay subroutine to give an exact delay of 10ms using Timer 1 .(Test by outputting 0x55 and 0xaa alternately on the LED's using port B).or AVR

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

	ldi r20, high(RAMEND)
	out SPH,r20
	ldi r20,low(RAMEND)
	out SPL,r20
	
	ldi r16,0x01
	out DDRD,r16

forever:

	ldi r16,0XFF
	out PORTD,r16
	call delay
	ldi r16,0x00
	out PORTD,r16
	call delay

	rjmp forever

Delay:

	ldi r20,0xFB
	out TCNT1H,r20
	ldi r20,0x1D
	out TCNT1L,r20
	ldi r20,0x00
	out TCCR1A,r20
	ldi r20,0x03
	out TCCR1B,r20
	
AGAIN:

	IN R20,TIFR
	SBRS R20,TOV1
	RJMP AGAIN
	LDI R20,0X00
	OUT TCCR1B,R20
	LDI R20,0X04
	OUT TIFR,R20
	RET






