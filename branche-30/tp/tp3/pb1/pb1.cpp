///////////////////////////////////////////////////////////////////////////////////////////////////
//probleme1:test.cpp
//Description: Allumer la DEL en appuyant et en relâchant le bouton-poussoir 5 fois del tourne en rouge
// pendant 1 seconde.
//Nom :Maroua Djaroud & El hajla Asmae
///////////////////////////////////////////////////////////////////////////////////////////////////

//Table d'états:

//////////////////////////////////////////////////////////////////////////////////////////////
// ETAT PRESENT  // BOUTON 	//  COMPTEUR	  // ETAT SUIVANT // SORTIE Z  /
//////////////////////////////////////////////////////////////////////////////////////////////
// init		//	0	//       0      //	init       //	0    /
// init		//	1	//       1      //      init       //	0    /
 
// init		//	0	//       1      //	init      //	0    /
// init		//	1	//       2     //       init      //	0    /

// init		//	0	//       2     //	init       //	0    /
// init		//	1	//       3     //       init      //	0    /

// init		//	0	//       3    //	init       //	0    /
// init		//	1	//       4     //       init      //	0    /

// init		//	0	//       4     //     allumer   //	0    /
// allumer      //	1	//       5    //       init      //	1    /

 

//////////////////////////////////////////////////////////////////////////////////////////////
#define F_CPU 8000000
#include <avr/io.h> //contient les définitions des entrées/sorties 
#include <util/delay.h> //Contient la fonction _delay_ms()pour créer des retards 



 int main(void) 
{   
  DDRC = 0xff; //portA est en mode sortie
  DDRD = 0x00;  //portC est en mode entree
int compteur=0;

enum etats {init, allumer};
etats cur=init;

for(;;) { //boucle infinie
       switch (cur)
       {
         case init:

           for(int i=0;i<4;i++){
             if (PIND & 0x04)
              {
                 while (PIND & 0x04)
                 {}

                   compteur++;

                   if (compteur==5)
                    {
                      cur=allumer;

                    }
              }
            } break;

        case allumer:

            PORTC=0x01;
            _delay_ms(1000.0);//attendre 1sec
            PORTC=0x00;
            cur=init;
            compteur=0;
            break;



         default :
           break;

} 
}
return 0;  
 }

