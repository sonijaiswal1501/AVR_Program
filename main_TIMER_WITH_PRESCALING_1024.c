/*
 * GccApplication1.c
 *
 * Created: 02-May-18 10:30:14 AM
 * Author : QAZ
 */ 

#include <avr/io.h>

#define Led PC0

int main(void)
{
	int tot_overflow;
	DDRC = 0xFF;				// connect led to pin PC0
	PORTC = 0x00;
	TCCR0 |= (1 << CS02)|(1 << CS00);		// set up timer with prescaling	= 1024 for 16MHz
	
	while(1)
	{
    	while ((TIFR & 0x01)!=0x01);
			TIFR|=(1<<TOV0);
			tot_overflow++; 
			
			if (tot_overflow >= 61)
			 {
				PORTC ^= 0xff;		  // toggles the led				
				tot_overflow = 0;   
			 }
	}
}
