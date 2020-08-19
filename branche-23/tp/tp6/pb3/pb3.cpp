#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include <string.h>
#include "memoire_24.h"

void initialisationUART ( void )
{
	// 2400 bauds. Nous vous donnons la valeur des deux
	// premier registres pour vous éviter des complications
	UBRR0H = 0;
	UBRR0L = 0xCF;

	// permettre la reception et la transmission par le UART0
	UCSR0A = (1 << UDRE0);
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);

	// Format des trames: 8 bits, 1 stop bits, none parity
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void transmissionUART ( uint8_t donnee )
{
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = donnee;
}

int main()
{	
	Memoire24CXXX memoire;
	uint16_t adresse = 0x0000;
	
	uint8_t donnee;
	
	initialisationUART();
	
	do
	{
		memoire.lecture(adresse++, &donnee);
		transmissionUART(donnee);
		
	} while(donnee != 0xFF);
		
	while(1){};
}
