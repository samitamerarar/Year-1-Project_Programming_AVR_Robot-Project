#include "Suiveur.h"
#include "del.h"

Suiveur::Suiveur(void)
{
	LSS05_DDR &= (~_BV(CAP1) & ~_BV(CAP2) & ~_BV(CAP3) & 
	~_BV(CAP4) & ~_BV(CAP5)) | _BV(DDB5);
}

Suiveur::~Suiveur(void) {}

bool Suiveur::estCentre(void)
{
	return bit_is_set(LSS05_PIN, CAP3);
}

bool Suiveur::augmenterVitesseRoueGauche(void)
{
	if(bit_is_set(LSS05_PIN, CAP4))
		return true;
		
	return false;
}

bool Suiveur::augmenterVitesseRoueDroite(void)
{
	if(bit_is_set(LSS05_PIN, CAP2))
		return true;
	
	return false;
}

bool Suiveur::tournerDroite(void)
{
	if(bit_is_set(LSS05_PIN, CAP4))
	{
		_delay_ms(150);
		if(bit_is_set(LSS05_PIN, CAP5))
			return true;
	}
	
	else if(bit_is_set(LSS05_PIN, CAP2))
	{
		_delay_ms(150);
		if(bit_is_set(LSS05_PIN, CAP5))
			return true;
	}
	return false;
}

bool Suiveur::tournerGauche(void)
{
	if(bit_is_set(LSS05_PIN, CAP2))
	{
		_delay_ms(100);
		if(bit_is_set(LSS05_PIN, CAP1))
			return true;
	}
	return false;
}
