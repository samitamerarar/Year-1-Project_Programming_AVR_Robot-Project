/* Nom: moteur.h
 * Auteurs: Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: controle du moteur
 * Version: 1.0
 */
#include "moteur.h"


//Cette fonction sert a definir les ports en sortie pour le signal Pwm
//elle initialise les registre utile 
void initialiserMoteur(void)
{
        DDRD |= _BV(PD4) | _BV(PD5) | _BV(PD6) | _BV(PD7);

        TCCR1A |= _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);

        TCCR1B |= _BV(CS11);
        TCCR1C = 0;
}
//cette fonction permet de varier la vitesse des roues 
void changerVitesse (uint8_t vitesse)	//255 - vitesse maximale
{
	OCR1A = vitesse;			//PD5	roue droite
	OCR1B = vitesse;			//PD4	roue gauche
}
//cette fonction permet de definir l'orientation de mouvement de roues

void avancer(uint8_t vitesse)
{
	PORTD &= ~_BV(PD7);
	PORTD &= ~_BV(PD6);
	changerVitesse(vitesse);
}
//cette fonction change l'orientation de roue et le robot se deplace vers //l'arriere
void reculer(uint8_t vitesse)
{
	PORTD |= _BV(PD7);
	PORTD |= _BV(PD6);
	changerVitesse(vitesse);
}
//cette fonction arrete le moteur en affectant au registre une valeur nul 
void arreterMoteur()
{
	OCR1A = 0;
	OCR1B = 0;
}
//cette fonction prend en parametre un char qui modifie la direction a l aide de //switch case . d robot tourne a droite , g robot tourne a gauche

void tourner(char direction)
{
	switch (direction)
	{
		case DROITE:
			OCR1A = 0;
			break;
		case GAUCHE:
			OCR1B = 0;
			break;
		default:
			break;
	}
}

