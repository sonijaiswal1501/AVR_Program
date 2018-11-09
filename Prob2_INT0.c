// ***********************************************************
/*Write a program to generate external interrupt on Int0 (PD2) pin of atmega8 controller .
In the interrupt handler toggle LED connected to PD4 every time an interrupt is
generated .
Implementation of the code should be done both in  C .*/

// ***********************************************************



#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones


// Define here the global static variables

volatile int flag;

// Interrupt handler example for INT0


ISR(INT0_vect) {

        flag ^=1;

}


// ***********************************************************

// Main program


int main(void)
{

		DDRD = 0x10;
		PORTD = 0x04;
      GICR  = (1<<INT0);
      sei();

   while(1)
    {             // Infinite loop; define here the

        if(flag)
      		PORTD = 0x04;
        else
      		PORTD = 0x14;

   }

     return 0;

}




