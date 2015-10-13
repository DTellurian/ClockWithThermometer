/*
 * ClockWithTermometer.cpp
 *
 * Created: 09.09.2015 10:44:39
 *  Author: Mihalych
 */ 

//---------------------------------------------------------------------------

#include "DeviceConfiguration.h"

#include <avr\io.h>
#include <avr\sleep.h>
#include <util\delay.h>
#include "Device.h"
#include "Device\Ports.h"
#include "BaseTypes\rtc.h"
#include "ModesSupport/ModesController.h"
#include "Buttons/SimpleButton.h"
#include "SevenDigitLed/BitLedStateLetterHelper.h"
//---------------------------------------------------------------------------

#include "BaseTypes/DateTime.h"

int main(void)
{	
	LedHelper ledHelper = LedHelper();
	Device::ledHelperPtr = &ledHelper;
	
	ModesController modesController = ModesController();
	Device::modesControllerPtr = &modesController;
	
	ButtonsController buttonsController = ButtonsController();
	Device::buttonsControllerPtr = &buttonsController;
	
	SimpleButton topButton = SimpleButton(Device::buttonsControllerPtr, &pinD2, 500);
	Device::topButtonPtr = &topButton;
	Device::buttonsControllerPtr->AttachButton(&topButton);
	
	SimpleButton bottomButton = SimpleButton(Device::buttonsControllerPtr, &pinD3, 500);
	Device::bottomButtonPtr = &bottomButton;
	Device::buttonsControllerPtr->AttachButton(&bottomButton);
	
	MainMode mainMode = MainMode();
	Device::mainModePtr = &mainMode;
	Device::buttonsControllerPtr->AttachConsumer(Device::mainModePtr);
	
	TimeSetMode timeSetMode = TimeSetMode();
	Device::timeSetModePtr = &timeSetMode;
	Device::buttonsControllerPtr->AttachConsumer(Device::timeSetModePtr);

	TimerMode timerMode = TimerMode();
	Device::timerModePtr = &timerMode;
	Device::buttonsControllerPtr->AttachConsumer(Device::timerModePtr);
	
	SensorsMode sensorsMode = SensorsMode();
	Device::sensor1ModePtr = &sensorsMode;
	Device::buttonsControllerPtr->AttachConsumer(Device::sensor1ModePtr);
	
	MonitorMode monitorMode = MonitorMode();
	Device::monitorModePtr = &monitorMode;
	Device::buttonsControllerPtr->AttachConsumer(Device::monitorModePtr);
	
	IdleMode idleMode = IdleMode();
	Device::idleModePtr = &idleMode;
	Device::buttonsControllerPtr->AttachConsumer(Device::idleModePtr);
	
	OneWireContext oneWireContext = OneWireContext(2);
	Device::oneWireContextPtr = &oneWireContext;
	
	Device::Initialize();
	
	dateTime receivedDayTime = get_date_time();

	if(receivedDayTime.hour == 0 && receivedDayTime.minute == 0 && receivedDayTime.second == 0 )
	{
		dateTime dt;
		
		dt.hour = 8;
		dt.minute = 34;
		dt.second = 00;
		
		dt.date = 30;
		dt.month = 10;
		dt.year = 14;
		dt.day = 3;
		
		rtc_init();
		set_date_time(dt);
	}
	
	Device::modesControllerPtr->SetCurrentMode(Device::mainModePtr);	
	
	BitLedStateLetterHelper::SetH(Device::bitStateLedControllerPtr->digitStates[3]);
	BitLedStateLetterHelper::SetE(Device::bitStateLedControllerPtr->digitStates[2]);
	BitLedStateLetterHelper::SetL(Device::bitStateLedControllerPtr->digitStates[1]);
	BitLedStateLetterHelper::SetO(Device::bitStateLedControllerPtr->digitStates[0]);
	
	_delay_ms(5000);
	
	while(1)
	{
		Device::buttonsControllerPtr->ButtonsControllerOnTick();
		Device::modesControllerPtr->currentModePtr->ProceedModeOnTick();
		Device::ledHelperPtr->ProceedTick();
		
		continue;
	}
}
//---------------------------------------------------------------------------