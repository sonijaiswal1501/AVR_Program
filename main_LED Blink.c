/*
 * LED Blink.c
 *
 * Created: 03-Apr-18 5:38:04 PM
 * Author : QAZ
 */ 
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA = DDRB = DDRC = DDRD = 0xff;		/* Making all 8 pins of Port A, B, C, D as output pins */
	
	while (1)
	{
		PORTA = PORTB = PORTC =  PORTD = 0xff;	/* Making PA,PB,PC,PD high. This will make LED ON */
		_delay_ms (100);
		PORTA = PORTB = PORTD = 0x00;			/* Making PA,P,PC,PD low. This will make LED OFF */
		_delay_ms (100);
	}
}
	