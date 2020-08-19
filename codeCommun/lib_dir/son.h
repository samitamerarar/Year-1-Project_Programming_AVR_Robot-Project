/* Nom: bouton.h
 * Auteurs: Guy-Frank , Tamer Arar, Maroua Djaroud et  Asmae El hajla
 * Description: controle de son
 * Version: 1.0
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <math.h>

#define SOUND_DDR DDRD
#define SOUND_PORT PORTD
#define SOUND_PIN0 PD0
#define SOUND_PIN1 PD1

void sound_init(void);

void sequenceCarre(void);
