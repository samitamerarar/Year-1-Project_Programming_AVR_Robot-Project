/*
 * Nom: compteur 32 bits
 * Copyright (C) 2005 Matthew Khouzam
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est un exemple simple de programme 
 * Version: 1.1
 */

#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h> 

int main()
{
  DDRD = 0x00; // PORT D est en mode entree
  DDRC = 0xff; // PORT C est en mode sortie
  
  PORTC = 0x00;
  
  for(;;)
  {
      if (PIND & 0x04)
      {
        _delay_ms(10);
        while (PIND & 0x04)
        {
          PORTC = 0x01;
          _delay_ms(18);
          
          PORTC = 0x02;
          _delay_ms(2);
        }
        PORTC = 0x00;
      }
  }  
  return 0; 
}

