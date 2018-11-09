/*
 * SERIAL COMMUNICATION.c
 *
 * Created: 03-May-18 3:10:03 PM
 * Author : QAZ
 */ 

#include <avr/io.h>

void UART_init(long BAUDRATE);
void UART_Tx(char ch);
unsigned char UART_Rx();
void UART_SendString(char *str);

#define F_CPU 16000000UL
#define UART_BAUDRATE 9600
#define BAUD_PRESCALE ((F_CPU / (UART_BAUDRATE * 16UL)) - 1)

int main()
{    
    char c;
    UART_init(9600);
    
    UART_SendString("\n Test ");
    while(1)
    {
	    c=UART_Rx();
	    UART_Tx(c);
    }
}
void UART_init(long BAUDRATE)
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	UBRRL = BAUD_PRESCALE;		
	UBRRH = (BAUD_PRESCALE >> 8);	
}

unsigned char UART_Rx()
{
	while ((UCSRA & (1 << RXC)) == 0);
	return(UDR);			
}

void UART_Tx(char ch)
{
	while (! (UCSRA & (1<<UDRE)));	
	UDR = ch ;
}

void UART_SendString(char *str)
{
	int j=0;
	
	while (str[j]!=0)		
	{
		UART_Tx(str[j]);
		j++;
	}
}

