/* Nom:del.cpp
 * Auteurs: Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: Enregistrer l'activation du bouton
 * Version: 1.0
 */


#include "del.h"
//fonction :cette fonction initialise la del ne retourne rien

void del_init(void)
{
	DEL_DDR |= _BV(DEL_PIN1) | _BV(DEL_PIN2);
}

//cette fonction prend en parametre une couleur et ne retourne rien 
// elle allume la del en ambree, rouge ou vert, respectivement

void del_on(char couleur)
{
	switch (couleur)
	{
		case ROUGE:
			DEL_PORT |= _BV(DEL_PIN1);
			DEL_PORT &= ~_BV(DEL_PIN2);
			break;
		case VERT:
			DEL_PORT &= ~_BV(DEL_PIN1);
			DEL_PORT |= _BV(DEL_PIN2);
			break;
		default:
			del_off();
			break;
	}
}
//cette fonction sert a eteindre la del 
void del_off(void)
{
	DEL_PORT &= ~_BV(DEL_PIN1) & ~_BV(DEL_PIN2);
}

void sequenceOctogone(void)
{
	del_on(ROUGE);
	
	_delay_ms(2000);
	
	del_off();
}

void sequenceCercle(void)
{
	del_on(VERT);
	
	_delay_ms(2000);
	
	del_off();
}
