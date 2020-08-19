#include "bouton.h"

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
