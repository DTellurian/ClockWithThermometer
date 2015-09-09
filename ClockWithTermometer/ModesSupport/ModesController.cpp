/*
 * ModesController.cpp
 *
 * Created: 23.05.2012 21:32:30
 *  Author: Dmitriy
 */ 
//---------------------------------------------------------------------------

#include "ModesController.h"
//---------------------------------------------------------------------------

ModesController::ModesController()
	:currentModePtr(0)
{			
}
//---------------------------------------------------------------------------

void ModesController::SetCurrentMode(Mode* modePtr)
{
	if(currentModePtr != 0)
	{
		currentModePtr->ExitMode();
		currentModePtr->isActive = 0;
	}		
		
	modePtr->EnterMode();
	currentModePtr = modePtr;
	currentModePtr->isActive = 1;
}
//---------------------------------------------------------------------------