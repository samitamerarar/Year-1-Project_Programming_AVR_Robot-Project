/* Nom: moteur.h
 * Auteurs: Guy-Frank et Tamer Arar, asmae el hajla , maroua Djaroud
 * Description: Contrôle le comportement du moteur
 * en utilisant la génération interne du microcontroleur
 * de signal PWM 
 * Version: 1.0
 */
 
#ifndef MOTEUR_H
#define MOTEUR_H

#include <avr/io.h>

#define MOTEUR_DDR DDRD
#define MOTEUR_PORT PORTD
#define MOTEUR_PIN_PWM_GAUCHE PD4
#define MOTEUR_PIN_PWM_DROITE PD5
#define MOTEUR_PIN_DIR_GAUCHE PD6
#define MOTEUR_PIN_DIR_DROITE PD7

#define DROITE 'd'
#define GAUCHE 'g'
#define AVANT 'f'
#define ARRIERE 'b'

class Moteur
{
	public:
	
		Moteur(void);
		~Moteur(void);

		void avancer(uint8_t vitesseD, uint8_t vitesseG);

		void reculer(uint8_t vitesseD, uint8_t vitesseG);

		void arreter(void);

		void tourner(uint8_t vitesseD, uint8_t vitesseG, char direction);
		
	private:
		
		void changerVitesse(uint8_t vitesseD, uint8_t vitesseG);

		void changerDirection(char roueD, char roueG);
};

#endif
