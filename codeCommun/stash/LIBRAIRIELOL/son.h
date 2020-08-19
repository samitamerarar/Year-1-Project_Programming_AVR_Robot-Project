/* Nom: bouton.h
 * Auteurs: Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: controle de son
 * Version: 1.0
 */



#define F_CPU 8000000
#define _BV(bit) (1 << (bit))
#include <avr/io.h>
#include <math.h>

void initialiserSon(void);

void jouerNote(uint8_t son);

void arreterSon(void);
