#include "SystemeNavigation.h"

volatile int flag1 = 0;
volatile bool stop = false;

uint8_t turn_counter = 0;

char derniereCouleurLue;

SystemeNavigation::SystemeNavigation(void)
{
	cli();
	nbPieces = 0;
	nbMesures = 0;
	del_init();
	sound_init();
	etat = AVANCER;
	enMarche = true;
	sei();
}

SystemeNavigation::~SystemeNavigation(void) {}

bool SystemeNavigation::isEnMarche(void) const
{
	return enMarche;
}

void SystemeNavigation::demarrer(void)
{
	moteur.avancer(144, 144);
}

void SystemeNavigation::mettreAJour(void)
{
	switch (etat)
	{
		case AVANCER:
			ajuster();
			break;
		case IDENTIFICATION:
			captDistance.init();
			ajuster();
			determinerPiece();
			break;
		case RETOUR:			
			nbPieces = 0;
			ajuster();
			lireCouleurs();
			break;
		default:
			break;
	}
}

void SystemeNavigation::ajuster(void)
{
	//Le robot effectue les virages seulement si le capteur de centre
	//est actif
	if(suiveur.estCentre())
	{
		if(etat == RETOUR)
		{
			if(turn_counter == 5)
			{
				if(suiveur.tournerGauche())
				{				
					moteur.avancer(168, 64);
					
					_delay_ms(1000);
					loop_until_bit_is_set(LSS05_PIN, CAP2);
					_delay_ms(100);
					
					captCouleur.init();
				}
			}
		}
		else if(etat == AVANCER)
		{
			if(suiveur.tournerDroite())
			{
				turn_counter++;
				moteur.avancer(64, 168);
				
				_delay_ms(1000);
				loop_until_bit_is_set(LSS05_PIN, CAP4);
				_delay_ms(100);
				
				if(turn_counter % 2 == 1)
					etat = IDENTIFICATION;
			}
		}
	}
	//Si le capteur de centre n'est pas actif, ajuster les vitesses des
	//roues jusqu'à ce qu'il le devienne
	else
	{
		if(suiveur.augmenterVitesseRoueGauche())
			moteur.avancer(144, 200);
		
		if(suiveur.augmenterVitesseRoueDroite())
			moteur.avancer(200, 144);
			
		loop_until_bit_is_set(LSS05_PIN, CAP3);
	}
	moteur.avancer(144, 144);
}

void SystemeNavigation::determinerPiece(void)
{	
	uint16_t distance = captDistance.calculerDistanceMm();
	
	if(distance < 150)
	{
		moteur.arreter();
		captDistance.off();
		
		char piece = '\0';
		
		switch (nbPieces)
		{
			case 0:
				piece = BLEU;
				etat = AVANCER;
				break;
			case 1:
				piece = VERT;
				etat = AVANCER;
				break;
			case 2:
				piece = ROUGE;
				etat = RETOUR;
				break;
			default:
				break;
		}
		
		effectuerSequence(piece);
		
		pieces[nbPieces++] = piece;
		
		moteur.tourner(134, 134, DROITE);
		
		_delay_ms(1000);
		
		loop_until_bit_is_set(LSS05_PIN, CAP4);
		loop_until_bit_is_set(LSS05_PIN, CAP3);
	}
}

void SystemeNavigation::lireCouleurs(void)
{	
	char couleur = captCouleur.getCouleur();	
	
	if(couleur != derniereCouleurLue)
	{
		if(couleur == pieces[nbPieces])
			nbPieces++;
		else
			nbPieces = 0;
			
		derniereCouleurLue = couleur;
	}
	
	if(nbPieces == NOMBRE_PIECES_MAX)
		enMarche = false;
}

void SystemeNavigation::effectuerSequence(char couleur)
{
	switch (couleur)
	{
		case ROUGE:
			sequenceOctogone();	//declarée dans del.h
			break;
		case VERT:
			sequenceCercle();	//declarée dans del.h
			break;
		case BLEU:
			//sequenceCercle();
			sequenceCarre();	//declarée dans son.h
			break;
		default:
			break;
	}
}

char SystemeNavigation::analyserMesures(void)
{
	char piece;
	
	uint8_t compteur = 0;
	uint16_t moyenne = 0;
	
	for (int i = 0; i < nbMesures; i++)
	{
		if(mesures[i] > 245 && mesures[i] <= 255)
			compteur++;
			
		moyenne += mesures[i];
	}
	
	moyenne /= nbMesures;
	
	if(moyenne > 235)
		piece = 's';
		
	else if(compteur > 30)
		piece = 'o';
	
	else
		piece = 'c';
		
	return piece;
}

void SystemeNavigation::prendreMesures(uint8_t mesure)
{
	mesures[nbMesures++] = mesure;
}

void SystemeNavigation::partirMinuterie(void)
{
	TCNT2 = 5;
	TCCR2A = 0;
	TCCR2B = _BV(CS21);
	TIMSK2 = _BV(TOIE2);
}

ISR(TIMER2_OVF_vect)
{
	TCNT2 = 5;
	flag1++;
	
	if(flag1 == 18000)
	{
		stop = true;
		TIMSK2 = 0;
		TCCR2B = 0;
	}
}
