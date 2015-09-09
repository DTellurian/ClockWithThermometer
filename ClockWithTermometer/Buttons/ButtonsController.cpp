/*
 * ButtonsController.cpp
 *
 * Created: 19.05.2012 13:07:04
 *  Author: Dmitriy
 */ 
//---------------------------------------------------------------------------

#include "ButtonsController.h"
//#include <stdlib.h>
//---------------------------------------------------------------------------

ButtonsController::ButtonsController(void)	
	:attachedButtonsCount(0), attachedConsumersCount(0)
{
	//buttons = (Button**)malloc(sizeof(Button*)*ButtonsControllerButtonsCount);
	//consumers = (ButtonsControllerConsumer**)malloc(sizeof(ButtonsControllerConsumer*)*ButtonsControllerConsumersCount);
}
//---------------------------------------------------------------------------

void ButtonsController::ButtonsControllerOnTick(void)
{
	for(uint8_t i = 0; i < attachedButtonsCount; i++)
		buttons[i]->OnTick();
}
//---------------------------------------------------------------------------

void ButtonsController::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber)
{
	uint8_t handled = 0;
	
	for(uint8_t i = 0; i < attachedConsumersCount; i++)
		consumers[i]->ProceedButtonFire(buttonPtr, isSealedFire, sealedFireNumber, handled);
}
//---------------------------------------------------------------------------

void ButtonsController::ProceedButtonUpFire(Button* buttonPtr)
{
	uint8_t handled = 0;
	
	for(uint8_t i = 0; i < attachedConsumersCount; i++)
		consumers[i]->ProceedButtonUpFire(buttonPtr, handled);	
}
//---------------------------------------------------------------------------

void ButtonsController::AttachButton(Button* buttonPtr)
{
	buttons[attachedButtonsCount++] = buttonPtr;
}
//---------------------------------------------------------------------------

void ButtonsController::AttachConsumer(ButtonsControllerConsumer* consumerPtr)
{
	consumers[attachedConsumersCount++] = consumerPtr;
}
//---------------------------------------------------------------------------