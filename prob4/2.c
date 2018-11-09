// ***********************************************************

//Prob.4.2......Write a code to toggle LED's on PORTB at the rate of 1 sec when 1 is pressed from the keyboard and change the rate to 2 sec when 2 is pressed.



// ***********************************************************



#include <avr\io.h>              // Most basic incluefiles
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here


int flag1,flag2;
// Interrupt handler example for INT0
void delay1s(void);


ISR(INT0_vect) {

        flag1 =1;
        flag2 =0;
}


ISR(INT1_vect) {

       flag1 =0;
       flag2 =1;

}



// ***********************************************************

// Main program

//

int main(void)

{

 	DDRB = 1;
	DDRD = 0;
	PORTD |= (1<<PD2) | (1<<PD3);


	GICR = (1<<INT0) |  (1<<INT1);
	MCUCR |=  (1<<ISC11)  |  (1<<ISC01) | (1<<SE);

	sei();

	

   while(1)             // Infinite loop; define here the
    {
      if( flag1 )
      {
    	  PORTB ^= 1 ;
    	  delay1s();
    	
    	}
     if( flag2 )
     {
    	  PORTB ^= 1 ;
    	  delay1s();
    	  delay1s();
    }

    }

   return 0;

}

void delay1s(void)
{
  TCNT1H = 0xC2;
  TCNT1L = 0xF6;

	TCCR1A = 0X00;
	TCCR1B = 0X03;
	
	while((TIFR & (0X1<<TOV1 ) ) == 0);
	
	TCCR1B = 0;
	TIFR = 0X1<<TOV1;
}




