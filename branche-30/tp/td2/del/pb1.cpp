#include <avr/io.h> 
#include <util/delay.h> //Contient la fonction _delay_ms()pour créer des retards 
#define F_CPU 8000000
int main()
{
 DDRC= 0xff; // PORT C est en mode sortie
 DDRD = 0xff; // PORT D est en mode entree
 
 for(;;)
 {

 PORTC=0x02;//rouge
 _delay_ms(3000);
 
 PORTC=0x01;//vert
 _delay_ms(3000);
 
 for ( unsigned long i=0;i<100;i++)
 {
PORTC=0x02;//ambree
  _delay_ms(1);
  PORTC=0x01;
   _delay_ms(8);
 
}
_delay_ms(3000);
}
 return 0;
}
