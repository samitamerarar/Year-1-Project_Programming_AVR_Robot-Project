///////////////////////////////////////////////////////////////////////////////////////////////////
//probleme1:Pb2.cpp
//Description: Problème 2: Contrôle des moteurs du robot
//
//Nom :Maroua Djaroud & El hajla Asmae
///////////////////////////////////////////////////////////////////////////////////////////////////




#include <avr/io.h> //contient les définitions des entrées/sorties 
#include <util/delay.h> //Contient la fonction _delay_ms()pour créer des retards 
#define F_CPU 8000000

void delay_ms(uint8_t delais)
{
   for (uint8_t i=0;i<delais;i++){
      _delay_ms(1);//pour avoir 1khz
   }
}

void delay_us(uint16_t delais)
{
   for (uint16_t i=0;i<delais;i++){
      _delay_us(25);
   }
}

int main ()
{
    DDRC = 0xff; //port Cest en mode sortie
    DDRD = 0x00;  //portD est en mode entree
for (;;)
{
    //pour 60Hz
    uint8_t time1 =118; // calcul : 2000ms/(1/60Hz)= 118ms
    
    for (uint8_t i= 0; i<=17; i=i+4.25)
    {
        for (uint16_t j=time1;j>0;j--)//diminuer le temps
    {

        PORTC=0x02;

          delay_ms(i/1);


         PORTC=0x00;

          delay_ms((17-i)/1);

        }
        
    }
    //pour 400Hz
    uint16_t time2 =800; // calcul : 2000ms/(1/400Hz)= 800ms
    
    for (uint16_t i= 0; i<=2500; i=i+625)
    {
        for (uint16_t j=time2;j>0;j--)//diminuer le temps
    {

        PORTC=0x02;

         delay_us(i/25);


         PORTC=0x00;


          delay_us((2500-i)/25);

        }
        
    }
    
}
return 0;

}
