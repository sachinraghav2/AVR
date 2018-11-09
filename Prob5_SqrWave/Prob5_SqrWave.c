// ***********************************************************


//Prob 4.5....Write a code to generate square wave at the output of pin OC1A of frequency f1 andexactly f1/2 at OC1B.

// ***********************************************************



#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here


// Define here the global static variables

int flag1,flag2;

// Interrupt handler example for INT0


ISR(TIMER2_COMP_vect) {

			flag1 ^= 1;

			flag2++;

			if(flag2 > 3)
	  		  flag2 = 0;

}



// ***********************************************************

// Main program



int main(void)
{

		TCNT2 = 0;
		OCR2 = 156;
		TCCR2 = (1<<CS22) | (1<<WGM21) ;
		TIMSK = (1<<OCIE2);
		DDRB = 0xFF;
		DDRD = 0xFF;
		sei();

      while(1)
       {            // Infinite loop; define here the

    		 if(flag1)
           	PORTB |= 0x02;
         else
           	PORTB &= 0xFD;

     		if(flag2 <=1)
        		PORTB |= 0x04;
         else
        		PORTB &= 0xFB;   			

		}

      return 0;

}








