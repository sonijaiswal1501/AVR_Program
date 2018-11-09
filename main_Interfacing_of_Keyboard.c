/*
 * Interfacing of Keyboard.c
 *
 * Created: 27-Apr-18 2:35:01 PM
 * Author : QAZ
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define Led PC0
 
int main(void)
{
		unsigned char keyCode, keyPressed, i;
		DDRA = 0xFF;		
		DDRD = 0xFF;		
		PORTD = 0x0F;		
		DDRD = 0xF0;		
		
		while (1)
		{
		  if(PIND != 0x0F)
			{	
				PORTD = 0x7F;
				DDRD = 0xF0;	
				if(PIND != 0x7F) 
				{
				  keyCode = PIND & 0x0F;
				  keyPressed = 0x70 | keyCode;				  
				}
				
				PORTD = 0xBF;
				DDRD = 0xF0;
				if(PIND != 0xBF)
				{
					keyCode = PIND & 0x0F;
					keyPressed = 0xB0 | keyCode;
				}
				
				PORTD = 0xDF;
				DDRD = 0xF0;
				if(PIND != 0xDF)
				{
					keyCode = PIND & 0x0F;
					keyPressed = 0xD0 | keyCode;
				}
				
				PORTD = 0xEF;
				DDRD = 0xF0;
				if(PIND != 0xEF)
				{
					keyCode = PIND & 0x0F;
					keyPressed = 0xE0 | keyCode;
				}
				
				PORTA = keyPressed;				
		}
	}
}
		


		


