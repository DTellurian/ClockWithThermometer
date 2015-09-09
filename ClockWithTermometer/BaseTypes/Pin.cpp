/*
 * Pin.cpp
 *
 * Created: 23.05.2012 21:18:25
 *  Author: Dmitriy
 */ 
//---------------------------------------------------------------------------

#include "Pin.h"
#include <avr/io.h>
#include "Port.h"
//---------------------------------------------------------------------------

Pin::Pin(Port* portPtr, int portPinNumber, int pinNumber)
{
	this->portPtr = portPtr;
	this->portPinNumber = portPinNumber;
	this->pinNumber = pinNumber;
}
//---------------------------------------------------------------------------

void Pin::SetAsOutput(void)
{
	*(portPtr->portInOutStatePtr) |= _BV(portPinNumber); //DDRD |= _BV(DDD3);
}
//---------------------------------------------------------------------------

void Pin::SetAsInput(void)
{
	*(portPtr->portInOutStatePtr) &= ~_BV(portPinNumber); //DDRD &= ~_BV(DDD3);	
}
//---------------------------------------------------------------------------

void Pin::SetAsInputWithPullUp(void)
{
	SetAsInput();
	SetHightLevel();
}
//---------------------------------------------------------------------------

uint8_t Pin::IsPinSet(void)
{
	return bit_is_set(*(portPtr->portPinRegisterPtr), pinNumber);
}
//---------------------------------------------------------------------------

void Pin::SetHightLevel(void)
{
	*(portPtr->portPinStatePtr) |= _BV(pinNumber);
}	
//---------------------------------------------------------------------------

void Pin::SetLowLevel(void)
{
	*(portPtr->portPinStatePtr) &= ~_BV(pinNumber);
}
//---------------------------------------------------------------------------

void Pin::SetValue(uint8_t targetValue)
{
	if(targetValue == 0)
		*(portPtr->portPinStatePtr) &= ~_BV(pinNumber);
	else
		*(portPtr->portPinStatePtr) |= _BV(pinNumber);
}
//---------------------------------------------------------------------------

void Pin::Reverse(void)
{		
	if(IsPinSet())
		SetLowLevel();
	else
		SetHightLevel();
}
//---------------------------------------------------------------------------