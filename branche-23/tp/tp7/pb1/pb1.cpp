/*
 * Nom: pb1.cpp
 * Description: Incrémentation du nombre de fois que la del libre clignote apres avoir appuyé sur un bouton-poussoir
 * Version: 1.0
 * Créé : 21 octobre 2016
 * Modifié : 24 octobre 2016
 * Auteurs : Tamer Arar et Guy-Frank Essome Penda
 */

#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

volatile bool appuye;
volatile uint8_t compteur;

void initialisation()
{
	cli();

	DDRD = 0x00;	// on met la broche D en entrée
	DDRC = 0xFF;	// on met la broche C en sortie
	
	compteur = 0;
	appuye = false;

	// ajustement du registre
	EIMSK |= _BV(INT0);

	sei();
}

// interruption enclenché en appuyant sur le bouton-poussoir
ISR(INT0_vect) {
	// laisser un delai avant de confirmer la reponse du bouton-poussoir
	_delay_ms(30);
	
	// le compteur est incrémenter de 10 fois par seconde tant que le bouton 
	// reste enfoncé
	// valeur maximale du compteur est à 120
	while(compteur < 120 && !(PIND & 0x04))
	{
		_delay_ms(100);
		compteur++;
	}
	// mettre la condition à vrai pour enclencher la suite des événements dans le main()
	appuye = true;
	
	// Enregistrer une autre interruption pendant qu'on est dans celle-ci
	EIFR |= (1 << INTF0);
}

int main()
{
	initialisation();
	for(;;)
	{
		// par défaut, la del libre n'est pas allumée
		PORTC = 0x00;
		// après que le boutton est relaché
		if (appuye)
		{
			// lumière clignote vert pendant 1/2 seconde
			PORTC = 0x01;
			for(int i = 0; i <2; i++)
				_delay_ms(250);

			// la carte mère ne fait rien (del éteinte) pendant 2 secondes
			PORTC = 0x00;
			for(int i = 0; i < 8; i++)
				_delay_ms(250);

			// clignotement de (compteur/2) fois, 2 fois par seconde
			for(uint8_t i = 0; i < compteur/2; i++)
			{
				PORTC = 0x02;
				_delay_ms(250);
				PORTC = 0x00;
				_delay_ms(250);
				PORTC = 0x02;
				_delay_ms(250);
				PORTC = 0x00;
				_delay_ms(250);
			}				
			
			// del libre est au vert pendant une seconde.
			PORTC = 0x01;
			for(int i = 0; i < 4; i++)
				_delay_ms(250);
				
			// pour ne pas que ca recommence la boucle
			appuye = false;
		}
	}
}
