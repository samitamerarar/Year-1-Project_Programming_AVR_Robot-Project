/* Nom: del.h
 * Auteurs: Guy-Frank et Tamer Arar , Asmae el hajla et maroua djaroud
 * Description: Contrôle le comportement de la del
 * Version: 1.0
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

#define DEL_DDR DDRD
#define DEL_PORT PORTD
#define DEL_PIN1 PD2
#define DEL_PIN2 PD3
#define ROUGE 'r'	//0x40	//PA6
#define VERT 'v'	//0x80	//PA7
#define ETEINT 'e'
//la definition des fonctions

void del_init(void);

void del_on(char couleur);

void del_off(void);

void sequenceOctogone(void);

void sequenceCercle(void);
