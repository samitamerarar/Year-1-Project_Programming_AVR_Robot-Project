/* Nom: son.h
 * Auteurs: Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: Controle le son 
 * Version: 1.0
 */

#include "son.h"

//Initialiser les ports en charge d'émettre le son
void sound_init(void)
{
	SOUND_DDR |= _BV(SOUND_PIN0); //PD0 allumé
	SOUND_DDR |= _BV(SOUND_PIN1); 
	SOUND_PORT &= ~_BV(SOUND_PIN1);	//PD1 bloqué
}

//Sequence d'identification du carré qui émet un son aigu à 880Hz pendant 2 secondes.
void sequenceCarre(void)
{
	uint16_t frequence880Hz = 2273; //(8000000/880Hz) / 4 = 2273  (divisé par 4, car delay_loop2)
	uint16_t intensite25 = frequence880Hz/4; 
									//880Hz -> 1,14ms
	for(int i = 0; i<1754; i++) {	//2000ms/1,14cycle = 1754 boucles

		SOUND_PORT |= _BV(SOUND_PIN0);	//PD0 allumé
		_delay_loop_2(intensite25);

		SOUND_PORT &= ~_BV(SOUND_PIN0);	//PD0 bloqué
		_delay_loop_2(frequence880Hz-intensite25);
	}
}
