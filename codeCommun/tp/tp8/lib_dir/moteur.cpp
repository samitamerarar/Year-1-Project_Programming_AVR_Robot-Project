#include "moteur.h"

void initialiserMoteur()
{
	DDRD |= _BV(PD4) | _BV(PD5) | _BV(PD6) | _BV(PD7);	//PD4 et PD5 en sortie pour le signal PWM
														//PD6 et PD7 en sortie pour la direction
	
	PORTD |= _BV(PD6);
	
	TCCR1A |= _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);

	TCCR1B = _BV(CS11);
	TCCR1C = 0;
}
void changerVitesse (uint8_t vitesse1, uint8_t vitesse2)//255 - vitesse maximale
{
	OCR1A = vitesse1;			//PD5	roue droite
	OCR1B = vitesse2;			//PD4	roue gauche
}

void avancer()
{
	PORTD &= ~_BV(PD7);
	PORTD |= _BV(PD6);
}

void reculer()
{
	PORTD |= _BV(PD7);
	PORTD &= ~_BV(PD6);
}

void tourner(char direction)
{
	switch (direction)
	{
		case 'd':
			OCR1A = OCR1B / 3;
			break;
		case 'g':
			OCR1B = OCR1A / 3;
			break;
		default:
			break;
	}
}

