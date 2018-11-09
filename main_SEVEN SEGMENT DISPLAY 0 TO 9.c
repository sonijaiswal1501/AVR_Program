/*
 * SEVEN SEGMENT DISPLAY 0 TO 9.c
 *
 * Created: 26-Apr-18 2:43:31 PM
 * Author : QAZ
 */ 

#include <avr/io.h>
#include<util/delay.h>

void seven_segment(unsigned char b);
void single_digit();

#define DISP1 PC0

int main(void)
{
    	
    DDRA = 0xFF;				// setting the port A    
    DDRC = 0XFF;	
			
    while (1) 
    {
		 single_digit();
    }
}
void seven_segment(unsigned char b)
{	
	PORTA = b;		
	_delay_ms(1000);	
}
void single_digit()
{
	PORTC &= ~(1<<PC0);	
	seven_segment(0XBF);
	_delay_ms(3000);
	seven_segment(0X86);
	_delay_ms(3000);
	seven_segment(0XDB);
	_delay_ms(3000);
	seven_segment(0XCF);
	_delay_ms(3000);
	seven_segment(0XE6);
	_delay_ms(3000);
	seven_segment(0XED);
	_delay_ms(3000);
	seven_segment(0XFD);
	_delay_ms(3000);
	seven_segment(0X87);
	_delay_ms(3000);
	seven_segment(0XFF);
	_delay_ms(3000);
	seven_segment(0XEF);
	_delay_ms(3000);	
}