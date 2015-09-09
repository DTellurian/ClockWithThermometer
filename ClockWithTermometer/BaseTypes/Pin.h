/*
 * Pin.h
 *
 * Created: 13.05.2012 21:36:14
 *  Author: Dmitriy
 */ 


#ifndef PIN_H_
#define PIN_H_
//---------------------------------------------------------------------------

#include <stdint.h>
#include "Port.h"

//---------------------------------------------------------------------------

class Pin
{
	public:
		Pin(Port* portPtr, int portPinNumber, int pinNumber);
	
		void SetAsOutput(void);
		void SetAsInput(void);
		void SetAsInputWithPullUp(void);
		
		uint8_t IsPinSet(void);
		
		void SetHightLevel(void);
		void SetLowLevel(void);
		void SetValue(uint8_t targetValue);
		
		void Reverse(void);
	private:
		Port* portPtr;
		int portPinNumber; //DDD3
		int pinNumber; //PIND3
};

//---------------------------------------------------------------------------
#endif /* PIN_H_ */