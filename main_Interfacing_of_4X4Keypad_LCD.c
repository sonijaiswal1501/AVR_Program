/*
 * Switch and LED.c
 *
 * Created: 04-Apr-18 2:52:54 PM
 * Author : QAZ
 */ 

#include <avr/io.h>
#include<util/delay.h>

void LCD_Init();
void LCD_Enable();
void LCD_CMD(unsigned char a);
void LCD_write(unsigned char b);

#define RS PC0		// Define Register Select (data/command reg.)pin
#define RW PC1		// Define Read/Write pin
#define EN PC2		// Define Enable pin

/*unsigned char keypad[4][4] = {	{'1','2','3','A'},
								{'4','5','6','B'},
								{'7','8','9','C'},
								{'*','0','#','D'}};*/

int main(void)
{	
	unsigned char keyCode,keyValue, keyPressed, i;
	DDRA = 0xFF;				// setting the port A
	DDRC = 0XFF;				// setting the port C
	DDRD = 0xFF;
	PORTD = 0x0F;
	DDRD = 0xF0;	
	LCD_Init();							// call function to Initialization of 16X2 LCD
	   
 while(1)
    {
		if(PIND != 0x0F)
		 {	 
			 PORTD = 0x7F;
			 DDRD = 0xF0;
			 if(PIND != 0x7F)
			 {
				 keyCode = PIND & 0x0F;
				 keyValue = 0x70 | keyCode;
			 }
			 
			 PORTD = 0xBF;
			 DDRD = 0xF0;
			 if(PIND != 0xBF)
			 {
				 keyCode = PIND & 0x0F;
				 keyValue = 0xB0 | keyCode;
			 }
			 
			 PORTD = 0xDF;
			 DDRD = 0xF0;
			 if(PIND != 0xDF)
			 {
				 keyCode = PIND & 0x0F;
				 keyValue = 0xD0 | keyCode;
			 }
			 
			 PORTD = 0xEF;
			 DDRD = 0xF0;
			 if(PIND != 0xEF)
			 {
				 keyCode = PIND & 0x0F;
				 keyValue = 0xE0 | keyCode;
			 }
			  switch (keyValue)               //generating key characetr to display on LCD
			  {
				  case (0xEB): keyPressed = '0';
				  break;
				  case (0x77): keyPressed = '1';
				  break;
				  case (0x7B): keyPressed = '2';
				  break;
				  case (0x7D): keyPressed = '3';
				  break;
				  case (0xB7): keyPressed = '4';
				  break;
				  case (0xBB): keyPressed = '5';
				  break;
				  case (0xBD): keyPressed = '6';
				  break;
				  case (0xD7): keyPressed = '7';
				  break;
				  case (0xDB): keyPressed = '8';
				  break;
				  case (0xDD): keyPressed = '9';
				  break;
				  case (0x7E): keyPressed = 'A';
				  break;
				  case (0xBE): keyPressed = 'B';
				  break;
				  case (0xDE): keyPressed = 'C';
				  break;
				  case (0xEE): keyPressed = 'D';
				  break;
				  case (0xE7): keyPressed = '*';
				  break;
				  case (0xED): keyPressed = '#';
				  break;
				  default    : keyPressed = 'X';
			  }			 
			LCD_write(keyPressed);  
		 }   
	}
}
void LCD_Init()					// LCD Initialize function
{
	LCD_CMD(0x38);				// Initialization of 16X2 LCD in 8bit mode
	LCD_CMD(0x06);				// Increment Cursor(Shift cursor to right)
	LCD_CMD(0x0E);				// Cursor ON
	_delay_ms(1);
	LCD_CMD(0x01);				// Clear LCD
	_delay_ms(1500);
	LCD_CMD(0x8F);				// Force cursor to begnning to 1st line
	
}
void LCD_Enable()				// LCD enable function
{
	PORTC |= (1<<EN);			//  RS=1 Enable pulse 
	 _delay_ms(10);
	PORTC &= ~(1<<EN);			//  RS=0 Enable pulse 
}

void LCD_CMD(unsigned char a)			// LCD command function 
{
	PORTA = a;
	PORTC &= ~(1<<RS);					// RS=0 command reg	
	PORTC &= ~(1<<RW);					// RW=0 Write operation 
	LCD_Enable();
	_delay_ms(100);	
}
void LCD_write(unsigned char b)			// LCD data write function 
{
	PORTA = b;
	PORTC |= (1<<RS);					// RS=1 command reg	
	PORTC &= ~(1<<RW);					// RW=0 Write operation 
	LCD_Enable();
	_delay_ms(10);
}