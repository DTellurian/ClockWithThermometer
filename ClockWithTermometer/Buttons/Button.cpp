/*
 * Button.cpp
 *
 * Created: 19.05.2012 12:56:38
 *  Author: Dmitriy
 */ 

//---------------------------------------------------------------------------

#include "Button.h"
#include "ButtonsController.h"
#include "../BaseTypes/DateTime.h"
//---------------------------------------------------------------------------

Button::Button(void)
{
}
//---------------------------------------------------------------------------

Button::Button(ButtonsController* buttonsControllerPtr, uint16_t delayMs)
{
	Initialize(buttonsControllerPtr, delayMs);
}
//---------------------------------------------------------------------------

void Button::ProceedFire(uint8_t isSealingEvent)
{
	buttonsControllerPtr->ProceedButtonFire(this, isSealingEvent, sealingFireCounter);	
}
//---------------------------------------------------------------------------

void Button::ProceedButtonUpFire(void)
{
	buttonsControllerPtr->ProceedButtonUpFire(this);	
}
//---------------------------------------------------------------------------

void Button::Initialize(ButtonsController* buttonsControllerPtr, uint16_t delayMs)
{
	this->buttonsControllerPtr = buttonsControllerPtr;
					
	enabled = 1;
	enableSealing = 0;
	firstSealingDelayMs = 100;
	betweenSealingDelayMs = 100;
		
	wasPressed = 0;
	pressedMilliseconds = 0; 
		
	fireFlag = 0;
		
	sealingFireFlag = 0;
	sealingFireCounter = 0;
	
	SetDelay(delayMs);	
	
	enabledButtonUpFire = 0;
	buttonUpDelayMs = 100;
}
//---------------------------------------------------------------------------

void Button::SetDelay(uint16_t delayMs)
{
	this->delayMs = delayMs;
}
//---------------------------------------------------------------------------

void Button::SetSealingDelay(uint16_t firstSealingDelayMs, uint16_t betweenSealingDelayMs)
{
	this->firstSealingDelayMs = firstSealingDelayMs;
	this->betweenSealingDelayMs = betweenSealingDelayMs;	
}
//---------------------------------------------------------------------------

void Button::OnTick(void)
{
	if(enabled == 0)
		return;

	if(IsPressed())	
	{		
		if(wasPressed)
		{
			if(fireFlag == 0)
			{
				if(DateTime::milliseconds - pressedMilliseconds > delayMs)
				{
					fireFlag = 1;
					pressedMilliseconds = DateTime::milliseconds;
					ProceedFire(0);
				}
			}
			else			
			{
				if(enableSealing == 1)
				{					
					if(sealingFireFlag == 0)
					{
						if(DateTime::milliseconds - pressedMilliseconds > firstSealingDelayMs)						
						{
							pressedMilliseconds = DateTime::milliseconds;
							sealingFireFlag = 1;
							sealingFireCounter++;
							ProceedFire(1);
						}
					}
					else
					{
						if(DateTime::milliseconds - pressedMilliseconds > betweenSealingDelayMs)
						{							
							pressedMilliseconds = DateTime::milliseconds;
							sealingFireCounter++;
							ProceedFire(1);
						}
					}
				}				
			}
		}
		else
		{
			wasPressed = 1;
			
			pressedMilliseconds = DateTime::milliseconds;
		
			fireFlag = 0;
			
			sealingFireFlag = 0;
			sealingFireCounter = 0;
		}
	}
	else	
	{
		if(wasPressed == 1)
		{
			wasPressed = 0;	
			
			if(enabledButtonUpFire == 1 && fireFlag == 0)
			{
				if(DateTime::milliseconds - pressedMilliseconds > buttonUpDelayMs)
					ProceedButtonUpFire();
			}
		}
	}			
}
//---------------------------------------------------------------------------