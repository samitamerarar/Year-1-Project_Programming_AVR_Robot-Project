/*
 * Nom: Probleme 1
 * Description: Allumer la DEL pendant une seconde apres avoir appuye 5 fois sur le bouton poussoir.
 * Version: 1.0
 * Auteurs : Tamer Arar et Guy-Frank Essome Penda
 * | ETAT | PROCHAIN ETAT | SORTIE |
 * |______|___0___|___1___|________|
 * |  S0  |   S0  |   S1  |    0   |
 * |------|-------|-------|--------|
 * |  S1  |   S0  |   S0  |    1   |
 * |______|_______|_______|________|
 */

#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h> 

int main()
{
  DDRD = 0x00; // PORT D est en mode entree
  DDRC = 0xff; // PORT C est en mode sortie
  int compteur = 0;

  for(;;)  // boucle sans fin
  {
    PORTC = 0x00;
    
    if(PIND & 0x04)
    {
        _delay_ms(10);
        while(PIND & 0x04) {}
        
        compteur++;
            
        if(compteur == 5)
        {
            PORTC = 0x01;
                
            for(int i = 0;i < 4;i++){_delay_ms(250);} //delai d'une seconde
                
            PORTC = 0x00;
                
            compteur = 0;
        }
        
    }
  }
  return 0; 
}

