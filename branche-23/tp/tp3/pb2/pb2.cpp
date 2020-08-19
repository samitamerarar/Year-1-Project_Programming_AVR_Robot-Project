/*
 * Nom: Probleme 2
 * Description: Changer la couleur de la DEL en poussant et en relachant le bouton-poussoir.
 * Version: 1.0
 * Auteurs : Tamer Arar et Guy-Frank Essome Penda
 * | ETAT | PROCHAIN ETAT |    SORTIE    |
 * |______|___0___|___1___|_ROUGE_|_VERT_|
 * | INIT | INIT  |  AMB  |    1  |   0  |
 * |------|-------|-------|-------|------|
 * | AMB  | VERT1 |  AMB  |    1  |   1  |
 * |------|-------|-------|-------|------|
 * | VERT1| VERT1 | ROUGE |    0  |   1  |
 * |------|-------|-------|-------|------|
 * | ROUGE| ETEINT| ROUGE |    1  |   0  |
 * |------|-------|-------|-------|------|
 * |ETEINT| ETEINT| VERT2 |    0  |   0  |
 * |------|-------|-------|-------|------|
 * | VERT2| INIT  | VERT2 |    0  |   1  |
 * |______|_______|_______|_______|______|
 */

#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h> 

enum Etat{INIT, AMB, VERT1, ROUGE, ETEINT, VERT2};

int main()
{
	DDRC = 0xff; // PORT C est en mode sortie
	DDRD = 0x00; // PORT D est en mode entree

	Etat etatActif = INIT;

	for (;;)  // boucle sans fin
	{
		switch (etatActif)
		{
		case INIT:            
			PORTC = 0x02;
            
			if (PIND & 0x04)                
                etatActif = AMB;
			break;
		case AMB:
			while (PIND & 0x04)
			{
				PORTC = 0x02;
				_delay_ms(2);

				PORTC = 0x01;
				_delay_ms(18);
			}
			etatActif = VERT1;
			break;
		case VERT1:
			PORTC = 0x01;
            
			if (PIND & 0x04)
                etatActif = ROUGE;
			break;
		case ROUGE:
			PORTC = 0x02;
            
			while (PIND & 0x04){}
			
            etatActif = ETEINT;
			break;
		case ETEINT:
			PORTC = 0x00;
            
			if (PIND & 0x04)
                etatActif = VERT2;
			break;
		case VERT2:
            PORTC = 0x01;
            
            while (PIND & 0x04){}
            
            etatActif = INIT;
			break;
		default:
			break;
		}
	}
	return 0;
}
