/*
 * Nom: Probleme 1
 * Description: Atténuer une DEL en 3 seconde
 * Version: 1.0
 * Auteurs : Tamer Arar et Guy-Frank Essome Penda
 */

#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h> 

int main()
{
  DDRC = 0xff; // PORT C est en mode sortie

  uint16_t tempsRouge = 50000;
  uint16_t tempsEteint = 0;
  uint16_t duree = 400;

  PORTC = 0x01;

  while(tempsRouge > 0){
    PORTC = 0x01;

    _delay_loop_2(tempsRouge);

    PORTC = 0x00;

    _delay_loop_2(tempsEteint);

    tempsRouge-=duree;
    tempsEteint+=duree;
  }
  return 0; 
}

