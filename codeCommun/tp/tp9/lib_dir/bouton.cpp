/* Nom: bouton.cpp
 * Auteurs: Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: Enregistrer l'activation du bouton
 * Version: 1.0
 */


#include "bouton.h"
//////////////////////////////////////////////////////////
//
//fonction:isPressed
//Role:elle verifie si le bouton poussoir est appuye
//
///////////////////////////////////////////////////////////////

bool isPressed()
{
	if(PIND & 0x04)
	{
		_delay_ms(10);
		
		if(PIND & 0x04)
			return true;
		else
			return false;
	}
}
