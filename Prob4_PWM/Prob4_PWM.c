// ***********************************************************

//Prob 4.4....Write a code to generate a PWM waveform.

// ***********************************************************



#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here


// Interrupt handler example for INT0

//

ISR(TIMER2_COMP_vect) {



}


// ***********************************************************

// Main program

int main(void)
{

	DDRB = 0xFF;
	TCNT2 =0;
	OCR2 = 125;
	TCCR2 = (1<<CS21) | (1<<WGM20) | (1<<WGM21) |(1<<COM20) | (1<<COM21);
	TIMSK = (1<<OCIE2);


   while(1)
    {             // Infinite loop; define here the

    }

   return 0;

}





