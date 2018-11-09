/*
 * Switch and LED.c
 *
 * Created: 04-Apr-18 2:52:54 PM
 * Author : QAZ
 */ 

#include <avr/io.h>
#include<util/delay.h>

#define SW 0
#define LED 1

int main(void)
{
	DDRB = 0X02;
	PORTB =0X02;
	
    while (1) 
    {
	    if((PINB & 0X01)==0X01)
		{
		  PORTB ^= 0X02;
		  _delay_ms(1);
		}
		  
		//else
		//  PORTB = 0X00;
		 
    }
}

