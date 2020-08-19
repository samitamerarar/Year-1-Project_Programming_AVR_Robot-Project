/*
 * Nom: lectureBytecode.cpp
 * Auteurs : Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: tester differentes fonction de notre librairie
 */


#define F_CPU 8000000

#include <util/delay.h>
#include <avr/io.h>
#include "bouton.h"
#include "moteur.h"
#include "son.h"
#include "can.h"
#include "del.h"
#include "memoire_24.h"

static uint16_t adresse;
static uint8_t compteur;

//Sequence qui permet de confirmer que le robot démarre
void sequenceDemarrage()
{
	
}

//Executer les méthodes selon l'instruction et l'opérande lues du bytecode
void executerInstruction(uint8_t instruction, uint8_t operande)
{		
	static uint16_t adresseBoucle;
	
	switch (instruction)
	{
		//Attendre 25ms * operande
		case 0x02:	//att
			for (uint8_t i = 0; i < operande; i++)
				_delay_ms(25);
			break;
			
		//Allumer la DEL selon la couleur indiquée par l'opérande
		case 0x44:	//dal
			if(operande == AMBREE)
				allumerDel(AMBREE);
				
			if(operande == ROUGE)
				allumerDel(ROUGE);
				
			if(operande == VERT)
				allumerDel(VERT);
			break;
			
		//Eteindre DEL
		case 0x45:	//det
			eteindreDel();
			break;
			
		//Émettre un son selon la note indiquée par l'opérande
		case 0x48:	//sgo
			jouerNote(operande);
			break;
			
		//Arreter l'emission du son
		case 0x09:	//sar
			arreterSon();
			break;
			
		//Arreter le moteur
		case 0x60:	//mar
		case 0x61:	
			arreterMoteur();
			break;
			
		//Faire avancer le robot selon la vitesse indiquée par l'opérande
		case 0x62:	//mav
			avancer(operande);
			break;
			
		//Faire reculer le robot selon la vitesse indiquée par l'opérande
		case 0x63:	//mre
			reculer(operande);
			break;
			
		//Faire tourner le robot à droite de 90 degres
		case 0x64:	//trd
			tourner(DROITE);
			break;
			
		//Faire tourner le robot à gauche de 90 degres
		case 0x65:	//trg
			tourner(GAUCHE);
			break;
			
		//Indiquer le début de la boucle
		case 0xC0:	//dbc
			adresseBoucle = adresse;
			compteur = operande;
			break;
			
		//Indiquer la fin de la boucle
		case 0xC1:	//fbc
			if(compteur != 0)
			{
				adresse = adresseBoucle;
				compteur--;
			}
			break;
		default:
			break;
	}
}

int main()
{
	Memoire24CXXX memoire;
	adresse = 0x0000;
	uint8_t instruction;
	uint8_t operande;
	
	initialiserSon();
	initialiserDel();
	initialiserMoteur();
	
	do
	{
		//Lire l'instruction de la mémoire
		memoire.lecture(adresse++, &instruction);
		
		//Lire l'opérande de la mémoire
		memoire.lecture(adresse++, &operande);
		
		executerInstruction(instruction, operande);
		
	} while (instruction != 0xFF);
	
	return 0;
}
