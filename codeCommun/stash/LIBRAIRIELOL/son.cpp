/* Nom: son.h
 * Auteurs: Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: Controle le son 
 * Version: 1.0
 */


#include "son.h"

const static double constante = pow(2, 1 / 12);

//cette fonction initialise le son 
void initialiserSon(void) //PWM, mode CTC
{
	DDRB |= _BV(PB3);
	
	TCCR0A |= _BV(WGM01);
	
	TCCR0B |= _BV(CS02);
}
	
void jouerNote(uint8_t note)	//jouer son après conversion d'un entier entre 45 et 81 en une durée
{
	TCCR0A |= _BV(COM0A0);
	
	if(note >= 45 && note <= 81)
	{	
		uint16_t frequence = 110 * pow(constante, note - 45); //d'apres la formule f=f0 x 2^n/(12)
		
		OCR0A = F_CPU / (frequence * 2 * 256) - 1;
	}
}

void arreterSon(void)	//le registre est bloqué
{
	TCCR0A &= ~_BV(COM0A0);
}
