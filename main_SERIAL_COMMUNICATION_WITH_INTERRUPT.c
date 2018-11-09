/*
 * SERIAL COMMUNICATION.c
 *
 * Created: 03-May-18 3:10:03 PM
 * Author : QAZ
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

void UART_init(long BAUDRATE);
unsigned char UART_Rx();

#define F_CPU 16000000UL
#define UART_BAUDRATE 9600
#define BAUD_PRESCALE ((F_CPU / (UART_BAUDRATE * 16UL)) - 1)
static char ch;

ISR(USART_RXC_vect)				//Interrupt Service Routine for INT0
{
	ch = UDR;
}
int main()
{       
	DDRA = 0xFF;
	PORTA = 0x00;
	
    UART_init(9600);    
	sei();
	
    while(1)
    {
	   if (ch==0X31)
	   PORTA = 0XFF;
	   else
	   PORTA = 0x00; 	   
    }
}
void UART_init(long BAUDRATE)
{
	UCSRB |= (1 << RXEN) ;
	UCSRB |= (1 << RXCIE) ;
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	UBRRL = BAUD_PRESCALE;		
	UBRRH = (BAUD_PRESCALE >> 8);	
}








