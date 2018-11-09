/*
 * External Interrupts.c
 *
 * Created: 01-May-18 2:31:24 PM
 * Author : QAZ
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void initInterrupt();

ISR(INT0_vect)				//Interrupt Service Routine for INT0
{
	PORTA |= 0x01;
	_delay_ms (1000);
	PORTA |= 0x00;
	_delay_ms (1000);
}
int main(void)
{
	DDRA = 0xFF;				// Configure Dataport as output
	DDRD &= ~(1<<PD2);				// Set PD2 as input (Using for interupt INT0)
	PORTD |= 1<<PD2;			// Enable PD2 pull-up resistor
		
	initInterrupt();			
	
	while(1)
	{		
	}
}
void initInterrupt()
{
	GICR  |= 1<<INT0;				 // Enable INT0
	MCUCR |= 1<<ISC01 | 1<<ISC00;	// Trigger INT0 on rising edge	
	sei();							//Enable Global Interrupt
}


