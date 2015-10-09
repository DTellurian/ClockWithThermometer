/*
 * TimerMode.cpp
 *
 * Created: 19.02.2015 17:47:48
 *  Author: Mihalych
 */ 
//---------------------------------------------------------------------------

#include "TimerMode.h"
#include "..\BaseTypes\CFTime.h"
#include "..\Device.h"
//---------------------------------------------------------------------------

TimerMode::TimerMode(void)
	:isRun(0), startSecondsCount(0), lastMeasuredSecondsCount(0)
{
	
}
//---------------------------------------------------------------------------
void TimerMode::ProceedModeOnTick(void)
{
	if(isRun)
		lastMeasuredSecondsCount = Device::GetCurrentTime().GetTotalSeconds();
	
	CFTime timeSpan = CFTime(lastMeasuredSecondsCount - startSecondsCount);
	
	BitLedState::SetDigitState(timeSpan.GetSeconds(), Device::bitStateLedControllerPtr->digitStates[1], Device::bitStateLedControllerPtr->digitStates[0]);				
	BitLedState::SetDigitState(timeSpan.GetMinutes(), Device::bitStateLedControllerPtr->digitStates[3], Device::bitStateLedControllerPtr->digitStates[2]);
}
//---------------------------------------------------------------------------

void TimerMode::EnterMode(void)
{
	Device::ledHelperPtr->pointBlinkEnabled = 0;
}
//---------------------------------------------------------------------------

void TimerMode::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled)
{
	//if(isActive == 1 && handled == 0)
	//{
		//handled = 1;
		//startSecondsCount = Device::GetCurrentTime().GetTotalSeconds();
	//}
}
//---------------------------------------------------------------------------

void TimerMode::ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled)
{
	if(isActive == 1 && handled == 0)
	{
		handled = 1;
		
		if(buttonPtr == Device::topButtonPtr)
			Device::modesControllerPtr->SetCurrentMode(Device::sensor1ModePtr);
			//Device::modesControllerPtr->SetCurrentMode(Device::mainModePtr);
		else if(buttonPtr == Device::bottomButtonPtr)
		{
			if(!isRun)
			{
				isRun = 1;
				
				//if(startSecondsCount == 0)
				startSecondsCount = Device::GetCurrentTime().GetTotalSeconds();
			}
			else
				isRun = 0;
		}
	}	
}
//---------------------------------------------------------------------------