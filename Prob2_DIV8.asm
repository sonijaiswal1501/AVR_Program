; ******************************************************

;Prob3.2...... Divide two 8-bit data without using the DIV instructionfor AVR

; ******************************************************


.include "C:\VMLAB\include\m8def.inc"


; Define here the variables

.def  temp  =r16

; Define here Reset and interrupt vectors, if any

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
   ldi r16,4
   ldi r17,2
   ldi r18,0
   ldi r19,0

forever:

   nop
   nop       ; Infinite loop.
   nop       ; Define your main system
   nop       ; behaviour here
   inc r19
   add  r18,r17
   cp r18,r16
   breq end
   brcc imperfect	

rjmp forever

imperfect:
			dec r19

end:    nop






