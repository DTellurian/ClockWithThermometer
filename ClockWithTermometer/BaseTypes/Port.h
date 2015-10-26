/*
 * Port.h
 *
 * Created: 13.05.2012 21:38:28
 *  Author: Dmitriy
 */ 


#ifndef PORT_H_
#define PORT_H_
//---------------------------------------------------------------------------

#include <stdint.h>
//---------------------------------------------------------------------------

class Port
{
	public:
		Port(volatile uint8_t* portInOutStatePtr, volatile uint8_t* portPinStatePtr, volatile uint8_t* portPinRegisterPtr);	
		
		volatile uint8_t* portInOutStatePtr; //DDRD
		volatile uint8_t* portPinStatePtr; //PORTD
		volatile uint8_t* portPinRegisterPtr; //PIND
	
	private:
		Port(const Port& c);
		Port& operator=(const Port& c);
};
//---------------------------------------------------------------------------
#endif /* PORT_H_ */