/* Nom: moteur.h
 * Auteurs: Guy-Frank et Tamer Arar, asmae el hajla , maroua Djaroud
 * Description: Contrôle le comportement du moteur
 * en utilisant la génération interne du microcontroleur
 * de signal PWM 
 * Version: 1.0
 */
 
#ifndef MOTEUR_H
#define MOTEUR_H

#define F_CPU 8000000
#define DROITE 'd'
#define GAUCHE 'g'
#define AVANT true
#define ARRIERE false
#include <avr/io.h>
#include <util/delay.h>

class Moteur
{
	public:
	
		Moteur(void);
		//~Moteur(void);

		void tourner180(void);

		void avancer(uint8_t vitesseD, uint8_t vitesseG);

		void reculer(uint8_t vitesseD, uint8_t vitesseG);

		void arreterMoteur(void);

		void tourner(char direction);
		
	private:
		
		void changerVitesse(uint8_t vitesseD, uint8_t vitesseG);

		void changerDirection(bool roueD, bool roueG);
};

#endif
