///////////////////////////////////////////////////////////////////////////////////////////////////
//probleme1:pb2.cpp
//Description: La DEL doit etre rouge au départ. Ensuite,lorsqu'on appuit sur le bouton poussoir,
//la couleur devient ambre, lorsqu'on le relache, la couleur change au vert. Lorsqu'on appuit de nouveau,
//la DEL devient rouge, et elle s'etteint lorsqu'on relache. Elle devient verte une fois appuyé et rouge
//lorsqu'on relache.
//Nom :Maroua Djaroud & El hajla Asmae
///////////////////////////////////////////////////////////////////////////////////////////////////

//Table d'états:

//////////////////////////////////////////////////////////////////////////////////////////////
// ETAT PRESENT  // BOUTON 	 // ETAT SUIVANT     // SORTIE DEL  /
//////////////////////////////////////////////////////////////////////////////////////////////
// rouge1	//	0        //	rouge1       //	rouge    /
// rouge1	//	1	 //     ambre        //	ambre    /

// ambre	//	1	 //	ambre        //	 ambre   /
// ambre	//	0        //     vert1        //	 vert    /

// vert1	//	0	 //     vert1        //	 vert    /
// vert1	//	1	 //     rouge2       //	 rouge   /

// rouge2	//	1	//      rouge2       //	 rouge   /
// rouge2	//	0	//      eteinte      //  eteint  /

// eteinte	//	0	//      eteinte      //  eteint  /
// eteinte      //	1	//      vert2        //  vert    /

// vert2	//	1	//       vert2       //	 vert    /
// vert2	//	0	//       rouge1      //  rouge   /
////////////////////////////////////////////////////////////////////////////////////////////////

#define F_CPU 8000000
#include <avr/io.h> //contient les définitions des entrées/sorties 
#include <util/delay.h> //Contient la fonction _delay_ms()pour créer des retards 

enum etats {rouge1, ambre, vert1, eteinte, vert2,rouge2 };
int main ()
{
DDRC = 0xff; //port Cest en mode sortie
DDRD = 0x00;  //portD est en mode entree
etats etat= rouge1;


for (;;)
{
    switch (etat)
    {

         case rouge1:

            PORTC=0x02;
            if(PIND & 0x04)
                etat=ambre;
             break;

        case ambre:
          {
                    PORTC=0x02;
                    _delay_ms(1);
                    PORTC=0x01;
                    _delay_ms(8);

                }
          if(!(PIND & 0x04))
              etat=vert1;
            break;

        case vert1:
            PORTC=0x01;
            if(PIND & 0x04)
                etat=rouge2;
            break;

        case rouge2:
            PORTC=0x02;
            if(!(PIND & 0x04))
                 etat=eteinte;
            break;

        case eteinte:
            PORTC=0x00;
            if(PIND & 0x04)
                etat=vert2;
            break;

        case vert2:
            PORTC=0x01;
            if(!(PIND & 0x04))
                etat=rouge1;
            break;
    }
}
return 0;
}
