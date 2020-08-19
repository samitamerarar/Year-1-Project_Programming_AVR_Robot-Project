/* Nom: moteur.h
 * Auteurs: Guy-Frank et Tamer Arar, asmae el hajla , maroua Djaroud
 * Description: Contrôle le comportement du moteur
 * en utilisant la génération interne du microcontroleur
 * de signal PWM 
 * Version: 1.0
 */
 
#ifndef SUIVEUR_H
#define SUIVEUR_H

#define LSS05_DDR DDRC
#define LSS05_PIN PINC

#define CAP1 PINC0	//capteur1 - pin0 (gris)
#define CAP2 PINC1	//capteur2 - pin1 (violet)
#define CAP3 PINC2	//capteur3 - pin2 (orange)
#define CAP4 PINC3	//capteur4 - pin3 (jaune)
#define CAP5 PINC4	//capteur5 - pin4 (vert)

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

class Suiveur
{
	public:
		Suiveur(void);
		~Suiveur(void);
		
		bool augmenterVitesseRoueGauche(void);
		
		bool augmenterVitesseRoueDroite(void);
		
		bool tournerDroite(void);
		
		bool tournerGauche(void);
		
		bool estCentre(void);
};

#endif
