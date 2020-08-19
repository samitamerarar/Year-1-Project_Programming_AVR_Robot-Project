/*
 * Nom: Probleme 2
 * Description:
 * Version: 1.0
 * Auteurs : Tamer Arar et Guy-Frank Essome Penda
 */

#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h> 

int main()
{
  DDRC = 0xff;

  uint16_t frequence60Hz = 4167;
  uint16_t intensite25 = frequence60Hz/4;
  uint16_t intensite50 = frequence60Hz/2;
  uint16_t frequence400Hz = 625;



  for(;;){
    PORTC = 0x00;
    for(int i = 0;i<960;i++)
      _delay_loop_2(frequence60Hz);

    for(int i = 0;i<960;i++){
      PORTC = 0xff;
    
      _delay_loop_2(intensite25);

      PORTC = 0x00;

      _delay_loop_2(frequence60Hz-intensite25);
    }

    for(int i = 0;i<960;i++){
      PORTC = 0xff;
    
      _delay_loop_2(intensite50);

      PORTC = 0x00;

      _delay_loop_2(frequence60Hz-intensite50);
    }

    for(int i = 0;i<960;i++){
      PORTC = 0xff;
    
      _delay_loop_2(frequence60Hz-intensite25);

      PORTC = 0x00;

      _delay_loop_2(intensite25);
    }

    PORTC = 0xff;

    for(int i = 0;i<960;i++)
      _delay_loop_2(frequence60Hz);
  }
  
  return 0;
}
