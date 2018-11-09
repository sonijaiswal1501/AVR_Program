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
void LCD_write_string(unsigned char *str);
void LCD_network();
void LCD_battery();
void LCD_batterycharg();


#define RS PC0		// Define Register Select (data/command reg.)pin
#define RW PC1		// Define Read/Write pin
#define EN PC2		// Define Enable pin

int main(void)
{	
	DDRA = 0xFF;				// setting the port A
	DDRC = 0XFF;				// setting the port C
	
	LCD_Init();							// call function to Initialization of 16X2 LCD
	LCD_network();
	
 while(1)
    {	
	LCD_battery();
	
    }
    
    return 0;
}
void LCD_Init()					// LCD Initialize function
{
	LCD_CMD(0x38);				// Initialization of 16X2 LCD in 8bit mode
	LCD_CMD(0x06);				// Increment Cursor(Shift cursor to right)
	LCD_CMD(0x0E);				// Cursor ON
	_delay_ms(1);
	LCD_CMD(0x01);				// Clear LCD
	_delay_ms(1500);
	LCD_CMD(0x80);				// Force cursor to begnning to 1st line
	
}
void LCD_Enable()				// LCD enable function
{
	PORTC |= (1<<EN);			//  RS=1 Enable pulse 
	 _delay_ms(100);
	PORTC &= ~(1<<EN);			//  RS=0 Enable pulse 
}

void LCD_CMD(unsigned char a)			// LCD command function 
{
	PORTA = a;
	PORTC &= ~(1<<RS);					// RS=0 command reg	
	PORTC &= ~(1<<RW);					// RW=0 Write operation 
	LCD_Enable();
	_delay_ms(1000);	
}
void LCD_write(unsigned char b)			// LCD data write function 
{
	PORTA = b;
	PORTC |= (1<<RS);					// RS=1 command reg	
	PORTC &= ~(1<<RW);					// RW=0 Write operation 
	LCD_Enable();
	_delay_ms(1000);
}
void LCD_write_string(unsigned char *str)			//store address value of the string in pointer      
{
	int i=0;
	while(str[i]!='\0')								// loop will go on till the NULL character in the string                         
	{
		LCD_write(str[i]);                          // sending data on LCD byte by byte		
		i++;
	}	
}
void LCD_network()
{
	LCD_CMD(0x40);
	LCD_write(0x10);
	LCD_write(0x10);
	LCD_write(0x18);
	LCD_write(0x18);
	LCD_write(0x1C);
	LCD_write(0x1E);
	LCD_write(0x1E);
	LCD_write(0x1F);
	LCD_CMD(0x8F);
	LCD_write(0);
	_delay_ms(5000);		
}
void LCD_battery()
{
	LCD_CMD(0x48);
	LCD_write(0x0E);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x1F);	
	LCD_CMD(0x8E);
	LCD_write(1);
	_delay_ms(4000);
	LCD_batterycharg();	
}
void LCD_batterycharg()
{
	LCD_CMD(0x48);
	LCD_write(0x0E);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_CMD(0x8E);
	LCD_write(2);	
	LCD_CMD(0x50);
	LCD_write(0x0E);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_CMD(0x8E);
	LCD_write(3);	
	LCD_CMD(0x58);
	LCD_write(0x0E);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_CMD(0x8E);
	LCD_write(4);	
	LCD_CMD(0x60);
	LCD_write(0x0E);
	LCD_write(0x11);
	LCD_write(0x11);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_CMD(0x8E);
	LCD_write(5);	
	LCD_CMD(0x68);
	LCD_write(0x0E);
	LCD_write(0x11);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_CMD(0x8E);
	LCD_write(5);	
	LCD_CMD(0x70);
	LCD_write(0x0E);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_write(0x1F);
	LCD_CMD(0x8E);
	LCD_write(6);	
}