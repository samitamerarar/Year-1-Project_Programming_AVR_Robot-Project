#include "CapteurCouleur.h"
#include "uart.h"

volatile uint8_t counter = 0, countR, countV, countB, countC;
volatile uint8_t flag = 0;

CapteurCouleur::CapteurCouleur(void){}

CapteurCouleur::~CapteurCouleur(void) {};

void CapteurCouleur::init(void)
{
	//output rate: 100%, LED on
	TCS_PORT = _BV(S0) | _BV(S1) | _BV(LED);
	
	filtresClairs();
	
	//S0-S3 in output mode, out in input mode
	TCS_DDR = (_BV(S0) | _BV(S1) | _BV(S2) | _BV(S3) | _BV(LED)) & ~_BV(OUT);
	
	//trigger external interrupt on rising edge INT2
	EICRA = _BV(ISC20) | _BV(ISC21);
	
	//enable interrupt on INT2
	EIMSK = _BV(INT2);
	
	timer0_init();
}

void CapteurCouleur::timer0_init(void)
{
	TCNT0 = 5;	
	TIMSK0 = _BV(TOIE2);
	TCCR0A = 0;
	TCCR0B = _BV(CS21);
}

char CapteurCouleur::getCouleur(void)
{		
	if(countC < 190)
	{		
		if(countR > countV && countR > countB)
			return ROUGE;

		if(countV > countR && countV > countB)
			return VERT;

		if(countB > countV && countB > countR)
			return BLEU;	
	}	
	return CLAIR;
}

ISR(TIMER0_OVF_vect)
{	
	TCNT0 = 5;
	flag++;
	
	if(flag == 40)
	{
		countC = counter;
		filtresRouges();
		counter = 0;
	}
	else if(flag == 80)
	{
		countR = counter;
		filtresVerts();
		counter = 0;
	}
	else if(flag == 120)
	{
		countV = counter;
		filtresBleus();
		counter = 0;
	}
	else if(flag == 160)
	{
		countB = counter;
		filtresClairs();
		counter = 0;
		flag = 0;
	}	
}

ISR(INT2_vect)
{
	counter++;
}
