/* Nom: bouton.h
 * Auteurs: Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: transmission et reception de donnee entre le Pc et le robot
 * Version: 1.0
 */




#include <avr/io.h>
#define _BV(bit) (1 << (bit))

void initialisationUART(void);

void transmissionUART(uint8_t donnee);

uint8_t receptionUART(void);
