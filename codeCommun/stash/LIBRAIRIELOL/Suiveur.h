/* Nom: moteur.h
 * Auteurs: Guy-Frank et Tamer Arar, asmae el hajla , maroua Djaroud
 * Description: Contrôle le comportement du moteur
 * en utilisant la génération interne du microcontroleur
 * de signal PWM 
 * Version: 1.0
 */
 
#ifndef SUIVEUR_H
#define SUIVEUR_H

#define CAP1 PINA0	//capteur1 - pin0 (gris)
#define CAP2 PINA1	//capteur2 - pin1 (violet)
#define CAP3 PINA2	//capteur3 - pin2 (orange)
#define CAP4 PINA3	//capteur4 - pin3 (jaune)
#define CAP5 PINA4	//capteur5 - pin4 (vert)

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

class Suiveur
{
	public:
		Suiveur(void);
		~Suiveur(void);
		
		bool ajustementDroite(void);
		
		bool ajustementGauche(void);
		
		bool tournerDroite(void);
		
		bool tournerGauche(void);
};

#endif
