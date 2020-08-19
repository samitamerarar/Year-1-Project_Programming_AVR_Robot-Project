/* Nom: moteur.h
 * Auteurs: Guy-Frank et Tamer Arar
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

void initialiserMoteur();

void changerVitesse(uint8_t vitesse1, uint8_t vitesse2);

void avancer();

void reculer();

void tourner(char direction);
