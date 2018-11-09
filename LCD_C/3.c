// ***********************************************************



// ***********************************************************



#include <avr\io.h>              // Most basic include files
#include<util/delay.h>

//#include <avr\interrupt.h>       // Add the necessary ones

//#include <avr\signal.h>          // here



// Define here the global static variables

#define LCD_DPRT  PORTB
//#define LCD_DDDR DDRB
#define LCD_DPIN PINB
#define LCD_CPRT PORTD
//#define LCD_CDDR DDRD
#define LCD_CPIN PIND
#define LCD_RS 5
#define LCD_RW 2
#define LCD_EN 4



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
     	lcdData('f');


  // while(1);


   return 0;

}

void lcd_init(void)
{
//	LCD_CPRT &=~(1<<LCD_EN);
//	lcdCommand(0x33);
//	lcdCommand(0x32);
	lcdCommand(0x38);
	lcdCommand(0x0e);
	lcdCommand(0x01);
	_delay_ms(100);
	lcdCommand(0x06);
}

void lcdCommand(unsigned char cmnd)
{
	LCD_DPRT = cmnd;// & 0xF0;
	LCD_CPRT &= ~(1<<LCD_RS);
//	LCD_CPRT &= ~(1<<LCD_RW);
//	LCD_CPRT |= (1<<LCD_EN);
//	_delay_us(1);
//	LCD_CPRT &= ~ (1<<LCD_EN);
//	_delay_ms(10);
//	LCD_CPRT = cmnd<<4;
	LCD_CPRT |= (1<<LCD_EN);
	_delay_us(10);
	LCD_CPRT &= ~ (1<<LCD_EN);
	_delay_ms(10);
}

void lcdData(unsigned char data)
{	
	LCD_DPRT = data;// & 0xF0;
	LCD_CPRT |= (1<<LCD_RS);
	LCD_CPRT &= ~(1<<LCD_RW);
//	LCD_CPRT |= (1<<LCD_EN);
//	_delay_us(1);
//	LCD_CPRT &= ~ (1<<LCD_EN);
//	LCD_CPRT = data<<4;
	LCD_CPRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_CPRT &= ~ (1<<LCD_EN);
	_delay_us(100);
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



