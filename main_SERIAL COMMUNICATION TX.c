/*
 * SERIAL COMMUNICATION.c
 *
 * Created: 03-May-18 3:10:03 PM
 * Author : QAZ
 */ 

#include <avr/io.h>

void UART_init(long a);
void UART_Tx(char ch);

#define F_CPU 16000000UL
#define UART_BAUDRATE 9600
#define BAUD_PRESCALE ((F_CPU / (UART_BAUDRATE * 16UL)) - 1)

int main()
{      
    UART_init(9600);
    UART_Tx('A');   
	
    while(1)
    {	    
    }
}
void UART_init(long BAUDRATE)
{
	UCSRB |= (1 << TXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	UBRRL = BAUD_PRESCALE;		
	UBRRH = (BAUD_PRESCALE >> 8);	
}

void UART_Tx(char ch)
{
	while (! (UCSRA & (1<<UDRE)));	
	UDR = ch ;
}

