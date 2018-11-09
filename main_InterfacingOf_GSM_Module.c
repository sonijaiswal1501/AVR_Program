/*
 * P1.GSM based sms alert fire alarm system.c
 *
 * Created: 26-Jul-18 10:13:20 AM
 * Author : QAZ
 */ 

#include <avr/io.h>
#include<util/delay.h>

void UART_init(long BAUDRATE);
void UART_Tx(char ch);
void UART_SendString(char *str);

void GSM_init();
void GSM_SendMessage();
void GSM_ReceiveMessage();
void GSM_Calling();
void GSM_ReceiveCall();

#define F_CPU 16000000UL
#define UART_BAUDRATE 9600
#define BAUD_PRESCALE ((F_CPU / (UART_BAUDRATE * 16UL)) - 1)

int main(void)
{
	UART_init(9600);			// initialize USART
	GSM_init();					// Start GSM with AT
	GSM_Calling();
	
	while (1)
	{	
			
	}
}

void UART_init(long BAUDRATE)
{
	UCSRB |= (1 << TXEN);									// Enable transmitter 
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);	//Set frame format: 8data, 2stop bit	
	UBRRL = BAUD_PRESCALE;									// Set baud rate for lower bit 
	UBRRH = (BAUD_PRESCALE >> 8);							// Set baud rate for higher bit 
}

void UART_Tx(char ch)
{
	while (! (UCSRA & (1<<UDRE)));				//Wait for empty transmit buffer 
	UDR = ch ;									// Put data into buffer, sends the data 
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

void GSM_init()
{
	UART_SendString("ATE1\r\n");			// send ATE0 to check module is ready or not
	_delay_ms(10000);	
	UART_SendString("AT+CMGF=1\r\n");	// select message format as text 
	_delay_ms(10000);	
}
void GSM_SendMessage()
{	
	UART_SendString("AT+CMGS=\"+918765718833\"\r\n");	//send command AT+CMGS="Mobile No.
	_delay_ms(10000);
	UART_SendString("\n Hi soni!!");
	UART_Tx(26);										// send Ctrl+Z 
	_delay_ms(10000);
}
void GSM_ReceiveMessage()
{
	UART_SendString("AT+CNMI=2,2,0,0,0\r\n");
	_delay_ms(10000);
}
  
void GSM_Calling()
{
	UART_SendString("ATD+918765718833;\r\n");		//send command ATD<Mobile_No>; for calling
	_delay_ms(10000);
}
  
void GSM_ReceiveCall()
{
	UART_SendString("ATA");
	UART_SendString("AT+CLIP=1\r\n");
	_delay_ms(10000);
}