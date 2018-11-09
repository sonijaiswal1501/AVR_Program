/*
 * LED Blink for Single Bit.c
 *
 * Created: 12-Apr-18 4:35:06 PM
 * Author : QAZ
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define LED 0

int main(void)
{
		DDRA = 0XFF;
		
		  while (1)
		  {
			PORTA = ~(1<<LED);
			_delay_ms (1000);
			PORTA |= (1<<LED);
			_delay_ms (1000);
		  }
}
