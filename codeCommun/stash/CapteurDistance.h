#define F_CPU 8000000UL
#include <util/delay.h>
#include "can.h"

class CapteurDistance
{
	public:
		CapteurDistance(void);
		~CapteurDistance(void);
		
		int getDistance(void);
		//string trouverPiece(void);
		
	private:
		can convertisseur;
};
