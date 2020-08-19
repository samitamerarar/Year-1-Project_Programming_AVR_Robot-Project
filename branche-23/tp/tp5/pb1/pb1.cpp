#define F_CPU 8000000
#define _BV(bit) (1 << (bit))
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t etat;
volatile uint8_t compteur;

void initialitisation()
{
	cli();

	DDRD = 0x00;
	DDRC = 0xff;

	etat = 0;

	EIMSK |= _BV(INT0);

	EICRA |= _BV(ISC00);

	sei();
}

ISR(INT0_vect) {
	// laisser un delai avant de confirmer la reponse du  
	// bouton-poussoir: environ 30 ms (anti-rebond)

	_delay_ms(30);

	// Se souvenir ici si le bouton est presse ou relache

	if (PIND & 0x04)
		compteur++;

	// changements d'etats tels que ceux de la  
	// semaine precedente

	if (compteur == 5)
	{
		etat = 1;
		compteur = 0;
	}

	EIFR |= _BV(INTF0);
}


int main()
{
	initialitisation();
	
	for(;;)
	{

		if (etat == 0)
			PORTC = 0x00;
		else
		{
			PORTC = 0x02;
			_delay_ms(1000);
			etat = 0;
		}
	}
}
