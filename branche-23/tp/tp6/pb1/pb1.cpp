#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include <string.h>
#include "memoire_24.h"

int main()
{
	DDRB = 0xff;
	PORTB = 0x00;
	
	Memoire24CXXX memoire;
	
	uint16_t adresse = 0x00;
	uint8_t mot1[] = "*E*C*O*L*E*\n";
	mot1[sizeof(mot1) - 1] = 0;
	uint8_t mot2[sizeof(mot1)];
	
	memoire.ecriture(adresse, mot1, sizeof(mot1));	
	memoire.lecture(adresse, mot2, sizeof(mot1));
	
	if(strcmp((char*) mot1, (char*) mot2) == 0)
		PORTB = 0x02;
	else
		PORTB = 0x01;
	
	return 0;
}
