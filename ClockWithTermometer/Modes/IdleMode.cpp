/* 
* IdleMode.cpp
*
* Created: 12.10.2015 15:17:13
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include <avr\sleep.h>
#include "IdleMode.h"
#include "..\Device.h"
#include "..\SevenDigitLed\BitLedStateLetterHelper.h"
#include "..\BaseTypes\DateTime.h"
//---------------------------------------------------------------------------

// default constructor
IdleMode::IdleMode()
 :state(DeviceActive), wakeupTimeLimit(0)
{
} //IdleMode
//---------------------------------------------------------------------------

// default destructor
IdleMode::~IdleMode()
{
} //~IdleMode

//---------------------------------------------------------------------------

void IdleMode::ProceedModeOnTick(void)
{
	if(state == WaitForWakeUp)
	{
		if(DateTime::milliseconds > wakeupTimeLimit)
		GoToSleep();
	}
}
//---------------------------------------------------------------------------

void IdleMode::EnterMode(void)
{
	BitLedStateLetterHelper::SetI(Device::bitStateLedControllerPtr->digitStates[3]);
	BitLedStateLetterHelper::SetD(Device::bitStateLedControllerPtr->digitStates[2]);
	BitLedStateLetterHelper::SetL(Device::bitStateLedControllerPtr->digitStates[1]);
	BitLedStateLetterHelper::SetE(Device::bitStateLedControllerPtr->digitStates[0]);
	
	state = DeviceActive;
}
//---------------------------------------------------------------------------

void IdleMode::ExitMode(void)
{
	
}
//---------------------------------------------------------------------------

void IdleMode::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled)
{
	if(state == WaitForWakeUp)
	{
		Device::SetCommonButtonsSettings();
		Device::LedOn();
		Device::modesControllerPtr->SetCurrentMode(Device::mainModePtr);
	}
}
//---------------------------------------------------------------------------

void IdleMode::ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled)
{
	if(isActive == 1 && handled == 0)
	{
		handled = 1;
		
		if(buttonPtr == Device::topButtonPtr)
			Device::modesControllerPtr->SetCurrentMode(Device::mainModePtr);
		else if(buttonPtr == Device::bottomButtonPtr)
		{
			GoToSleep();
		}
	}	
}
//---------------------------------------------------------------------------

void IdleMode::GoToSleep(void)
{
	Device::SetWakeUpButtonsSettings();
	Device::LedOff();
			
	//ѕереключаю прерывание в режим низкого уровн€, иначе не выйдет из сп€чки
	EIMSK = _BV(INT0) | _BV(INT1);
	EICRA = 0;

	state = WaitForWakeUp;
			
	sleep_enable();
	set_sleep_mode (SLEEP_MODE_PWR_DOWN);
	sleep_mode();
	sleep_disable();
			
	//ќтключаю внешние прерывани€
	EIMSK &= ~_BV(INT0);
	EIMSK &= ~_BV(INT1);
			
	wakeupTimeLimit = DateTime::milliseconds + 5000;	
}
//---------------------------------------------------------------------------

ISR(INT0_vect)
{
	
}
//---------------------------------------------------------------------------

ISR(INT1_vect)
{
	
}
//---------------------------------------------------------------------------