/*
 * TimeSetMode.cpp
 *
 * Created: 18.02.2015 12:46:06
 *  Author: Mihalych
 */ 
//---------------------------------------------------------------------------

#include "TimeSetMode.h"
#include "..\BaseTypes\CFTime.h"
#include "..\Device.h"
//---------------------------------------------------------------------------

TimeSetMode::TimeSetMode(void)
	:isMinutesEditing(1)
{
}
		
void TimeSetMode::ProceedModeOnTick(void)
{
	CFTime currentTime = Device::GetCurrentTime();
	Device::ledHelperPtr->ShowTime(&currentTime, 0);
}
//---------------------------------------------------------------------------

void TimeSetMode::EnterMode(void)
{
	isMinutesEditing = 1;
	
	Device::ledHelperPtr->pointBlinkEnabled = 0;
	Device::ledHelperPtr->rightSideBlinkEnabled = 1;
	Device::ledHelperPtr->millisecondToBlink = 0;
	
	BitLedState::SetDot(1, Device::bitStateLedControllerPtr->digitStates[2]);
}
//---------------------------------------------------------------------------

void TimeSetMode::ExitMode(void)
{
	Device::ledHelperPtr->leftSideBlinkEnabled = 0;
	Device::ledHelperPtr->rightSideBlinkEnabled = 0;
}
//---------------------------------------------------------------------------

void TimeSetMode::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled)
{
	if(isActive == 1 && handled == 0)
	{
		handled = 1;
		
		if(buttonPtr == Device::topButtonPtr)
			Device::modesControllerPtr->SetCurrentMode(Device::mainModePtr);			
		else if(buttonPtr == Device::bottomButtonPtr)
			SetTime();
	}
}
//---------------------------------------------------------------------------

void TimeSetMode::ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled)
{
	if(isActive == 1 && handled == 0)
	{			
		handled = 1;
		
		if(buttonPtr == Device::topButtonPtr)
		{
			isMinutesEditing = !isMinutesEditing;
				
			Device::ledHelperPtr->rightSideBlinkEnabled = isMinutesEditing;
			Device::ledHelperPtr->leftSideBlinkEnabled = !isMinutesEditing;				
			
			Device::ledHelperPtr->ShowAllBlinked();
		}
		else if(buttonPtr == Device::bottomButtonPtr)
			SetTime();
	}	
}
//---------------------------------------------------------------------------

void TimeSetMode::SetTime(void)
{
	CFTime currentTime = Device::GetCurrentTime();
	
	if(isMinutesEditing)
		currentTime.AddMinute(1);
	else
		currentTime.AddHour();
		
	Device::SetCurrentTiem(&currentTime);	
	Device::ledHelperPtr->ShowAllBlinked();
}
//---------------------------------------------------------------------------
