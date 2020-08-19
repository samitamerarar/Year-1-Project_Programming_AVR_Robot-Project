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
        DDRD |= _BV(PD4) | _BV(PD5) | _BV(PD6) | _BV(PD7);

        TCCR1A |= _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);

        TCCR1B |= _BV(CS11);
        TCCR1C = 0;
}

//cette fonction permet de varier la vitesse des roues 
void Moteur::changerVitesse (uint8_t vitesseD, uint8_t vitesseG)	//255 - vitesse maximale
{
	OCR1A = vitesseD;			//PD5	roue droite
	OCR1B = vitesseG;			//PD4	roue gauche
}

void Moteur::changerDirection(bool roueD, bool roueG)
{
	if(roueD == AVANT)
		PORTD |= _BV(PD7); //PORTD &= ~_BV(PD7);
	else
		PORTD |= _BV(PD7);
		
	if(roueG == AVANT)
		PORTD &= ~_BV(PD6);
	else
		PORTD |= _BV(PD6);
}

void Moteur::tourner180(void)
{
	_delay_ms(50);
	arreterMoteur();
		
	_delay_ms(200);
	changerDirection(ARRIERE, AVANT);
	changerVitesse(144, 144);
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
void Moteur::arreterMoteur(void)
{
	OCR1A = 0;
	OCR1B = 0;
}
//cette fonction prend en parametre un char qui modifie la direction a l aide de //switch case . d robot tourne a droite , g robot tourne a gauche
void Moteur::tourner(char direction)
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

