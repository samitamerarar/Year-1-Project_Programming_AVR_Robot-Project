#define F_CPU 8000000
#define _BV(bit) (1 << (bit))
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void initialitisationBouton();

void partirMinuterie (uint16_t duree);
