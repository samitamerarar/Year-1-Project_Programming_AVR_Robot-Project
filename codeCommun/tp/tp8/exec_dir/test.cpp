/*
 * Nom: test.cpp
 * Auteurs : Les membres de l'équipe 2330
 * Description: tester differentes fonction de notre librairie
 */
#define F_CPU 8000000

#include <util/delay.h>
#include <avr/io.h>
#include "bouton.h"
#include "moteur.h"
#include "can.h"
#include "del.h"
#include "interruptions.h"
#include "memoire_24.h"

int main()
{
	DDRD = 0x0F;
	PORTD = 0x0F;
	
	initialiserMoteur();
	for(;;)
	{
		changerVitesse(128, 128);
		avancer();
	}
	
	if(isPressed())
	{
		allumerDel('a');
	}
	
	return 0;
}
