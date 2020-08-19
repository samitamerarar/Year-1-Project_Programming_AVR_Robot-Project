#ifndef CAPT_H
#define CAPT_H

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "can.h"

#define GP2D12_DDR DDRA
#define GP2D12_PIN PINA0
#define GP2D12_DISTANCE_MAX 80
#define GP2D12_DISTANCE_MIN 10

class CapteurDistance
{
	public:
		CapteurDistance(void);
		~CapteurDistance(void);
		
		void init(void);
		
		void off(void);
		
		uint16_t calculerDistanceMm(void);
		
	private:
		can convertisseur;
		uint8_t getNumValue(void);
		uint8_t getVoltage(void);
};

#endif
