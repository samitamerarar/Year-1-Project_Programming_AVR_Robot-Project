/*
 * Nom: ecritureBytecode.cpp
 * Auteurs : Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: Écrire le bytecode dans la mémoire de la carte mère
 */

#define F_CPU 8000000

#include <util/delay.h>
#include <avr/io.h>
#include "uart.h"
#include "memoire_24.h"

int main()
{
	Memoire24CXXX memoire;
	uint8_t	adresse = 0x0000;
	uint8_t donnee;
	uint16_t taille;
	
	initialisationUART();
	
	//Lire le premier octet indiquant la taille du bytecode
	donnee = receptionUART();
	taille = donnee;
	
	//Lire le deuxième octet indiquant la taille du bytecode
	donnee = receptionUART();
	
	//Concatener les deux octets
	taille = (taille << 8) + donnee;	
	
	//Ecrire tous les octets du bytecode dans la mémoire
	for (uint16_t i = 0; i < taille; i++)
	{
		donnee = receptionUART();
		memoire.ecriture(adresse++, donnee);	
	}
	return 0;
}
