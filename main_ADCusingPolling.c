/*
 * ADC USING POLLING.c
 *
 * Created: 07-May-18 12:36:03 PM
 * Author : QAZ
 */ 

#include <avr/io.h>


int main(void)
{
    DDRB = 0xFF;
	DDRD = 0xFF;
	DDRA = 0x00;
	PORTA = 0xFF;
	ADCSRA = 0x80;
	ADMUX = 0x40;
	
    while (1) 
    {
		ADCSRA |= (1<<ADSC);
		while((ADCSRA &(1<<ADIF))==0);	
		ADCSRA |=  (1<<ADIF);		
			PORTB = ADCL;
			PORTD = ADCH;
			
    }
}

