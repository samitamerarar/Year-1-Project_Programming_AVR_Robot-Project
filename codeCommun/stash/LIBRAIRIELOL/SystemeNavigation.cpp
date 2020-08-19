#include "SystemeNavigation.h"

SystemeNavigation::SystemeNavigation(void) : moteur(0) {}

SystemeNavigation::~SystemeNavigation(void) {}

void SystemeNavigation::setMoteur(Moteur *moteur)
{
	this->moteur = moteur;
}

void SystemeNavigation::ajuster(void)
{
	if(suiveur.tournerGauche())
	{
		moteur->avancer(168, 64);
		
		_delay_ms(1500);
		loop_until_bit_is_set(PINA, CAP3);
	}
	
	else if(suiveur.ajustementGauche())
	{
		moteur->avancer(192, 128);
		loop_until_bit_is_clear(PINA, CAP2);
	}
	
	if(suiveur.tournerDroite())
	{
		moteur->avancer(64, 168);
		
		_delay_ms(1500);
		loop_until_bit_is_set(PINA, CAP3);
	}
		
	else if(suiveur.ajustementDroite())
	{	
		moteur->avancer(128, 192);
		loop_until_bit_is_clear(PINA, CAP4);
	}
	
	/*if(bit_is_clear(PINA, CAP1)
		&& bit_is_clear(PINA, CAP2)
		&& bit_is_clear(PINA, CAP3)
		&& bit_is_clear(PINA, CAP4)
		&& bit_is_clear(PINA, CAP5))
	{
		moteur->tourner180();
		
		loop_until_bit_is_set(PINA, CAP3);
	}*/
		
	moteur->avancer(128, 128);
}
