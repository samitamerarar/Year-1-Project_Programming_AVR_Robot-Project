#include <avr/io.h>
#include <avr/interrupt.h>

#define TCS_PORT PORTB
#define TCS_DDR DDRB
#define S0 PB0
#define S1 PB1
#define OUT PB2
#define LED PB3
#define S2 PB4
#define S3 PB5

#define CLAIR 'c'
#define ROUGE 'r'
#define VERT 'v'
#define BLEU 'b'

#define filtresClairs() TCS_PORT |= _BV(S2) & ~_BV(S3);
#define filtresRouges() TCS_PORT &= ~_BV(S2) & ~_BV(S3);
#define filtresVerts() TCS_PORT |= _BV(S2) | _BV(S3);
#define filtresBleus() TCS_PORT &= ~_BV(S2) | _BV(S3);

class CapteurCouleur
{
	public:
		CapteurCouleur(void);
		~CapteurCouleur(void);
		
		void init(void);
		
		char getCouleur(void);
	
	private:		
		void timer0_init(void);
};
