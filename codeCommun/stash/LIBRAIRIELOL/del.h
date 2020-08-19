/* Nom: del.h
 * Auteurs: Guy-Frank et Tamer Arar , Asmae el hajla et maroua djaroud
 * Description: Contrôle le comportement de la del
 * Version: 1.0
 */

#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>

#define _BV(bit) (1 << (bit))
#define DEL PORTA
#define ROUGE 0x40	//PA6
#define VERT 0x80	//PA7
#define AMBREE 0x03
#define ETEINT 0x3F
//la definition des fonctions

void initialiserDel(void);

void allumerDel(uint8_t couleur);

void eteindreDel(void);

void couleurAmbree(void);
