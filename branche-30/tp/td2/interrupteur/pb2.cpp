#include <avr/io.h> 
#include <util/delay.h> //Contient la fonction _delay_ms()pour créer des retards 
#define F_CPU 8000000
int main()
{
 DDRC= 0xff; // PORT C est en mode sortie
 DDRD = 0x00; // PORT D est en mode entree

 for(;;)
 PORTC=0x00;
 {
 if (PIND &0x04){
    while (PIND &0x04){

PORTC=0x02;//ambree
  _delay_ms(1);
  PORTC=0x01;
   _delay_ms(8);
 
}
_PORTC=0x00;
}

}
 return 0;
}
