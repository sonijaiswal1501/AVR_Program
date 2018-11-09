// ***********************************************************

//Prob 8.1....Study the ADC Interface and Write a code for ADC using AVR Micro controller. Sample the LDR data at 1Hz and generate plot for the same .n:

// ***********************************************************



#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here



// Interrupt handler example for INT0


ISR(ADC_vect) {

		 PORTB = ADCL;
		 PORTD = ADCH;
	    ADCSRA  |=  (1<<ADSC);
}


// ***********************************************************

// Main program


int main(void)
{

	DDRB = 0xFF;
	DDRD = 0xFF;
	DDRC = 0x00;

//	PORTC=0x01;

	ADMUX = (1<<REFS0);
	ADCSRA  |=  (1<<ADPS1)   |  (1<<ADPS0);
	ADCSRA  |= (1<<ADIE)  |  (1<<ADSC)  |  (1<<ADEN); 	

	sei();	

   while(1)
   {             // Infinite loop; define here the


   }



}



