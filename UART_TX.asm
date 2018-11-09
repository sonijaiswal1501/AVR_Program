; ******************************************************
; BASIC .ASM template file for AVR
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
;
start:
   nop       ; Initialize here ports, stack pointer,
   nop       ; cleanup RAM, etc.
   nop       ;
   nop       ;
   	LDI R16,0XFF
   	OUT DDRB,R16
   	
   	LDI R16,(1<<TXEN)
   	OUT UCSRB,R16
   	LDI R16,(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0)
   	OUT UCSRC,R16
   	LDI R16,0X33
   	OUT UBRRL ,R16
   	
  AGAIN:
  		LDI R17,'y'
  		CALL TRNSMT
  		LDI R17,'E'
  		CALL TRNSMT
  		LDI R17,'S'
  		CALL TRNSMT
  		RJMP AGAIN
  	
TRNSMT:
		SBIS UCSRA,UDRE
		RJMP TRNSMT
		OUT UDR,R17
		RET

