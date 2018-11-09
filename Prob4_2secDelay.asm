; ******************************************************

;Prob3.4..... Write a delay subroutine to give an exact delay of 2sec.(Test by outputting 0x55 and 0xaa alternately on the LED's using port B if possible ).or AVR

; ******************************************************



.include "C:\VMLAB\include\m8def.inc"



; Define here the variables

;

.def  temp  =r16



; Define here Reset and interrupt vectors, if any

;

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

   nop       ; Initialize here ports, stack pointer,
   nop       ; cleanup RAM, etc.
   nop       ;
   nop       ;
   ldi r21,LOW(RAMEND)
   out SPL,r21
   ldi r22,HIGH(RAMEND)
   out SPH,r22

forever:
   sbi DDRD, PD2;OUT PB2,r16
   rcall delay
   cbi DDRD, PD2;OUT PB2,r17
   rcall delay

rjmp forever

delay:
			ldi r19,10

loop1:
			ldi r23,255

loop2:
			ldi r24,255

loop3:
         		dec r24
		 	brne loop3
		 	dec r23
		 	brne loop2
		 	dec r19
		 	brne loop1
		 	nop
		 	nop
		 	ret



;.org 0x400

;mydata: .db "World PEACE"








