#include "SystemeNavigation.h"
#include "uart.h"

int main(void)
{
	SystemeNavigation navSys;
	
	while(navSys.isEnMarche())
	{
		//navSys.ajuster();
		navSys.determinerPiece();
	}
	
	return 0;
}
