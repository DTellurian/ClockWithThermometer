/*
 * SimpleButton.cpp
 *
 * Created: 19.01.2014 18:04:13
 *  Author: Mihalych
 */ 
//---------------------------------------------------------------------------

#include "SimpleButton.h"
#include "ButtonsController.h"
//---------------------------------------------------------------------------

SimpleButton::SimpleButton(ButtonsController* buttonsControllerPtr, Pin* pinPtr, uint16_t delayMs)
	:Button(buttonsControllerPtr, delayMs)
{
	this->pinPtr = pinPtr;
	
	pinPtr->SetAsInputWithPullUp();
}
//---------------------------------------------------------------------------

uint8_t SimpleButton::IsPressed(void)
{
	return !pinPtr->IsPinSet();
}
//---------------------------------------------------------------------------