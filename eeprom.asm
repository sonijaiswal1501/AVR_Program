; ******************************************************

;Prob7.2....Write code for accessing EEPROM.for AVR

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

 CLI

  wait:
   	SBIC EECR,EEWE
   	RJMP WAIT
   	LDI R17, 0X10
   	OUT EEARL, R17
   	LDI R17, 0X00
   	OUT EEARH, R17

  	

; Code for writing in EEPROM  	

    LDI R16, 0xB
    OUT EEDR, R16
    SBI EECR,EEMWE
    SBI EECR, EEWE



;Code for reading from EEPROM  	

   ;	SBI EECR, EERE
   ;	IN R16, EEDR
   ;	OUT PORTB, R16


SEI
FOREVER:
			RJMP FOREVER
