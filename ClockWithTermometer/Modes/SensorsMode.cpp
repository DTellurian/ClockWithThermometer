/* 
* SensorsMode.cpp
*
* Created: 09.10.2015 8:43:09
* Author: Mihalych
*/


//---------------------------------------------------------------------------

#include "SensorsMode.h"
#include "..\BaseTypes\CFTime.h"
#include "..\Device.h"
#include "..\SevenDigitLed\BitLedStateLetterHelper.h"
#include "..\BaseTypes\DateTime.h"
//---------------------------------------------------------------------------
// default constructor
SensorsMode::SensorsMode(void)
	:displayValue(7), nextMillisecondsToMeasure(0)
{
} //SensorsMode

//---------------------------------------------------------------------------
// default destructor
SensorsMode::~SensorsMode()	
{
} //~SensorsMode

//---------------------------------------------------------------------------
void SensorsMode::ProceedModeOnTick(void)
{	
	ReadAndDisplay();
	 
	//BitLedState::SetDigitState(displayValue, Device::bitStateLedControllerPtr->digitStates[1], Device::bitStateLedControllerPtr->digitStates[0]);
	//BitLedState::SetDigitState(0, Device::bitStateLedControllerPtr->digitStates[3], Device::bitStateLedControllerPtr->digitStates[2]);
}
//---------------------------------------------------------------------------

void SensorsMode::EnterMode(void)
{
	BitLedState::ClearDigit(Device::bitStateLedControllerPtr->digitStates[3]);
	BitLedState::ClearDigit(Device::bitStateLedControllerPtr->digitStates[2]);
	BitLedState::ClearDigit(Device::bitStateLedControllerPtr->digitStates[1]);
	BitLedState::ClearDigit(Device::bitStateLedControllerPtr->digitStates[0]);
	BitLedState::SetDot(0, Device::bitStateLedControllerPtr->digitStates[1]);
	
	if(Device::oneWireContextPtr->IsSearchState())
	{
		Device::ShowSearch();
	}
	else
	{
		BitLedStateLetterHelper::SetS(Device::bitStateLedControllerPtr->digitStates[2]);
		BitLedState::SetDigitState(Device::oneWireContextPtr->currentSensorIndex + 1, Device::bitStateLedControllerPtr->digitStates[0]);
		_delay_ms(200);
	}
		
	ReadAndDisplay();
}
//---------------------------------------------------------------------------

void SensorsMode::ExitMode(void)
{
	BitLedState::SetDot(0, Device::bitStateLedControllerPtr->digitStates[1]);
}
//---------------------------------------------------------------------------

void SensorsMode::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled)
{
}
//---------------------------------------------------------------------------

void SensorsMode::ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled)
{
	if(isActive == 1 && handled == 0)
	{
		handled = 1;
		
		if(buttonPtr == Device::topButtonPtr)
			Device::modesControllerPtr->SetCurrentMode(Device::monitorModePtr);
		else if(buttonPtr == Device::bottomButtonPtr)
		{
			if(Device::oneWireContextPtr->IsSearchState())
				return;
			
			Device::oneWireContextPtr->SetNextSensor();
			nextMillisecondsToMeasure = 0;
			EnterMode();
		}
	}
}
//---------------------------------------------------------------------------


void SensorsMode::ReadAndDisplay(void)
{
	if(nextMillisecondsToMeasure > DateTime::milliseconds)
		return;
	
	nextMillisecondsToMeasure  = DateTime::milliseconds + SENSORS_MODE_MEASUREMENT_FREQUENCY;
	
	uint16_t temperatureToShow;
	uint8_t checkResult = Device::oneWireContextPtr->ReadTemperature(&temperatureToShow);
	
	if(checkResult)
		Device::ShowTemperature(temperatureToShow);
	else
	{
		Device::ShowError();
		
		_delay_ms(1000);
		Device::modesControllerPtr->SetCurrentMode(Device::monitorModePtr);
	}	
}
//---------------------------------------------------------------------------
