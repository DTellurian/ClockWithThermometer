/*
 * LedHelper.cpp
 *
 * Created: 18.02.2015 13:10:51
 *  Author: Mihalych
 */ 
//---------------------------------------------------------------------------

#include "LedHelper.h"
#include "SevenDigitLed/BitLedState.h"
#include "Device.h"
#include "BaseTypes/DateTime.h"
//---------------------------------------------------------------------------

LedHelper::LedHelper(void)
	:leftSideBlinkEnabled(0), leftSideVisibility(1), rightSideBlinkEnabled(0), rightSideVisibility(1), pointBlinkEnabled(0), millisecondToBlink(0)
{
	
}
//---------------------------------------------------------------------------

void LedHelper::ShowTime(CFTime* timePtr, uint8_t showSeconds)
{	
	if(leftSideBlinkEnabled && !leftSideVisibility)
	{
		BitLedState::ClearDigit(Device::bitStateLedControllerPtr->digitStates[3]);
		BitLedState::ClearDigit(Device::bitStateLedControllerPtr->digitStates[2]);
	}
			
	if(rightSideBlinkEnabled && !rightSideVisibility)
	{
		BitLedState::ClearDigit(Device::bitStateLedControllerPtr->digitStates[1]);
		BitLedState::ClearDigit(Device::bitStateLedControllerPtr->digitStates[0]);
	}

	if(!rightSideBlinkEnabled || rightSideVisibility)
		BitLedState::SetDigitState(timePtr->GetMinutes(), Device::bitStateLedControllerPtr->digitStates[1], Device::bitStateLedControllerPtr->digitStates[0]);
		
	if(!leftSideBlinkEnabled || leftSideVisibility)
		BitLedState::SetDigitState(timePtr->GetHours(), Device::bitStateLedControllerPtr->digitStates[3], Device::bitStateLedControllerPtr->digitStates[2]);
}
//---------------------------------------------------------------------------

void LedHelper::ProceedTick(void)
{
	if(millisecondToBlink < DateTime::milliseconds)
	{
		millisecondToBlink = DateTime::milliseconds + 500;
		
		if(pointBlinkEnabled)
			BitLedState::InverseDot(Device::bitStateLedControllerPtr->digitStates[2]);
			
		if(leftSideBlinkEnabled)
			leftSideVisibility = !leftSideVisibility;
			
		if(rightSideBlinkEnabled)
			rightSideVisibility = !rightSideVisibility;			
	}
}
//---------------------------------------------------------------------------

void LedHelper::ShowAllBlinked(void)
{
	millisecondToBlink = DateTime::milliseconds + 500;
	
	rightSideVisibility = 1;
	leftSideVisibility = 1;
}
//---------------------------------------------------------------------------