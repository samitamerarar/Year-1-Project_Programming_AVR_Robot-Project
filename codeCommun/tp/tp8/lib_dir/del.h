/* Nom: del.h
 * Auteurs: Guy-Frank et Tamer Arar
 * Description: Contrôle le comportement de la del
 * Version: 1.0
 */

#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>

#define DEL PORTC
#define ROUGE 0x01
#define VERT 0x02
#define ETEINT 0x00

void allumerDel(char couleur);

void couleurAmbree();
