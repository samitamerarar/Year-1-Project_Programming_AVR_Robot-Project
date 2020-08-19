///////////////////////////////////////////////////////////////////////////////////////////////////
//probleme2:main.cpp
//Description:controle de la DEL 
//Nom :Maroua Djaroud & El hajla Asmae

///////////////////////////////////////////////////////////////////////////////////////////////////

#define F_CPU 8000000
#include <avr/io.h> //contient les définitions des entrées/sorties 
#include <util/delay.h> //Contient la fonction _delay_ms()pour créer des retards
#include <avr/interrupt.h>

#include "can.h"
#include <util/delay.h>


//variable globale 
//bornes
 #define AMBIANT_MAX 235
 #define AMBIANT_MIN 80

 #define PORT 2// ou le capteur est branché
 volatile uint8_t valeurNum; // recuperer la valeur numerique 
void initialisation()
{
 DDRB = 0xff; //portB est en mode sortie
 DDRA = 0x00;  //portA est en mode entree
 valeurNum =0;
}


int main ()
{
    initialisation();
    
    // declaration de l'OBJET 
    can can;
    
    for(;;)      //boucle sans fin
    {
        //la valeur numerique venant du can est sur 10 bit
        //On la met sur 8bits en eliminant les 2 derniers bits
        //pour simplifier le calcul
        valeurNum = (((can.lecture(PORT)) >> 2) & 0xff); //decalage a gauche, puis le & binaire pour garder que 8 bits
     
        //compare la valeur renvoyee par le can et des bornes fixees

        if(valeurNum > AMBIANT_MAX) 
        { 
           
           PORTB = 0x02;//allumage rouge

            
        }
        else if((valeurNum > AMBIANT_MIN) && (valeurNum < AMBIANT_MAX))  
        {
             
               PORTB = 0x02;
              _delay_ms(2);  
              PORTB = 0x01;
              _delay_ms(10);  
              //allumeAmbre
        }
        else if (valeurNum < AMBIANT_MIN)
        { 
           PORTB = 0x01;// allumeVert();
        }
    }
    
    return 0;
}

