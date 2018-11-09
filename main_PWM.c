/*
 * PWM.c
 *
 * Created: 05-May-18 3:33:41 PM
 * Author : QAZ
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

double dutyCycle = 25;

int main(void)
{
    DDRB = 0xFF;
	PORTB = 0xFF;
	TCCR0 |= (1<<COM01) | (1<< WGM00) | (1<<WGM01);
	
	OCR0 = (dutyCycle/100.0)*255;
	TCCR0 |= (1<<CS10) | (1<<CS00);
	
    while (1) 
    {
		_delay_ms (10000);		
		OCR0 = (dutyCycle/100.0)*255;
		
		  		
    }
}

