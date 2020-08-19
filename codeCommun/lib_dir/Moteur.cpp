/* Nom: moteur.h
 * Auteurs: Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: controle du moteur
 * Version: 1.0
 */
#include "Moteur.h"

//Cette fonction sert a definir les ports en sortie pour le signal Pwm
//elle initialise les registre utile 
Moteur::Moteur(void)
{
        MOTEUR_DDR |= _BV(MOTEUR_PIN_PWM_GAUCHE) | _BV(MOTEUR_PIN_PWM_DROITE);
        
        MOTEUR_DDR |= _BV(MOTEUR_PIN_DIR_GAUCHE) | _BV(MOTEUR_PIN_DIR_DROITE);

        TCCR1A |= _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);

        TCCR1B |= _BV(CS11);
        TCCR1C = 0;
}

Moteur::~Moteur(void) {}

//cette fonction permet de varier la vitesse des roues 
void Moteur::changerVitesse (uint8_t vitesseD, uint8_t vitesseG)	//255 - vitesse maximale
{
	OCR1A = vitesseD;			//PD5	roue droite
	OCR1B = vitesseG;			//PD4	roue gauche
}

void Moteur::changerDirection(char roueD, char roueG)
{
	if(roueD == AVANT)
		MOTEUR_PORT &= ~_BV(MOTEUR_PIN_DIR_DROITE);
	else
		MOTEUR_PORT |= _BV(MOTEUR_PIN_DIR_DROITE);
		
	if(roueG == AVANT)
		MOTEUR_PORT &= ~ _BV(MOTEUR_PIN_DIR_GAUCHE);
	else
		MOTEUR_PORT |= _BV(MOTEUR_PIN_DIR_GAUCHE);
}

//cette fonction permet de definir l'orientation de mouvement de roues
void Moteur::avancer(uint8_t vitesseD, uint8_t vitesseG)
{
	changerDirection(AVANT, AVANT);
	changerVitesse(vitesseD, vitesseG);
}
//cette fonction change l'orientation de roue et le robot se deplace vers //l'arriere
void Moteur::reculer(uint8_t vitesseD, uint8_t vitesseG)
{
	changerDirection(ARRIERE, ARRIERE);
	changerVitesse(vitesseD, vitesseG);
}
//cette fonction arrete le moteur en affectant au registre une valeur nul 
void Moteur::arreter(void)
{
	OCR1A = 0;
	OCR1B = 0;
}
//cette fonction prend en parametre un char qui modifie la direction a l aide de //switch case . d robot tourne a droite , g robot tourne a gauche
void Moteur::tourner(uint8_t vitesseD, uint8_t vitesseG, char direction)
{	
	switch (direction)
	{
		case DROITE:
			changerDirection(ARRIERE, AVANT);			
			break;
		case GAUCHE:
			changerDirection(AVANT, ARRIERE);
			break;
		default:
			break;
	}
	changerVitesse(vitesseD, vitesseG);
}

