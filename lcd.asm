; ******************************************************

; Prob 9_10.1.........Study the LCD Interface and Write a code for LCD using AVR Micro controller . for AVR

; ******************************************************


.include "C:\VMLAB\include\m8def.inc"


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

		LDI R21,HIGH(RAMEND)
  	 	OUT SPH,R21
   	LDI R21,LOW(RAMEND)
  		OUT SPL,R21
  		LDI R20,0XFF
	   OUT DDRB,R20
	   OUT DDRD,R20
	   LDI R20,0X33
	   CALL COMMAND
	   CALL DELAY_2MS
	   LDI R20,0X32
	   CALL COMMAND
	   CALL DELAY_2MS
	   LDI R20,0X28
	   CALL COMMAND
	   CALL DELAY_2MS
	   LDI R20,0X0E
	   CALL COMMAND
	   CALL DELAY_2MS
	   LDI R20,0X01
	   CALL COMMAND
	   CALL DELAY_2MS
	   LDI R20,0X06
	   CALL COMMAND
	   CALL DELAY_2MS
	   LDI R20,'H'
	   CALL DATA
	   LDI R20,'I'
	   CALL DATA
	   LDI R20,0XC0
	   CALL COMMAND
	    LDI R20,'A'
	   CALL DATA

forever:
   	rjmp forever

COMMAND:

	   MOV R19,R20
	   ANDI R19,0XF0
	   OUT PORTD,R19
	   CBI PORTB,5
	   SBI PORTB,4
	   CALL SHORTDELAY
	   CBI PORTB,4
	   CALL DELAY_100US
	   MOV R19,R20
	   SWAP  R19
	   ANDI R19,0XF0
	   OUT PORTD,R19
	   SBI PORTB,4
	   CALL SHORTDELAY
	   CBI PORTB,4
	   CALL DELAY_100US
	   RET

DATA:

		MOV R19,R20
   	ANDI R19,0XF0
   	OUT PORTD,R19
   	SBI PORTB,5
   	SBI PORTB,4
  		CALL SHORTDELAY
   	CBI PORTB,4
   	CALL DELAY_100US
   	MOV R19,R20
   	SWAP  R19
   	ANDI R19,0XF0
   	OUT PORTD,R19
   	SBI PORTB,4
   	CALL SHORTDELAY
   	CBI PORTB,4
   	CALL DELAY_100US
   	RET

SHORTDELAY:

		NOP
   	NOP
   	RET

DELAY_100US:

	   PUSH R17
   	LDI R17,60
   	D:
   	CALL SHORTDELAY
   	DEC R17
   	BRNE D
   	POP R17
   	RET

DELAY_2MS:
   	LDI R17, -250
   	OUT TCNT0,R17
   	LDI R17,0X03
   	OUT TCCR0,R17

AGAIN1:

		IN R20,TIFR
   	SBRS R20,TOV0
   	RJMP AGAIN1
   	LDI R17,0X00
   	OUT TCCR0,R17
   	LDI R17,(1<<TOV0)
   	OUT TIFR,R17
   	RET








