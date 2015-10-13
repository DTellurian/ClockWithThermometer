/* 
* MonitorMode.cpp
*
* Created: 12.10.2015 15:17:01
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include "MonitorMode.h"
#include "..\Device.h"
#include "..\SevenDigitLed\BitLedStateLetterHelper.h"
//---------------------------------------------------------------------------

// default constructor
MonitorMode::MonitorMode()
{
} //MonitorMode
//---------------------------------------------------------------------------

// default destructor
MonitorMode::~MonitorMode()
{
} //~MonitorMode
//---------------------------------------------------------------------------

void MonitorMode::ProceedModeOnTick(void)
{
	
}
//---------------------------------------------------------------------------

void MonitorMode::EnterMode(void)
{
	BitLedState::ClearDigit(Device::bitStateLedControllerPtr->digitStates[3]);
	BitLedState::ClearDigit(Device::bitStateLedControllerPtr->digitStates[2]);
	BitLedStateLetterHelper::SetO(Device::bitStateLedControllerPtr->digitStates[1]);
	BitLedStateLetterHelper::SetR(Device::bitStateLedControllerPtr->digitStates[0]);
}
//---------------------------------------------------------------------------

void MonitorMode::ExitMode(void)
{
	
}
//---------------------------------------------------------------------------

void MonitorMode::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled)
{
	
}
//---------------------------------------------------------------------------

void MonitorMode::ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled)
{
	if(isActive == 1 && handled == 0)
	{
		handled = 1;
		
		if(buttonPtr == Device::topButtonPtr)
			Device::modesControllerPtr->SetCurrentMode(Device::idleModePtr);
	}
}
//---------------------------------------------------------------------------
