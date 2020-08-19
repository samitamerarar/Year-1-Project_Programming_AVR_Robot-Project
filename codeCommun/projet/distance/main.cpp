#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include "del.h"
#include "son.h"
#include "CapteurDistance.h"
#include "Moteur.h"
#include "can.h"
#include "uart.h"

/////////////////////////////////

int main(void)
{	
	CapteurDistance captD;
	
	uart_init();
	can convertisseur;
	uint8_t donnee = 0;

	del_init();
	Moteur moteur;

	int valeurPrecedente;
	int valeurSuivante;
	
	int compteur1 = 0;
	int compteur2 = 0;
	int compteur3 = 0;
	int compteur4 = 0;
	int constant = 0;
	
	//regarde si la piece est carré en rentrant dans la piece
	for (int i = 0; i < 100; i++) {
		
		donnee = convertisseur.lecture(0) >> 2;
		uart_send(donnee);
		
		moteur.avancer(140,140);
		
		valeurPrecedente = captD.getDistance(); //premiere lecture
		_delay_ms(50);
		valeurSuivante = captD.getDistance(); //deuxieme lecture
		
		//si la distance = rayon max de la piece
		if ( (valeurSuivante < 110) && (valeurSuivante > 100) ) {
			compteur1++;
		}
		
		//si detecte 3 fois que la distance = rayon max de la piece
		if (compteur1 == 3) {
			del_on(ROUGE); //Carré				
			moteur.arreter();
			break;
		}
	}
	
	//regarde si la piece est octogonale ou cercle
	/*for (int i = 0; i < 100; i++) {
		moteur.avancer(130,130);
		
		valeurPrecedente = captD.getDistance(); //premiere lecture
		_delay_ms(10);
		valeurSuivante = captD.getDistance(); //deuxieme lecture

		//si la distance devient constante
		if ( valeurSuivante < (valeurPrecedente + 1) && valeurSuivante > (valeurPrecedente - 1) ) {
				compteur2++;
		}

		//apres 2 distances constantes
		if ( compteur2 == 2 ) {
				constant = 1;
				del_on(VERT);
		}
		
		//combien de fois on check si la distance = rayon max de la piece
		if (constant) {
				compteur4++;
		}

		//apres que la distance ait déjà été constante une fois, on regarde
		//si la distance correspond au rayon max de la piece
		if ( constant && (valeurSuivante < 110 && valeurSuivante > 100) ) {
				compteur3++;
		}

		//si detecte 4 fois que la distance = rayon max de la piece
		if ( constant && compteur3 == 4) {
				del_on(ROUGE); //Octogone
				moteur.arreter();
				break;
		}
		
		//si apres 8 calculs la distance != rayon max de la piece
		if ( constant && compteur4 == 8) {
				del_on(VERT); //Cercle
				moteur.arreter();
				break;
		}

		donnee = convertisseur.lecture(0) >> 2;
		uart_send(donnee);
	}*/

}
