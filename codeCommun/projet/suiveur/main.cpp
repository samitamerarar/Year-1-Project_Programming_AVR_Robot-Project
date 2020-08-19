/*
 * Nom: lectureBytecode.cpp
 * Auteurs : Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: tester differentes fonction de notre librairie
 */

#include "SystemeNavigation.h"
#include "del.h"

int main()
{
	del_init();
	SystemeNavigation sysNavigation;
	
	for(;;)
	{
		sysNavigation.ajuster();
	}
	
	return 0;
}
