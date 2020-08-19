#include "SystemeNavigation.h"

int main()
{
	SystemeNavigation navSys;
	
	navSys.demarrer();
	
	_delay_ms(500);
	
	while(navSys.isEnMarche())
	{
		navSys.mettreAJour();
	}
}
