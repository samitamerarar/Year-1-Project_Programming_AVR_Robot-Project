/*
 * Nom: pb2.cpp
 * Description: Changement de couleurs de la DEL libre en fonction des signaux obtenus par une photorésistance.
 * Version: 1.0
 * Créé : 24 octobre 2016
 * Modifié : 24 octobre 2016
 * Auteurs : Tamer Arar et Guy-Frank Essome Penda
 */

#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include <string.h>
#include "can.h"

int main()
{	
	
	DDRC = 0x03; //on attribut la sortie au port 1 et 2 de la broche C
	DDRA = 0x00; //on met la broche A en entrée
	can convertisseur; //variable qui convertit valeur analogique vers numérique
	uint8_t donnee; //données récoltées sur 8 bits
	
	for (;;)
	{
		// lire la valeur analogique de la fonction du fichier can.h à 
		// la position 0 de la broche A et décaler le nombre de bits 
		// recu, soit 10 bits, vers la droite par 2 pour obtenir une valeur
		// sur 8 bits
		donnee = convertisseur.lecture(0) >> 2;
		
		// Méthode par scrutation qui permet de de définir une plage de 
		// données sur 8 bits sachant que la valeur max 255. 
		// La del tourne au vert avec une donnée inférieur a 200 (luminosité très basse),
		// elle tourne au rouge avec une valeur supérieure à 245 (lumière élevée), 
		// sinon, entre ces deux valeurs elle est à ambrée (lumière ambiante)
		if(donnee < 10)
			PORTC = 0x01;
		else if(donnee > 235)
			PORTC = 0x01;
		else
		{
			PORTC = 0x01;
			_delay_ms(16);
			PORTC = 0x02;
			_delay_ms(4);
		}
	}
}
