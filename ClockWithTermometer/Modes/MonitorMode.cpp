/* 
* MonitorMode.cpp
*
* Created: 12.10.2015 15:17:01
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include "MonitorMode.h"
#include "..\Device.h"
#include "..\SevenDigitLed\BitLedStateLetterHelper.h"
#include "..\BaseTypes\DateTime.h"
//---------------------------------------------------------------------------

// default constructor
MonitorMode::MonitorMode()
	:sensorIndex(0), monitorState(ModeNameDisplay), nextStateShowTime(0), nextMillisecondsToSensorMeasure(0)
{
} //MonitorMode
//---------------------------------------------------------------------------

// default destructor
MonitorMode::~MonitorMode()
{
} //~MonitorMode
//---------------------------------------------------------------------------

void MonitorMode::ProceedModeOnTick(void)
{
	if(nextStateShowTime < DateTime::milliseconds)
	{
		Device::ClearScreen();
		_delay_ms(500);
		
		nextStateShowTime = DateTime::milliseconds + MONITOR_MODE_STATE_PERIOD_MS;				
		
		if(monitorState == ModeNameDisplay)
		{
			monitorState = TimeDisplay;
			Device::ledHelperPtr->pointBlinkEnabled = 1;
		}
		else if(monitorState == TimeDisplay)
		{
			Device::ledHelperPtr->pointBlinkEnabled = 0;
			
			monitorState = SensorsDisplay;
			
			nextMillisecondsToSensorMeasure = 0;
			
			if(Device::oneWireContextPtr->IsSearchState())
				Device::ShowSearch();
			else
			{
				Device::oneWireContextPtr->currentSensorIndex = 0;
				
				BitLedStateLetterHelper::SetS(Device::bitStateLedControllerPtr->digitStates[2]);
				BitLedState::SetDigitState(Device::oneWireContextPtr->currentSensorIndex + 1, Device::bitStateLedControllerPtr->digitStates[0]);
				_delay_ms(200);
			}
		}
		else//monitorState == SensorsDisplay
		{
			int nextSensorIndex = Device::oneWireContextPtr->SetNextSensor();
			
			if(nextSensorIndex == 0)
			{
				monitorState = TimeDisplay;
				Device::ledHelperPtr->pointBlinkEnabled = 1;
			}
			else
			{
				Device::ClearScreen();				
				
				BitLedStateLetterHelper::SetS(Device::bitStateLedControllerPtr->digitStates[2]);
				BitLedState::SetDigitState(Device::oneWireContextPtr->currentSensorIndex + 1, Device::bitStateLedControllerPtr->digitStates[0]);
				_delay_ms(200);
			}
		}
	}
	
	if(monitorState == TimeDisplay)
	{
		CFTime currentTime = Device::GetCurrentTime();
		Device::ledHelperPtr->ShowTime(&currentTime, 0);
	}
	else if(monitorState == SensorsDisplay)
	{
		if(nextMillisecondsToSensorMeasure > DateTime::milliseconds)
			return;	
			
		nextMillisecondsToSensorMeasure = DateTime::milliseconds + MONITOR_MODE_SENSORS_MEASUREMENT_FREQUENCY;
		
		uint16_t temperatureToShow;
		uint8_t checkResult = Device::oneWireContextPtr->ReadTemperature(&temperatureToShow);
		
		if(checkResult)
			Device::ShowTemperature(temperatureToShow);
		else
		{
			Device::ShowError();
				
			_delay_ms(1000);
			nextStateShowTime = 0;
		}
	}
	else//monitorState = ModeNameDisplay
		;
}
//---------------------------------------------------------------------------

void MonitorMode::EnterMode(void)
{
	monitorState = ModeNameDisplay;
	
	nextStateShowTime = DateTime::milliseconds + MONITOR_MODE_STATE_PERIOD_MS;
	
	BitLedStateLetterHelper::SetD(Device::bitStateLedControllerPtr->digitStates[3]);
	BitLedStateLetterHelper::SetI(Device::bitStateLedControllerPtr->digitStates[2]);
	BitLedStateLetterHelper::SetP(Device::bitStateLedControllerPtr->digitStates[1]);
	BitLedStateLetterHelper::SetL(Device::bitStateLedControllerPtr->digitStates[0]);
}
//---------------------------------------------------------------------------

void MonitorMode::ExitMode(void)
{
	Device::ledHelperPtr->pointBlinkEnabled = 0;
}
//---------------------------------------------------------------------------

void MonitorMode::ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled)
{
	
}
//---------------------------------------------------------------------------

void MonitorMode::ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled)
{
	if(isActive == 1 && handled == 0)
	{
		handled = 1;
		
		if(buttonPtr == Device::topButtonPtr)
			Device::modesControllerPtr->SetCurrentMode(Device::idleModePtr);
	}
}
//---------------------------------------------------------------------------
