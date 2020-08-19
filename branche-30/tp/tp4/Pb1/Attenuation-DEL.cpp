///////////////////////////////////////////////////////////////////////////////////////////////////
//probleme1:Pb1.cpp
//Description: Problème 1: Atténuation d'une DEL
//
//Nom :Maroua Djaroud & El hajla Asmae
///////////////////////////////////////////////////////////////////////////////////////////////////



#define F_CPU 8000000

#include <avr/io.h> //contient les définitions des entrées/sorties 
#include <util/delay.h> //Contient la fonction _delay_ms()pour créer des retards 

int main ()
{
DDRC = 0xff; //port Cest en mode sortie
DDRD = 0x00;  //portD est en mode entree

for (;;)
{
    uint16_t time=3000; //3secondes

    //ROUGE 

    for (uint16_t i=time;i>0;i--)//diminuer le temps
    {

        PORTC=0x02;
        for (uint16_t j=0;j<i/30;j++){
            _delay_us(10);
        }

         PORTC=0x00;

         for (uint16_t j=0;j<(time-i)/30;j++){
             _delay_us(10);
         }
        }
   _delay_ms(500);

   //VERT
    for (uint16_t i=time;i>0;i--)//diminuer le temps
{
    
    PORTC=0x01;
    for (uint16_t j=0;j<i/30;j++){
        _delay_us(10);
    }

     PORTC=0x00;

     for (uint16_t j=0;j<(time-i)/30;j++){
         _delay_us(10);
     }
    }
    _delay_ms(500);

}



return 0 ;
}
