; ******************************************************

;Prob3.1.... Multiply two 8-bit data without using the MUL instruction

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
   ldi r16, 0x05 ; r16 has number that has to be multiplied
   mov r17,r16    ; r17 used for repeated addition
   ldi r18,0x02   ; r18 holds how many times r16 is to be multiplied
   ldi r20, 0xFF
   ldi r21,0x00
   mov r22,r20

forever:

   nop
   nop       ; Infinite loop.
   nop       ; Define your main system
   nop       ; behaviour here
	add r16,r17  ;multiplication as a repeated addition
	add r20,r22
	brcs carry
	new: dec r18     ;dec r18 after every addition
	brne forever
	rjmp end

carry:
	inc r21
	rjmp new	

 end:
     clr r18




