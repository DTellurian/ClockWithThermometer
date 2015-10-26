/*
 * MainMode.cpp
 *
 * Created: 17.02.2015 13:33:42
 *  Author: Mihalych
 */ 
//---------------------------------------------------------------------------

#include "MainMode.h"
#include "..\Device.h"
#include "..\Device\Ports.h"
#include "..\BaseTypes\rtc.h"
#include "..\BaseTypes\DateTime.h"

//#include <avr\sleep.h>
//#include <util\delay.h>
//---------------------------------------------------------------------------

MainMode::MainMode(void)
{
	
}
//---------------------------------------------------------------------------

void MainMode::ProceedModeOnTick(void)
{	
	CFTime currentTime = Device::GetCurrentTime();
	Device::ledHelperPtr->ShowTime(&currentTime, 0);
}
//---------------------------------------------------------------------------

void MainMode::EnterMode(void)
{
	Device::ledHelperPtr->pointBlinkEnabled = 1;
}
//---------------------------------------------------------------------------

void MainMode::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled)
{
	if(isActive == 1 && handled == 0)
	{
		handled = 1;
		
		if(buttonPtr == Device::topButtonPtr)
			Device::modesControllerPtr->SetCurrentMode(Device::timeSetModePtr);
	}
}
//---------------------------------------------------------------------------

void MainMode::ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled)
{
	if(isActive == 1 && handled == 0)
	{
		handled = 1;
				
		if(buttonPtr == Device::topButtonPtr)
			Device::modesControllerPtr->SetCurrentMode(Device::timerModePtr);
	}
}
//---------------------------------------------------------------------------