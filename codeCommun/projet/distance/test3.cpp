#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "del.h"
#include "Moteur.h"

volatile int ovf_counter = 0;

void timer0_init(void)
{
	TCNT0 = 5;
	TCCR0A = 0;
	TCCR0B = _BV(CS01);
	TIMSK0 = _BV(TOIE0);
}

int main(void)
{
	Moteur moteur;	
	moteur.avancer(255, 255);
	
	while(1) {}
}

ISR(TIMER0_OVF_vect)
{
	TCNT0 = 5;
	ovf_counter++;
	if(ovf_counter == 4000)
	{
		PORTA ^= _BV(PA6);
		ovf_counter = 0;
	}
}
