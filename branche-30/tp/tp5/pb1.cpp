///////////////////////////////////////////////////////////////////////////////////////////////////
//probleme1:pb2.cpp
//Description: Allumer la DEL en appuyant et en relâchant le bouton-poussoir 5 fois del tourne en rouge
// pendant 1 seconde.
//Nom :Maroua Djaroud & El hajla Asmae
///////////////////////////////////////////////////////////////////////////////////////////////////#define F_CPU 8000000#include <avr/io.h> //contient les définitions des entrées/sorties 
#include <util/delay.h> //Contient la fonction _delay_ms()pour créer des retards 
#include <avr/interrupt.h>: Interrupts

volatile  uint8_t etat;//macherevariable

ISR ( INT0_vect) {

// placer le bon type de signal d'interruption

// a prendre en charge en argument

ISR ( 'modifier ici' ) {

// laisser un delai avant de confirmer la reponse du

// bouton-poussoir: environ 30 ms (anti-rebond)

_delay_loop_ms ( 30 );

// Se souvenir ici si le bouton est presse ou relache

'modifier ici'

// changements d'etats tels que ceux de la semaine /usagers/aselh/inf1995/tp4/Pb2/Makefile/usagers/aselh/inf1995/tp4/Pb2/Makefile

// Voir la note plus bas pour comprendre cette instruction et son role

EIFR |= (1 << INTF0) ;

}
void initialisation ( void ) {

// cli est une routine qui bloque toutes les interruptions.

// Il serait bien mauvais d'etre interrompu alors que

// le microcontroleur n'est pas pret...

cli ();


// configurer et choisir les ports pour les entrees

// et les sorties. DDRx... Initialisez bien vos variables

'modifier ici'


// cette procédure ajuste le registre EIMSK

// de ATmega324PA pour permettre les interruptions externes

EIMSK |= _BV(INT0);


// il faut sensibiliser les interruptions externes aux

// changements de niveau du bouton-poussoir

// en ajustant le registre EICRA

EICRA |= 'modifier ici' ;


// sei permet de recevoir a nouveau des interruptions.

sei ();
}
enum etats {ambre, vert1, eteinte,rouge1,rouge2 };

int main ()
{
DDRC = 0xff; //port Cest en mode sortie
DDRD = 0x00;  //portD est en mode entree
etats etat= rouge;


for (;;)
{
    switch (etat)
    {

         case rouge1:

            PORTD=0x02;
            etat=ambre;
         break;

        case ambre:
          if(PIND & 0x04){
                    PORTD=0x02;
                    _delay_ms(1);
                    PORTD=0x01;
                    _delay_ms(8);

                }
          if(!(PIND & 0x04))
              etat=vert1;
            break;

        case vert1:
            PORTD=0x01;
            etat=rouge2;
            break;

        case rouge2:
            PORTD=0x02;
            if(!(PIND & 0x04))
                 etat=eteinte;
            break;

        case eteinte:
            PORTD=0x00;
            if(PIND & 0x04)
                etat=vert2;
            break;

        case vert2:
            PORTD=0x02;
            if(!(PIND & 0x04))
                etat=rouge1;
            break;
    }

return 0;
}
