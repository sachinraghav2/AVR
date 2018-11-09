// ***********************************************************


//Prob 4.2.....Write a code to toggle LED's on PORTB at the rate of 1 sec when 1 is pressed fromthe keyboard and change the rate to 2 sec when 2 is pressed.

// ***********************************************************



#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include<util/delay.h>


#define  key_prt  PORTC
#define  key_ddr DDRC
#define  key_pin PINC

void delay_ms(unsigned int );

unsigned char keypad[4][4] = { '0','1','2','3',
										 '4','5','6','7',
										 '8','9','A','B',
										 'C','D','E','F'};
// ***********************************************************

// Main program



int main(void)
{
  	unsigned char colloc, rowloc;
  	
  	DDRD = 0xFF;
   key_prt = 0xFF;
   key_ddr = 0xF0;

   while(1)
    {             // Infinite loop; define here the
         do
         {
 				key_prt &= 0x0f;
 			   colloc = (PINC & 0x0F);
   		}while(colloc != 0x0F);
   		
   		do
         {
 				do
 				{
 				   delay_ms(20);
 				   colloc = (PINC & 0x0F);
   	   	}while(colloc == 0x0F);
   	   	
   		   delay_ms(20);
   		   colloc = (PINC & 0x0F);
   	  	}while(colloc == 0x0F);
   	  	
   	  while(1)
        {
          key_prt = 0xEF;
          colloc = (PINC & 0x0F);

			 if(colloc != 0x0F)
			 {
			 	rowloc = 0;
			 	break;
   		 }
   		key_prt  = 0xDF;
   		colloc = (key_pin  &( 0x0F));
   		
   		if(colloc != 0x0F)
   		 {
			 	rowloc = 1;
			 	break;
   		 }
   		 key_prt  = 0xBF;
   		 colloc = (key_pin & 0x0F);
   		if(colloc != 0x0F)
   		 {
			 	rowloc = 2;
			 	break;
   		 }
   		 key_prt  = 0x7F;
   		 colloc = (key_pin & 0x0F);
   	    rowloc = 3;
			 break;
		  }
		
		if(colloc == 0x0E)
		  PORTD = (keypad[rowloc][0]);
		
	  	else if(colloc == 0x0D)
		  PORTD = (keypad[rowloc][1]);
		
		else if (colloc == 0x0B)
		  PORTD = (keypad[rowloc][2])  ;
		else
		  PORTD = (keypad[rowloc][3]);
    }

  return 0;

}

void delay_ms(unsigned int d)
{
		_delay_ms(d);
}







