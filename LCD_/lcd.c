// ***********************************************************


// ***********************************************************


#include <avr\io.h>              // Most basic include files
#include<util/delay.h>
#include <avr\interrupt.h>       // Add the necessary ones

// Define here the global static variables


void delay_10u();
void delay_100u();
void lcd_init(void);
void lcdCommand(unsigned char );
void lcdData(unsigned char );
void lcd_print(char *);

// ***********************************************************

// Main program


int main(void)
{
	DDRB = 0xFF;
	DDRD = 0xFF;


   lcd_init();
   lcd_print("Hi");

  while(1);

   return 0;

}



void lcd_init(void)
{
	PORTB  &=   ~  (1<<4); 	
	lcdCommand(0x33);
//	_delay_ms(2);
	lcdCommand(0x32);
//	_delay_ms(2);
	lcdCommand(0x28);
//	_delay_ms(2);
	lcdCommand(0x0e);
//	_delay_ms(2);
	lcdCommand(0x01);
//	_delay_us(2000);
	lcdCommand(0x06);

}



void lcdCommand(unsigned char cmnd)
{
	PORTD = cmnd & 0xF0;
	PORTB  &=  ~  (1<<5);
	PORTB  |=  (1<<4);
	delay_10u();
	PORTB  &=  ~  (1<<4);
	delay_100u();
	PORTD = cmnd<<4;
	PORTB  |= (1<<4);
	delay_10u();
	PORTB  &=  ~  (1<<4)	 ;
	delay_100u();
}




void lcdData(unsigned char data)
{	

	PORTD = data & 0xF0;
	PORTB  |= (1<<5);
	PORTB  |= (1<<4);
	delay_10u();
	PORTB  &=  ~  (1<<4);
	PORTD  = data<<4;
	PORTB  |= (1<<4);
	delay_10u();
	PORTB  &=  ~  (1<<4);
	delay_100u();

}

void lcd_print(char *str)
{
	unsigned char i = 0;
	while(str[i] != 0)
	{
		lcdData(str[i]);
		i++;
	}

}

void delay_10u()
{
	TCNT0 =-80;
  	TCCR0= 0x01;
	while( (TIFR & 0x01) == 0);
	TCCR0 = 0;
	TIFR = 0x01;
}

void delay_100u()
{
	TCNT0 =-10;
  	TCCR0= 0x02;
	while( (TIFR & 0x01) == 0);
	TCCR0 = 0;
	TIFR = 0x01;
}






