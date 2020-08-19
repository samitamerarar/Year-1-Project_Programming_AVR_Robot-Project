#include "CapteurDistance.h"
#include "uart.h"

void CapteurDistance::init(void)
{
	GP2D12_DDR &= ~_BV(GP2D12_PIN);	//en mode entrée pour initialisation
}

void CapteurDistance::off(void)
{
	GP2D12_DDR |= _BV(GP2D12_PIN);	//en mode sortie
}

CapteurDistance::CapteurDistance(void)
{
	off();
}

CapteurDistance::~CapteurDistance(void){}

uint8_t CapteurDistance::getNumValue(void)
{
	uint8_t value = convertisseur.lecture(GP2D12_PIN) >> 2;
	return value;
}

uint8_t CapteurDistance::getVoltage(void)
{
	int average = 0;
	int value = 0;
	
	for (int i = 0; i < 10; i++)
	{
		value = getNumValue();
		average += value;
		_delay_ms(5);
	}
	
	average /= 10;
	
	return average;
}

uint16_t CapteurDistance::calculerDistanceMm(void)
{	
	const float m = 2914.0;
	const float b = 5.0;
	const float k = 1.0;
	
	int voltage = getVoltage();
	
	float distance = (m / ((float) voltage + b) - k) * 10;
	
	return (int) distance;	
}
