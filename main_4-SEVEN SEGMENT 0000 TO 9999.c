#include <avr/io.h>
#include<util/delay.h>

void converto7seg(int number);
void twodigitwithenable (int number);

#define DISP1 PC0
#define DISP2 PC1
#define DISP3 PC2
#define DISP3 PC3

int main(void)
{
	int i,j,k,l,m;
	DDRA=0xFF;		
	DDRC=0xFF;
	PORTC=0xff;
	
	
	while (1)
	{ 
		 for (i=0;i<10;i++)
		 {
			for (j=0;j<10;j++)
				{
					for (k=0;k<10;k++)
					  {
						for(l=0; l<10; l++)
						{
						  for(m=0; m<20; m++)
						  {	
							_delay_ms(50);
							converto7seg(l);
							PORTC &= ~(1<<PC3);
							_delay_ms(50);
							PORTC |= (1<<PC3);
							converto7seg(k);
							PORTC &= ~(1<<PC2);
							_delay_ms(50);
							PORTC |= (1<<PC2);
							converto7seg(j);
							PORTC &= ~(1<<PC1);
							_delay_ms(50);
							PORTC |= (1<<PC1);
							converto7seg(i);
							PORTC &= ~(1<<PC0);
							_delay_ms(50);
							PORTC |= (1<<PC0);
						  }
						}
					}
				}
		 }
		
	}
}

void seven_segment(unsigned char b)
{
	PORTA = b;		
}

void converto7seg(int number)
{	
	switch (number)
	{
		case 0: seven_segment(0XBF);
				break;
		case 1: seven_segment(0X86);
				break;
		case 2: seven_segment(0XDB);
				break;
		case 3: seven_segment(0XCF);
				break;
		case 4: seven_segment(0XE6);
				break;
		case 5: seven_segment(0XED);
				break;
		case 6: seven_segment(0XFD);
				break;
		case 7: seven_segment(0X87);
				break;
		case 8: seven_segment(0XFF);
				break;
		case 9: seven_segment(0XEF);
				break;
	}
}
void twodigitwithenable (int number)
{
				PORTC &= ~(1<<PC0);	
				PORTC |= (1<<PC0);				
				converto7seg(number);		
				PORTC &= ~(1<<PC1);		
				PORTC |= (1<<PC1);				
				converto7seg(number);							
	
}
