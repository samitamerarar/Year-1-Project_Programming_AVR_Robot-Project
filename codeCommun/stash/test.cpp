#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "Moteur.h"
#include "can.h"
#include "uart.h"

#define GP2D12_DDR DDRA
#define GP2D12_PORT PORTA
#define GP2D12_PIN PA0

void capteur_init(void)
{	
	GP2D12_DDR &= ~_BV(GP2D12_PIN);
}

float read_gp2d12_range()
{
	can conv;
	int tmp;
	tmp = conv.lecture(GP2D12_PIN);
	if (tmp < 3)
		return -1;
		
	return (12000.0 /((float)tmp - 3.0)) - 4.0;
}

int getDistance(void)
{
	char a,b;		
	char capt;
	
	capt = read_gp2d12_range();
	
	a=capt/10;
	b=capt%10;
	
	return a*10+b;
}

int main(void)
{	
	int val;
	Moteur m;
	
	m.avancer(144, 144);
	
	uart_init();
	capteur_init();
	
	while(1)
	{
		val = getDistance();
		
		if(val>10&&val<80)
		{
			if(val <= 18)
			{
				
				while(val > 15 && val < 20)
				{
					m.tourner180();
					
					val = getDistance();
					
					uart_send(val);
					
					_delay_ms(50);					
				}
			}			
		}
		//uart_send(val);	
		_delay_ms(50);
	}
	
	return 0;
}
