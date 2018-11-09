/*
 * LED Blink for Single Bit.c
 *
 * Created: 12-Apr-18 4:35:06 PM
 * Author : QAZ
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
		DDRA = 0xFF;
		  while (1)
		  {
			for(int i=0; i<8; i++)
			 {
			   PORTA |= (1<<i);
			   _delay_ms (10000);
			 }
			 PORTA = 0x00;
			 _delay_ms (10000);
		  }
}

