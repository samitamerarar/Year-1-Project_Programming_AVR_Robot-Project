///////////////////////////////////////////////////////////////////////////////////////////////////
//probleme1:pb1.cpp
//Description:controle de la DEL a l aide du bouton poussoir blanc situe sur le breadBoard 
//Nom :Maroua Djaroud & El hajla Asmae

///////////////////////////////////////////////////////////////////////////////////////////////////

#define F_CPU 8000000
#include <avr/io.h> //contient les définitions des entrées/sorties 
#include <util/delay.h> //Contient la fonction _delay_ms()pour créer des retards
#include <avr/interrupt.h>

#define MAX_COMPT 120
#define RELACHER 0
#define APPUYER 1

volatile uint8_t boutonPoussoir=0;
uint8_t compteur =0;


ISR(INT0_vect)
{	
	boutonPoussoir= APPUYER;
	
	//anti-rebond
	_delay_ms(10);
	
	//logique inverse
	if(~(PIND& 0x04))
	{
		boutonPoussoir= APPUYER;
				
	}
	else
		boutonPoussoir= RELACHER;


}

void initialisation()
{
//Pour bloquer les interruptions
   cli();

  DDRB = 0xff; //portB est en mode sortie
  DDRD = 0x00;  //portD est en mode entree

//ajustement du registre EIMSK
   EIMSK |= _BV(INT0);

   EICRA |= _BV(ISC00);
  
//Pour debloquer les interruptions    
  sei();
    
}

void incrementation()
{
	while  (compteur<MAX_COMPT && boutonPoussoir==RELACHER)
	{
		compteur+=10;
             _delay_ms(1000);
	}
        


}

void clignoterVert()
{
	for(int i=0; i< 10; i++)
	{	
		PORTB= 0x01; 
		_delay_ms(25);
		PORTB =0x00;
                _delay_ms(25);
	}

}

void clignoterRouge()
{
	for(int i=0; i< compteur/2; i++)
	{	
		PORTB= 0x02; 
		_delay_ms(250);
		PORTB =0x00;
		_delay_ms(250);
	}
}

void allumerVert()
{
	PORTB= 0x01; 
	_delay_ms(1000);
	PORTB =0x00;	
}

void delay()
{
	 PORTB=0x00;
	_delay_ms(2000);
}
int main()
{
	initialisation();
	  
	for(;;)
 	{	
            do {
	  } while (boutonPoussoir=RELACHER);

  
	incrementation();

  	clignoterVert();
	    delay();
	    clignoterRouge();
	    allumerVert();
	     	
	compteur=0;	
                

}
	return 0;	
}
