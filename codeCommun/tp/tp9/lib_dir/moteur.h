/* Nom: moteur.h
 * Auteurs: Guy-Frank et Tamer Arar, asmae el hajla , maroua Djaroud
 * Description: Contrôle le comportement du moteur
 * en utilisant la génération interne du microcontroleur
 * de signal PWM 
 * Version: 1.0
 */

#define F_CPU 8000000
#define DROITE 'd'
#define GAUCHE 'g'
#define _BV(bit) (1 << (bit))
#include <avr/io.h>

void initialiserMoteur(void);

void changerVitesse(uint8_t vitesse);

void avancer(uint8_t vitesse);

void reculer(uint8_t vitesse);

void arreterMoteur();

void tourner(char direction);
