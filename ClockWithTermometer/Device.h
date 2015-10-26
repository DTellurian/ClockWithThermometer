/*
 * Device.h
 *
 * Created: 27.10.2014 23:09:20
 *  Author: Mihalych
 */ 


#ifndef DEVICE_H_
#define DEVICE_H_

//---------------------------------------------------------------------------

#include "DeviceConfiguration.h"
#include "SevenDigitLed/BitStateLedController.h"
#include "BaseTypes/rtc.h"
#include "ModesSupport/ModesController.h"
#include "Buttons/ButtonsController.h"
#include "Modes/MainMode.h"
#include "Modes/TimeSetMode.h"
#include "LedHelper.h"
#include "Modes/TimerMode.h"
#include "Modes/SensorsMode.h"
#include "Modes/MonitorMode.h"
#include "Modes/IdleMode.h"
#include "DS18B20Support/OneWireContext.h"
//---------------------------------------------------------------------------

//Время подавления дребезга нажатия кнопки.
#define BUTTON_INTERRUPT_TIMEOUT_MS 100
//---------------------------------------------------------------------------

#define SIMULATION

enum DeviceStates
{
	Active,
	Sleep
};
//---------------------------------------------------------------------------

class Device
{
	public:
		static void Initialize(void);
		
		static BitStateLedController* bitStateLedControllerPtr;
		static ModesController* modesControllerPtr;
		static ButtonsController* buttonsControllerPtr;
		
		static Button* topButtonPtr;
		static Button* bottomButtonPtr;

		static MainMode* mainModePtr;
		static TimeSetMode* timeSetModePtr;
		static TimerMode* timerModePtr;
		static SensorsMode* sensor1ModePtr;
		static MonitorMode* monitorModePtr;
		static IdleMode* idleModePtr;

		static LedHelper* ledHelperPtr;
		
		static OneWireContext* oneWireContextPtr;
		
		static void LedOff(void);
		static void LedOn(void);
		
		static CFTime GetCurrentTime(void);
		static void SetCurrentTiem(CFTime* timePtr);
		static void ShowTemperature(uint16_t temperatureValue);
		
		static void SetCommonButtonsSettings(void);
		static void SetWakeUpButtonsSettings(void);
		
		static uint8_t isLedEnabled;
		
		static void ShowSearch(void);
		static void ShowError(void);
		static void ClearScreen(void);
	private:
		Device(void);
		Device(Device&);
		
		static BitStateLedController bitStateLedController;
		//static void InitTimer0(void);
		static void init_timer2(void);				
		
};

//---------------------------------------------------------------------------
#endif /* DEVICE_H_ */