// ***********************************************************

/*Prob6.1. Write a assembly code to receive data from UART & transmit it back by adding one to it.
a. Baud Rate = 9600
b. 8 bit data
c. Single Stop Bit
Do the same by writing the code in C .*/

// ***********************************************************



#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones



// Interrupt handler example for INT0


SIGNAL(SIG_INTERRUPT0) {



}


// ***********************************************************

// Main program

//

void uart_init(void)
{

	UBRRL= 0x33;
	UCSRB = (1<<TXEN) | (1<<RXEN);
	UCSRC = (1<<UCSZ0) | (1<<UCSZ1) | (1<<URSEL);
}

void uart_send(unsigned char ch)
{

	while( ! ( UCSRA & (1<<UDRE ) ) );
	UDR = ch;

}

int main(void)
{
     unsigned char ch;
     uart_init() ;

   while(1)
    {             // Infinite loop; define here the

     while( ! ( UCSRA & (1<<RXC ) ) );
     ch = UDR;
     ch += 1;
     uart_send( ch );
   }

    return 0;

}





