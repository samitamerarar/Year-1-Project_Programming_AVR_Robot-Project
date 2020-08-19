  /*****************************************************************************
  Colour Sensor TCS3200 Demo Program
  
  HARDWARE
  --------
  MCU = ATmega32 Running at 16MHz Crystal (LFUSE=0xFF HFUSE=0xC9)
  
  DISPLAY = 16x2 LCD Module
  *************************
  
  LCD   | ATmega32
  RS  -> PD3
  R/W -> PD6
  E   -> PB4
  DB0 ->
  DB1 ->
  DB2 ->
  DB3 ->
  DB4 -> PB0
  DB5 -> PB1
  DB6 -> PB2
  DB7 -> PB3
  
  TCS3200 Module
  **************
  
        ATmega32
  S2 -> PA0
  S3 -> PA1
  OUT ->PA3
  LED ->PA4
  
  BUZZER -> PD7
  
  
  
  NOTICE
  --------
  NO PART OF THIS WORK CAN BE COPIED, DISTRIBUTED OR PUBLISHED WITHOUT A
  WRITTEN PERMISSION FROM EXTREME ELECTRONICS INDIA. THE LIBRARY, NOR ANY PART
  OF IT CAN BE USED IN COMMERCIAL APPLICATIONS. IT IS INTENDED TO BE USED FOR
  HOBBY, LEARNING AND EDUCATIONAL PURPOSE ONLY. IF YOU WANT TO USE THEM IN
  COMMERCIAL APPLICATION PLEASE WRITE TO THE AUTHOR.


  WRITTEN BY:
  AVINASH GUPTA
  gmail@avinashgupta.com (Yes ! It's correct !)
*******************************************************************************/

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include "tcs3200.h"
#include "uart.h"

uint32_t MeasureR();
uint32_t MeasureG();
uint32_t MeasureB();
uint32_t MeasureC();

int main(void)
{
	//Initialize TCS Library
	InitTCS3200();
	
	initialisationUART();
	
	while(1)
	{		
		TCSLEDOn();
		uint32_t v1=MeasureC();
		
		_delay_ms(100);
		
		TCSLEDOff();
		uint32_t v2=MeasureC();
		
		uint32_t d=v1-v2;
		
		if(d>8000)
		{
			//Show		
			uint32_t r,g,b;
		
			TCSLEDOn();
			
			r=MeasureR();
			g=MeasureG();
			b=MeasureB();
			
			TCSLEDOff();
		
			if(r<b)
			{
				if(r<g)
					transmissionUART('r');
				else
					transmissionUART('v');
			}
			else
			{
				if(b<g)
					transmissionUART('b');
				else
					transmissionUART('v');
			}
			
			//End Show			
			_delay_ms(2000);
		}
		
		_delay_ms(50);			
	}
	
}

uint32_t MeasureR()
{
	TCSSelectRed();
	uint32_t r;
	
	_delay_ms(10);
	r=TCSMeasure();	
	
	_delay_ms(10);
	r+=TCSMeasure();	
	
	_delay_ms(10);
	r+=TCSMeasure();
	
	return r/3.3;
	
}

uint32_t MeasureG()
{
	TCSSelectGreen();
	uint32_t r;
	
	_delay_ms(10);
	r=TCSMeasure();	
	
	_delay_ms(10);
	r+=TCSMeasure();	
	
	_delay_ms(10);
	r+=TCSMeasure();
	
	return r/3;
	
}

uint32_t MeasureB()
{
	TCSSelectBlue();
	uint32_t r;
	
	_delay_ms(10);
	r=TCSMeasure();	
	
	_delay_ms(10);
	r+=TCSMeasure();	
	
	_delay_ms(10);
	r+=TCSMeasure();
	
	return r/4.2;
	
}

uint32_t MeasureC()
{
	TCSSelectClear();
	uint32_t r;
	
	_delay_ms(10);
	r=TCSMeasure();	
	
	_delay_ms(10);
	r+=TCSMeasure();	
	
	_delay_ms(10);
	r+=TCSMeasure();
	
	return r/3;	
}
