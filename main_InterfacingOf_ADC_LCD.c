

#include <avr/io.h>
#include <util/delay.h>

int  ADC_Read();
void ADC_Init();

void LCD_Clear();
void LCD_Enable();
void LCD_init();
void LCD_CMD(unsigned char a);
void LCD_write(unsigned char b);
void LCD_write_string(unsigned char *str);	

#define CMD_PORT PORTD				
#define DATA_PORT PORTB
#define RS PD2				// RS pin
#define RW PD3				// Read/Write pin
#define EN PD4				// Enable pin

int main(void)
{
	char String[5];
	unsigned int value;
	DDRD = 0xFF;				// setting the port A
	DDRB = 0XFF;				// setting the port C
	DATA_PORT = CMD_PORT =0X00;
	 
	ADC_Init();    
	LCD_init();
    LCD_CMD(0x80);						// cursor at home position 
	LCD_write_string("ADC Value:");		// call function to print string on LCD
	
    while (1) 
    {
		LCD_CMD(0x8A);					// LCD16x2 cursor position 
	    value=ADC_Read();				// Read ADC  
	    itoa(value,String,10);			// Integer to string conversion  
	    LCD_write_string(String);
		LCD_write_string("  ");	
    }
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

void ADC_Init()
{
	DDRA=0x0;				// Make ADC port as input 
	PORTA = 0xFF;
	ADCSRA = 0x87;			// Enable ADC, fr/128  
	ADMUX = 0x40;			// Vref: Avcc, ADC channel: 0 
}

int ADC_Read()
{
	unsigned int Ain,AinLow ;
	
	ADCSRA |= (1<<ADSC);			// Start conversion 
	while((ADCSRA&(1<<ADIF))==0);	// Monitor end of conversion interrupt 
	
	_delay_us(10);
	AinLow = (int)ADCL;				// Read lower byte
	Ain = (int)ADCH<<8;				//Read higher 2 bits and
	Ain = AinLow + Ain;				
	return(Ain);					// Return digital value
}


