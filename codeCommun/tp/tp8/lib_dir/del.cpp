#include "del.h"

void allumerDel(char couleur)
{
	switch (couleur)
	{
		case 'a':
			couleurAmbree();
			break;
		case 'r':
			DEL = ROUGE;
			break;
		case 'v':
			DEL = VERT;
			break;
		default:
			DEL = ETEINT;
	}
}

void couleurAmbree()
{
	DEL = VERT;
	_delay_ms(3);
	
	DEL = ROUGE;
	_delay_ms(1);
}
