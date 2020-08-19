#include "CapteurCouleur.h"
#include "del.h"
#include "uart.h"
#include "son.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main()
{
	uart_init();
	del_init();
	sound_init();
	sei();
	
	while(1)
	{
		sequenceCarre();
		_delay_ms(1000);
	}
}
