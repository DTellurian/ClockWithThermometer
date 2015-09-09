/*
 * Device.h
 *
 * Created: 27.10.2014 23:09:20
 *  Author: Mihalych
 */ 


#ifndef DEVICE_H_
#define DEVICE_H_

//---------------------------------------------------------------------------

#include "SevenDigitLed/BitStateLedController.h"
#include "BaseTypes/rtc.h"
#include "ModesSupport/ModesController.h"
#include "Buttons/ButtonsController.h"
#include "Modes/MainMode.h"
#include "Modes/TimeSetMode.h"
#include "LedHelper.h"
#include "Modes/TimerMode.h"
//---------------------------------------------------------------------------

//����� ���������� �������� ������� ������.
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

		static LedHelper* ledHelperPtr;		
		
		static CFTime GetCurrentTime(void);
		static void SetCurrentTiem(CFTime* timePtr);
	private:
		Device(void);
		Device(Device&);
		
		static BitStateLedController bitStateLedController;
		//static void InitTimer0(void);
		static void init_timer2(void);
};

//---------------------------------------------------------------------------
#endif /* DEVICE_H_ */