; ******************************************************

; Prob3.3...Sort 10 numbers in ascending and descending order and store them separately without changing the original array.
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
   ldi ZL,LOW(mydata<<1)
   ldi ZH,HIGH(mydata<<1)

   ldi XL,0x60
   ldi XH,0x00
   mov YL,XL
   mov YH,XH
   ldi r22,11
   mov r23,r22
   ldi r18,0
   mov r24,r22

forever:

store:
   		lpm r16,Z+
   		st X, r16
   		inc r18
   		cpi r18, 8
   		breq next1
   		inc XL

ret1:
			dec r22
			breq sorting
			rjmp store

next1:

			ldi XL, 0x68
			ldi XH, 0x00
			rjmp ret1

sorting:	

		mov ZL,YL
      mov ZH,YH
     ldi r18, 0
     ldi r22,11

compare:

			ld r16,Z

forward:
			ld r17,Y
			cp r17,r16
			brcs swapping

swapret:
			cpi YL,0x67
			breq newY
			inc YL

ret2:
         dec r22
			breq updateZ

ret4:
			rjmp compare

updateZ:
			dec r24
			breq end
			mov r22,r24
			sub YL, r24
			cpi ZL, 0x67
			breq newZ
			inc ZL

ret3:
			rjmp ret4

newY:

			ldi YL,0x68
			rjmp ret2

newZ:

			ldi ZL,0x68
			rjmp ret3

swapping:

			st Z,r17
			st Y,r16
			rjmp swapret

mydata:

		.db 8,3,6,24,7,1,9,5,12,43,31	

end:

			nop





