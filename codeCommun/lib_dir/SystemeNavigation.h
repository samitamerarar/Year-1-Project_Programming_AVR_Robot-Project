#ifndef SYSTEME_NAVIGATION_H
#define SYSTEME_NAVIGATION_H

#include "Suiveur.h"
#include "Moteur.h"
#include "CapteurCouleur.h"
#include "CapteurDistance.h"
#include "uart.h"
#include "del.h"
#include "son.h"

#define NOMBRE_PIECES_MAX 3
#define NOMBRE_MESURES_MAX 255

//Les différents états du robot lors de son parcours
enum Etat{INITIAL, AVANCER, IDENTIFICATION, RETOUR};

class SystemeNavigation
{
	public:
		SystemeNavigation(void);
		~SystemeNavigation(void);
		
		void mettreAJour(void);
		
		void determinerPiece(void);
		
		bool isEnMarche(void) const;
		
		void partirMinuterie(void);
		
		void ajuster(void);
		
		void prendreMesures(uint8_t mesure);
		
		void demarrer(void);
		
		char analyserMesures(void);
		
		void lireCouleurs(void);
		
		void effectuerSequence(char couleur);
		
	private:
		uint8_t nbPieces;
		char pieces[NOMBRE_PIECES_MAX];
		
		uint8_t nbMesures;
		uint8_t mesures[NOMBRE_MESURES_MAX];
		
		Moteur moteur;
		Suiveur suiveur;
		CapteurDistance captDistance;
		CapteurCouleur captCouleur;
		
		Etat etat;
		bool enMarche;
};

#endif
