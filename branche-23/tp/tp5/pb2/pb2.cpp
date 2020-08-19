#define F_CPU 8000000
#define _BV(bit) (1 << (bit))
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t minuterieExpiree;
volatile uint8_t boutonPoussoir;

void initialtisation()
{
	cli();

	DDRD = 0x00;
	DDRC = 0xff;
	
	minuterieExpiree = 0;
	boutonPoussoir = 0;

	EIMSK |= _BV(INT0);

	EICRA |= _BV(ISC00);

	sei();
}

ISR (TIMER1_COMPA_vect) {
	minuterieExpiree = 1;
}

ISR(INT0_vect)
{
	_delay_ms(30);
	
	if(minuterieExpiree != 1)
		boutonPoussoir = 1;
}

void partirMinuterie ( uint16_t duree ) {

	minuterieExpiree = 0;

	// mode CTC du timer 1 avec horloge divisee par 1024
	// interruption apres la duree specifiee

	TCNT1 = 0 ;
	OCR1A = duree;
	TCCR1A = 0;
	TCCR1B = _BV(CS12) | _BV(CS10) | _BV(WGM12) ;
	TCCR1C = 0;
	TIMSK1 = _BV(OCIE1A) ;
}

int main()
{
	initialtisation();
	
	for (int i = 0; i < 80; i++)
			_delay_ms(25);
		
	PORTC = 0x01;
		
	for (int i = 0; i < 4; i++)
		_delay_ms(25);
			
	PORTC = 0x00;
	
	partirMinuterie(7812);
	
	do {
		// attendre qu'une des deux variables soit modifiee
		// par une ou l'autre des interruptions.
	} while ( minuterieExpiree == 0 && boutonPoussoir == 0 );

	// Une interruption s'est produite. Arreter toute
	// forme d'interruption. Une seule reponse suffit.

	cli ();

	// Verifier la reponse
	if(boutonPoussoir == 1)
		PORTC = 0x02;
	else
		PORTC = 0x01;
}
