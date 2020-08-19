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
  DDRD = 0xff; // PORT D est en mode sortie  

  for(;;)  // boucle sans fin
  {
    PORTD = 0x01;
    _delay_ms (1000);
    
    PORTD = 0x02;
    _delay_ms (1000);
    
    for(int i = 0;i < 50;i++)
    {
        PORTD = 0x01;        
        _delay_ms (18);
        
        PORTD = 0x02;
        _delay_ms (2);
    }
    
    PORTD = 0x00;
    _delay_ms (1000);
  }
  return 0; 
}

