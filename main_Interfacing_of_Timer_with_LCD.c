/*
 * A6.3Interfacing of Timer with LCD.c
 *
 * Created: 13-Aug-18 5:50:55 PM
 * Author : QAZ
 */ 

#include <avr/io.h>
#include <util/delay.h>

void LCD_Clear();
void LCD_Enable();
void LCD_init();
void LCD_CMD(unsigned char a);
void LCD_write(unsigned char b);
void LCD_write_string(unsigned char *str);

void Timer();
void Timer_inti();
void Timer_overflow();

#define CMD_PORT PORTD
#define DATA_PORT PORTB
#define RS PD2				// RS pin
#define RW PD3				// Read/Write pin
#define EN PD4				// Enable pin

char a[], b[], c[];
int i=0, j=0, count=0;

int main(void)
{
	
	DDRB = DDRD = 0xFF;				// setting the port B, C and D
	PORTB = PORTD = 0x00;
	
	Timer_inti();
	LCD_init();
	LCD_CMD(0x80);						// cursor at home position
	LCD_write_string("Time:");		// call function to print string on LCD
	
	while(1)
	{
		Timer_overflow();
	}
}
void Timer_inti()
{
	TCCR0 |= (1 << CS02)|(1 << CS00);		// set up timer with prescaling	= 1024 for 16MHz
}
void Timer_overflow()
{
	while(1)
	{
		int tot_overflow;
		while ((TIFR & 0x01)!=0x01);
		TIFR|=(1<<TOV0);
		tot_overflow++;
		
		if (tot_overflow >= 61)
		{			
			tot_overflow = 0;
			count++;
			Timer();
		}
	}
}
void Timer()
{
	if(count>=60)			//Seconds
	{
		count=0;
		j++;
		if(j>=60)			//Minutes
		{
			count=0;
			j=0;
			i++;
			if(i>=24)		//Hours
			{
				count=0;
				j=0;
				i=0;
			}
		}
	}
	LCD_CMD(0x85);
	itoa(i,a,10);
	LCD_write_string(a);
	itoa(j,b,10);
	LCD_write(':');
	LCD_write_string(b);
	itoa(count,c,10);
	LCD_write(':');
	LCD_write_string(c);
	LCD_write(' ');
}

void LCD_Enable()
{
	CMD_PORT |= (1<<EN);
	_delay_ms(10);
	CMD_PORT &= ~(1<<EN);
	_delay_ms(10);
}

void LCD_init()
{
	LCD_CMD(0x38);				// Initialization of 16X2 LCD in 8bit mode
	LCD_CMD(0x0E);				// Cursor ON
	LCD_Clear();				// Clear LCD
	LCD_CMD(0x06);				// Increment Cursor(Shift cursor to right)
}

void LCD_CMD(unsigned char cmd)
{
	DATA_PORT = cmd;
	CMD_PORT &= ~(1<<RS);
	CMD_PORT &= ~(1<<RW);
	LCD_Enable();
	
}

void LCD_write(unsigned char data)
{
	DATA_PORT = data;
	CMD_PORT |= (1<<RS);
	CMD_PORT &= ~(1<<RW);
	LCD_Enable();
}

void LCD_Clear()
{
	LCD_CMD(0x01);				// Clear LCD
	_delay_ms(100);
}
void LCD_write_string(unsigned char *str)		//store address value of the string in pointer
{
	int i=0;
	while(str[i]!='\0')							// loop will go on till the NULL character in the string
	{
		LCD_write(str[i]);                      // sending data on LCD byte by byte
		i++;
	}
}

