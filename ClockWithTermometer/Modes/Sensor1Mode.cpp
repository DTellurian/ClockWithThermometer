/* 
* Sensor1Mode.cpp
*
* Created: 09.10.2015 8:43:09
* Author: Mihalych
*/


//---------------------------------------------------------------------------

#include "Sensor1Mode.h"
#include "..\BaseTypes\CFTime.h"
#include "..\Device.h"
//---------------------------------------------------------------------------
// default constructor
Sensor1Mode::Sensor1Mode(void)
	:displayValue(7), temperatureToShow(0)
{
} //Sensor1Mode

//---------------------------------------------------------------------------
// default destructor
Sensor1Mode::~Sensor1Mode()	
{
} //~Sensor1Mode

//---------------------------------------------------------------------------
void Sensor1Mode::ProceedModeOnTick(void)
{
	ReadAndDisplay();
	//BitLedState::SetDigitState(displayValue, Device::bitStateLedControllerPtr->digitStates[1], Device::bitStateLedControllerPtr->digitStates[0]);
	//BitLedState::SetDigitState(0, Device::bitStateLedControllerPtr->digitStates[3], Device::bitStateLedControllerPtr->digitStates[2]);
}
//---------------------------------------------------------------------------

void Sensor1Mode::EnterMode(void)
{
	ReadAndDisplay();
}
//---------------------------------------------------------------------------

void Sensor1Mode::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled)
{
}
//---------------------------------------------------------------------------

void Sensor1Mode::ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled)
{
	if(isActive == 1 && handled == 0)
	{
		handled = 1;
		
		Device::modesControllerPtr->SetCurrentMode(Device::mainModePtr);
	}
}
//---------------------------------------------------------------------------

#ifndef SIMULATION
void Sensor1Mode::ReadAndDisplay(void)
{
	uint8_t checkResult = Device::oneWireContextPtr->ReadTemperature(&temperatureToShow);
	
	if(checkResult)
		Device::ShowTemperature(temperatureToShow);
	else
	{
		BitLedState::SetDigitState(0, Device::bitStateLedControllerPtr->digitStates[1], Device::bitStateLedControllerPtr->digitStates[0]);
		BitLedState::SetDigitState(0, Device::bitStateLedControllerPtr->digitStates[3], Device::bitStateLedControllerPtr->digitStates[2]);
	}	
}
//---------------------------------------------------------------------------
#else
void Sensor1Mode::ReadAndDisplay(void)
{
	BitLedState::SetDigitState(displayValue, Device::bitStateLedControllerPtr->digitStates[1], Device::bitStateLedControllerPtr->digitStates[0]);
	BitLedState::SetDigitState(0, Device::bitStateLedControllerPtr->digitStates[3], Device::bitStateLedControllerPtr->digitStates[2]);
}
//---------------------------------------------------------------------------
#endif