#include "CapteurDistance.h"

//Constructeur
CapteurDistance::CapteurDistance(void)
{
	DDRA &= 0xFE;	//Mettre bit 1 du PORTA en mode entrée
}

//Destructeur
CapteurDistance::~CapteurDistance(void) {}

//Renvoi la moyenne de 10 valeurs consécutives d'un voltage converti sur 8 bits 
//pour prévenir le bruit
int CapteurDistance::getDistance(void)
{
	int voltageConverti = 0;
	for (int i = 0; i < 7 ; i++) {
		voltageConverti += (convertisseur.lecture(0) >> 2);
		_delay_ms(50);
	}
	voltageConverti /= 7;
	
	return voltageConverti;
}

//Méthode chargée d'identifer la forme de la pièce (carré, octogone ou cercle)
/*string CapteurDistance::trouverPiece(void)
{
	string piece;
	int valeurPrecedente;
	int valeurSuivante;
	int compteur = 0;
	
	for (;;) {
		valeurPrecedente = getDistance();
		_delay_ms(100);							//A changer en fonction de la vitesse du robot
		valeurSuivante = getDistance();
		
		for (int i = 0; i < 100; i++) {			//retourne carré
			if ( (valeurSuivante < 109) && (valeurSuivante > 103) )
				return piece = "carre"; 
		}
		
		compteur++;
		if ( valeurSuivante < (valeurPrecedente + 1) && valeurSuivante > (valeurPrecedente - 1) ) {
			allumerDel(ROUGE);
			if (compteur < ?? && compteur > ??) {
				return piece = "octogone"; 		//retourne octogone
			} else if (compteur < ?? && compteur > ??)
				return piece = "cercle";		//retourne cercle
		}
	}
	
	
}*/

/*
uint8_t CapteurDistance::getDistance(void)
{
	uint8_t distanceInversee;
	uint8_t voltageConverti = 0;
	for (int i = 0; i < 10 ; i++) {
		voltageConverti = (convertisseur.lecture(0) >> 2);
		distanceInversee += 2115 / (voltageConverti - 28);
		_delay_ms(80);
	}
	distanceInversee /= 10;
	
	return distanceInversee;
}
*/

/*
uint8_t CapteurDistance::getDistance(void)
{
	float distanceInversee;
	uint8_t distanceReelle;
	uint8_t voltageConverti = (convertisseur.lecture(0) >> 2);
	
	distanceInversee = 2215.38f / (voltageConverti - 28.55f); //2215, 2035
	distanceReelle = 1 / distanceInversee - 0.42;
	
	return distanceReelle;
}
*/
