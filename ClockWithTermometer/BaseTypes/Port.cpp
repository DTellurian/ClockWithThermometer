/*
 * Port.cpp
 *
 * Created: 19.05.2012 13:10:07
 *  Author: Dmitriy
 */ 
//---------------------------------------------------------------------------

#include "Port.h"
//---------------------------------------------------------------------------

Port::Port(volatile uint8_t* portInOutStatePtr, volatile uint8_t* portPinStatePtr, volatile uint8_t* portPinRegisterPtr)
{
	this->portInOutStatePtr = portInOutStatePtr;
	this->portPinStatePtr = portPinStatePtr;
	this->portPinRegisterPtr = portPinRegisterPtr;
}
//---------------------------------------------------------------------------