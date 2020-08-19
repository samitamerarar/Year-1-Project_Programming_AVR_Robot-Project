#include "Suiveur.h"

Suiveur::Suiveur(void)
{
	DDRA = 0x00;
}

Suiveur::~Suiveur(void) {}

bool Suiveur::ajustementDroite(void)
{
	if(bit_is_set(PINA, CAP4))
		return true;
		
	return false;
}

bool Suiveur::ajustementGauche(void)
{
	if(bit_is_set(PINA, CAP2))
		return true;
	
	return false;
}

bool Suiveur::tournerDroite(void)
{
	if(ajustementDroite())
	{
		_delay_ms(100);
		if(bit_is_set(PINA, CAP5))
			return true;
	}
	return false;
}

bool Suiveur::tournerGauche(void)
{
	if(ajustementGauche())
	{
		_delay_ms(100);
		if(bit_is_set(PINA, CAP1))
			return true;
	}
	return false;
}

/*void ajusterChemin(void)
{	
	if(bit_is_set(PINA, CAP2))
	{
		_delay_ms(100);
		if(bit_is_set(PINA, CAP1))
		{
			changerVitesse(168, 64);
			
			_delay_ms(1500);
			loop_until_bit_is_set(PINA, CAP2);
		}
		else
		{
			changerVitesse(192, 128);
			loop_until_bit_is_clear(PINA, CAP2);
		}
	}	
	
	 if(bit_is_set(PINA, CAP4))
	{
		_delay_ms(100);
		if(bit_is_set(PINA, CAP5))
		{
			changerVitesse(64, 168);
			
			_delay_ms(1500);
			loop_until_bit_is_set(PINA, CAP3);
		}
		else
		{		
			changerVitesse(128, 192);
			loop_until_bit_is_clear(PINA, CAP4);
		}
	}
	
	if(bit_is_clear(PINA, CAP1)
		&& bit_is_clear(PINA, CAP2)
		&& bit_is_clear(PINA, CAP3)
		&& bit_is_clear(PINA, CAP4)
		&& bit_is_clear(PINA, CAP5))
	{
		_delay_ms(50);
		arreterMoteur();
		
		_delay_ms(200);
		changerDirection(ARRIERE, AVANT);
		changerVitesse(144, 144);
		
		loop_until_bit_is_set(PINA, CAP3);
		changerDirection(AVANT, AVANT);
	}
		
	changerVitesse(128, 128);
}*/
