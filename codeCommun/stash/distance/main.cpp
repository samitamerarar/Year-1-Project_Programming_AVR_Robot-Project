#define F_CPU 8000000
#define _BV(bit) (1 << (bit))
#include <util/delay.h>
#include <avr/io.h>
#include "CapteurDistance.h"
#include "del.h"

int main()
{
	CapteurDistance captD;
	initialiserDel();
	
	while(1)
	{
		if(captD.getDistance() > 10.0 && captD.getDistance() < 20.0)
			allumerDel(VERT);
	}
}
