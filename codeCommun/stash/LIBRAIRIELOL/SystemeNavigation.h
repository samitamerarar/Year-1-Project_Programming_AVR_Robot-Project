#ifndef SYSTEME_NAVIGATION_H
#define SYSTEME_NAVIGATION_H

#include "Suiveur.h"
#include "Moteur.h"

class SystemeNavigation
{
	public:
		SystemeNavigation(void);
		~SystemeNavigation(void);
		
		void setMoteur(Moteur *moteur);
		
		void ajuster(void);
	private:
		Moteur *moteur;
		Suiveur suiveur;
};

#endif
