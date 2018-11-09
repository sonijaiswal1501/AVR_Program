// ***********************************************************

//Prob9_10.1.....Write a code for SPI Master and Slave.ect:


// ***********************************************************



#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here



// ***********************************************************

// Main program


int main(void)
{

		DDRB = (1<<3) | (1<<5);
		DDRD = 0xFF;
		SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);

		while(1)
	   {

 			SPDR = 'A';

			while( ! ( SPSR & (1<<SPIF ) ) );
		      	PORTD = SPDR;
		}

		return 0;

}













