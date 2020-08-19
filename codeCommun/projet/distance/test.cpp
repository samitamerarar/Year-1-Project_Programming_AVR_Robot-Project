#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "can.h"
#include "uart.h"
#include "del.h"

void capteur_init(void)
{
	DDRA &= ~_BV(DDA0);
}

uint8_t getDigitalValue(void)
{
	can convertisseur;
	int digitalValue = convertisseur.lecture(PINA0) >> 2;
	return digitalValue;
}

uint8_t getAverage(void)
{
	int somme = 0;
	int value = 0;
	
	for (int i = 0; i < 10; i++)
	{
		value = getDigitalValue();
		somme += value;
		_delay_ms(5);		
	}
	
	somme /= 10;
	
	somme = (float) somme * 1.0175;
	
	return somme;
}

uint8_t calculerDistance(void)
{	
	const float m = 2914.0;
	const float b = 5.0;
	const float k = 1.0;
	
	int voltage = getAverage();
	
	float distance = m / ((float) voltage + b) - k;
	
	distance *= 10;
	
	int a = (int) distance / 10;
	int c = (int) distance % 10;
	
	if(c > 5)
		a++;
	
	return a;	
}

int main(void)
{
	del_init();
	uart_init();
	capteur_init();
	
	int value = 0;
	
	while(1)
	{
		value = getAverage();
		
		uart_send(value);
	}
	
	return 0;
}
