#define F_CPU 8000000
#define _BV(bit) (1 << (bit))
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void ajustementPWM (uint8_t a, uint8_t b) {

// mise a un des sorties OC1A et OC1B sur comparaison
// reussie en mode PWM 8 bits, phase correcte
// et valeur de TOP fixe a 0xFF (mode #1 de la table 16-5
// page 130 de la description technique du ATmega324PA)

TCCR1A = 0xf1; 
OCR1A = a;
OCR1B = b;

// division d'horloge par 8 - implique une frequence de PWM fixe

TCCR1B = _BV(CS11);
TCCR1C = 0;
}

int main()
{
	DDRD = 0xB0;
	PORTD = 0xA0;
	
	for(;;)	
		ajustementPWM(128, 128);
}
