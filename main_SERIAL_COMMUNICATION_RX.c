/*
 * SERIAL COMMUNICATION.c
 *
 * Created: 03-May-18 3:10:03 PM
 * Author : QAZ
 */ 

#include <avr/io.h>

void UART_init(long BAUDRATE);
unsigned char UART_Rx();


#define F_CPU 16000000UL
#define UART_BAUDRATE 9600
#define BAUD_PRESCALE ((F_CPU / (UART_BAUDRATE * 16UL)) - 1)

int main()
{    
    char ch;
	DDRA = 0xFF;
	PORTA = 0x00;
	
    UART_init(9600);    
   
    while(1)
    {
	    ch=UART_Rx();
		if (ch=='1')
			PORTA = 0XFF;
		else
			PORTA = 0x00;	   
    }
}
void UART_init(long BAUDRATE)
{
	UCSRB |= (1 << RXEN) ;
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	UBRRL = BAUD_PRESCALE;		
	UBRRH = (BAUD_PRESCALE >> 8);	
}

unsigned char UART_Rx()
{
	while ((UCSRA & (1 << RXC)) == 0);
	return(UDR);			
}






