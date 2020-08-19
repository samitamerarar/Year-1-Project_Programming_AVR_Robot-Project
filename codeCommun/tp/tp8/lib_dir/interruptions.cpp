#include "interruptions.h"

void initialitisationBouton()
{
	cli();

	EIMSK |= _BV(INT0);

	EICRA |= _BV(ISC00);

	sei();
}

void partirMinuterie (uint16_t duree)
{
	// mode CTC du timer 1 avec horloge divisee par 1024
	// interruption apres la duree specifiee

	TCNT1 = 0 ;
	OCR1A = duree;
	TCCR1A = 0;
	TCCR1B = _BV(CS12) | _BV(CS10) | _BV(WGM12) ;
	TCCR1C = 0;
	TIMSK1 = _BV(OCIE1A) ;
}
