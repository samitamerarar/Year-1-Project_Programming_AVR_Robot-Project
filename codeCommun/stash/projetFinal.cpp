#define F_CPU 8000000

#include <util/delay.h>
#include <avr/io.h>
#include "SystemeNavigation.h"
#include "del.h"
#include "son.h"

//Les différents états du robot lors de son parcours
enum Etat{INITIAL, PIECE, AVANCER, RETOUR};

int main()
{
	/*int coin = 0; 						// Nombre de coins sur le trait noir rencontrés
	string pieces[3] = {""};			// tableau 3 valeurs à 0
	
	Etat etat = AVANCE;
	
	switch (etat)
	{
	case AVANCE:   // État qui fait avancer le robot et tourne aux coins.
	{	
		if (coin == 1) 
			etat = TOURNER;
		else if (coin == 3 || coin == 5)
			etat = TOURNER2;
		break;
	}
	case TOURNER:  // État après avoir tourner 1 fois et en sort une fois la pièce atteinte.
	{	
		etat = PIECE;
		break;
	}
	case PIECE:    // État lorsque le robot est dans la pièce.
	{
		string piece = trouverPiece(); 			// Nous renvoie la pièce trouvée (méthode avec IR)
		enregistrerPiece(pieces, piece); 		// Enregistre la pièce dans le tableau pieces
		
		if (piece == "carre")
			sequencePieces(CARRE);
		else if (piece == "octogone")
			sequencePieces(OCTOGONE);
		else
			sequencePieces(CERCLE);
			
		etat = DEMITOUR;
		break;
	}
	case DEMITOUR: // État lorsque le robot doit sortir de la pièce.
	{	
		etat = AVANCE;
		break;
	}
	case TOURNER2: // État après avoir tourner 2 fois et en sort une fois la pièce atteinte.
	{
		etat = PIECE;
		break;
	}
	case RECULER:  // État après la troisième pièce.
	{
		break;
	}
	case COULEUR:  // État dans lequel le robot identife la séquence de couleur.
	{
		break;
	}
	default:
		break;
	}*/
}

void enregistrerPiece(string pieces[3], string piece)
{	
	if (pieces[0] != "") {
		pieces[0] = piece;
	}
	else if (pieces[1] != "") {
		pieces[1] = piece;
	}
	else {
		pieces[2] = piece;	
	}
}

