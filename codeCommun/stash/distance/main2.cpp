#define F_CPU 8000000
#define _BV(bit) (1 << (bit))
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <del.h>

/////////////////////////////////


volatile bool arreterRobot = 0;    //booléen permet l'arret du robot
volatile float valeurMinArreter = 11; //valeur minimale requise pour que le robot s'arrete

void initCapteurDistance(void)
{
	cli();

	/*PORTD &= ~_BV(PD1);	//entrée
	PORTD |= ~_BV(PD0);	//sortie*/
	
	
	
	arreterRobot = 0;
	EIMSK |= _BV(INT0);	// Registre activant le bit pour l'interrupt 0
	EICRA |= _BV(ISC01) | _BV(ISC00); // Signal qui active l'interruption : Rising Edge
	
	sei();
}

ISR (INT0_vect)
{
	_delay_ms(30);
	if(valeurMinArreter == calculerDistance(voltageOut))
	{
	      arreterRobot = 1;
	}
}

int main()
{		
	float voltageOut = 0.0;
	float distance = 0.0; //en cm
	string piece = "";

	initCapteurDistance();
	initTableauEnregistrerPieces();

	avancer(50);
	tourner(DROITE);
	_delay_ms(1000);

	
	
	while (arreterRobot)
		switch (piece)
		{
			case CARRE:
				initialiserSon();
				jouerNote(80);
				_delay_ms(2000);
				arreterSon();
				arreterRobot = 0;
				enregistrerPiece('C');
				break;

			case CERCLE:
				allumerDel(VERT);
				_delay_ms(2000);
				arreterRobot = 0;
				enregistrerPiece('O');
				break;

			case OCTOGONE:
				allumerDel(ROUGE);
				_delay_ms(2000);
				arreterRobot = 0;
				enregistrerPiece('G');
				break;

			default:
				break;
		}
	
	
}

float calculerDistance(int voltage)
{
	if (voltage > 0.52 && voltage < 2.62) {
		float distanceCalcul = 0.0;

		//constante pour l'inverse de la distance (GP2D12)
		float k = 0.42 

		/* y = ax + b */
		int a = 24; //taux de variation 12.48
		float b = 0.22  //calibre l'ordonnée à l'origine 135.38

		//y = ax + b -> Voltage = a(1/distance + k) + b 
		//(1/((Voltage - b)/ a)) - k = distance
		//(1/((Voltage - b)/ 24)) - k = distance
	
		distanceCalcul = (1/((voltage - 0.22)/ a)) - 0.42;
	}

}




