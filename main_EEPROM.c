/*
 * EEPROM.c
 *
 * Created: 02-Aug-18 11:23:42 AM
 * Author : QAZ
 */ 

#include <avr/io.h>
#include <util/delay.h>		// Include delay header file
#include <avr/eeprom.h>		// Include AVR EEPROM header file 
#include <string.h>			// Include string header file 

void LCD_Clear();
void LCD_Enable();
void LCD_init();
void LCD_CMD(unsigned char a);
void LCD_write(unsigned char b);
void LCD_write_string(unsigned char *str);	
void EEPROM();
void EEPROM_string(unsigned char *str);

#define CMD_PORT PORTD				
#define DATA_PORT PORTB
#define RS PD2				// RS pin
#define RW PD3				// Read/Write pin
#define EN PD4				// Enable pin
char R_array[],W_array[];
int main(void)
{	
	DDRD = 0xFF;			// setting the port A
	DDRB = 0XFF;			// setting the port C
	DATA_PORT = CMD_PORT =0X00;
	
	
	
	LCD_Clear();    
	LCD_init();		
	EEPROM_string("soni");	
}
void EEPROM_string(unsigned char *str)
{
	int i=0;
	while(str[i]!='\0')								// loop will go on till the NULL character in the string
	{
		W_array[i]=str[i];                          // sending data on LCD byte by byte
		i++;
	}	
}
void EEPROM()
{
	memset(R_array,0,15);
	eeprom_busy_wait();									// Initialize LCD
	eeprom_write_block(W_array,0,strlen(W_array));		// Write W_array from EEPROM address 0
	eeprom_write_block(W_array,0,strlen(W_array));		// Write W_array from EEPROM address 0
	eeprom_read_block(R_array,0,strlen(W_array));		// Read EEPROM from address 0
	LCD_write_string(R_array);							// Print Read_array on LCD	
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

void LCD_write_string(unsigned char *str)			//store address value of the string in pointer
{
	int i=0;
	while(str[i]!='\0')								// loop will go on till the NULL character in the string
	{
		LCD_write(str[i]);                          // sending data on LCD byte by byte
		i++;
	}
}