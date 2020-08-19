/* Nom:del.cpp
 * Auteurs: Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: Enregistrer l'activation du bouton
 * Version: 1.0
 */


#include "del.h"
//fonction :cette fonction initialise la del ne retourne rien

void initialiserDel(void)
{
	DDRA |= _BV(PA6) | _BV(PA7);
}

//cette fonction prend en parametre une couleur et ne retourne rien 
// elle allume la del en ambree, rouge ou vert, respectivement

void allumerDel(uint8_t couleur)
{
	switch (couleur)
	{
		case AMBREE:
			couleurAmbree();
			break;
		case ROUGE:
			DEL |= ROUGE;			
			break;
		case VERT:
			DEL |= VERT;
			break;
		default:
			eteindreDel();
			break;
	}
}
//cette fonction sert a eteindre la del 
void eteindreDel(void)
{
	DEL &= ETEINT;
}
// cette fonction allume la del en ambree
void couleurAmbree(void)
{	
	DEL = VERT;
	_delay_ms(3);

	DEL = ROUGE;
	_delay_ms(1);
}
