/* Nom: bouton.h
 * Auteurs: Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: transmission et reception de donnee entre le Pc et le robot
 * Version: 1.0
 */



#include "uart.h"

void uart_init(void)
{
	// 2400 bauds. Nous vous donnons la valeur des deux
	// premier registres pour vous éviter des complications
	UBRR0H = 0;
	UBRR0L = 0xCF;

	// permettre la reception et la transmission par le UART0
	UCSR0A = _BV(UDRE0);
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);

	// Format des trames: 8 bits, 1 stop bits, none parity
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
}

void uart_send(uint8_t donnee)
{
	while (!( UCSR0A & _BV(UDRE0)));
	UDR0 = donnee;
}

uint8_t uart_receive(void)
{
	while (!(UCSR0A & _BV(RXC0)));
	return UDR0;
}
