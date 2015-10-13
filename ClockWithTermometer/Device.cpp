/*
 * Device.cpp
 *
 * Created: 27.10.2014 23:09:33
 *  Author: Mihalych
 */ 
//---------------------------------------------------------------------------

#include "Device.h"


#include <avr/io.h>
#include <avr/interrupt.h>
#include "SevenDigitLed/BitStateLedController.h"
#include "Device\Ports.h"
#include "SevenDigitLed\BitLedState.h"
#include "BaseTypes\CFTime.h"
#include "BaseTypes\DateTime.h"
#include "DS18B20Support\DS18B20.h"
//---------------------------------------------------------------------------

#define APIN pinB5
#define BPIN pinB3
#define CPIN pinD5
#define DPIN pinB6
#define EPIN pinD0
#define FPIN pinB4
#define GPIN pinD6
#define DPPIN pinB7
#define dig1PIN pinB0
#define dig2PIN pinB1
#define dig3PIN pinB2
#define dig4PIN pinD7
#define led1PIN pinC0
#define led2PIN pinC1
#define sensorsPowerPIN pinD3

#ifndef SIMULATION
BitStateLedController Device::bitStateLedController(&APIN, &BPIN, &CPIN, &DPIN, &EPIN, &FPIN, &GPIN, &DPPIN, Low, Low, 4);
#else	
BitStateLedController Device::bitStateLedController(&APIN, &BPIN, &CPIN, &DPIN, &EPIN, &FPIN, &GPIN, &DPPIN, Low, Hight, 4);
#endif

BitStateLedController* Device::bitStateLedControllerPtr;
ModesController* Device::modesControllerPtr;
ButtonsController* Device::buttonsControllerPtr;

Button* Device::topButtonPtr;
Button* Device::bottomButtonPtr;

MainMode* Device::mainModePtr;
TimeSetMode* Device::timeSetModePtr;
TimerMode* Device::timerModePtr;
SensorsMode* Device::sensor1ModePtr;
MonitorMode* Device::monitorModePtr;
IdleMode* Device::idleModePtr;

LedHelper* Device::ledHelperPtr;
OneWireContext* Device::oneWireContextPtr;

uint8_t Device::isLedEnabled = 1;
//---------------------------------------------------------------------------

void Device::Initialize(void)
{	
	bitStateLedControllerPtr = &bitStateLedController;
	
	dig1PIN.SetAsOutput();
	dig2PIN.SetAsOutput();
	dig3PIN.SetAsOutput();
	dig4PIN.SetAsOutput();
	
	//dig1PIN.SetHightLevel();
	//dig2PIN.SetHightLevel();
	//dig3PIN.SetHightLevel();
	//dig4PIN.SetHightLevel();
	
	bitStateLedControllerPtr->digitPins[0] = &dig4PIN;
	bitStateLedControllerPtr->digitPins[1] = &dig3PIN;
	bitStateLedControllerPtr->digitPins[2] = &dig2PIN;
	bitStateLedControllerPtr->digitPins[3] = &dig1PIN;
	
	Device::SetCommonButtonsSettings();
	
	Device::oneWireContextPtr->Init();
	
	DateTime::Initialize(260, 4);
	
	sei();
	
	init_timer2();
}
//---------------------------------------------------------------------------

void Device::SetCommonButtonsSettings(void)
{
	Device::topButtonPtr->enabled = 1;
	Device::topButtonPtr->enabledButtonUpFire = 1;
	Device::topButtonPtr->enableSealing = 0;
	Device::topButtonPtr->SetDelay(1000);
	Device::topButtonPtr->enabledButtonUpFire = 1;
	Device::topButtonPtr->buttonUpDelayMs = 50;
	
	Device::bottomButtonPtr->enabled = 1;
	Device::bottomButtonPtr->SetDelay(500);
	Device::bottomButtonPtr->enableSealing = 1;
	Device::bottomButtonPtr->SetSealingDelay(150, 150);
	Device::bottomButtonPtr->enabledButtonUpFire = 1;
	Device::bottomButtonPtr->buttonUpDelayMs = 50;	
}
//---------------------------------------------------------------------------

void Device::SetWakeUpButtonsSettings(void)
{	
	Device::topButtonPtr->enabledButtonUpFire = 0;	
	Device::topButtonPtr->SetDelay(2000);
	Device::topButtonPtr->enabledButtonUpFire = 0;	
		
	Device::bottomButtonPtr->SetDelay(2000);
	Device::bottomButtonPtr->enableSealing = 0;	
	Device::bottomButtonPtr->enabledButtonUpFire = 0;	
}
//---------------------------------------------------------------------------
//
//void Device::InitTimer0(void)
//{
	////TCCR0 = _BV(CS02);// | _BV(CS01) | _BV(CS00);
	//TCCR0 = _BV(CS01);
	//TIMSK |= _BV(TOIE0);
//}
////---------------------------------------------------------------------------

void Device::init_timer2(void)  //Инициализация таймера/счетчика2
{		
	OCR2A = 60;
	TCCR2A = _BV(WGM21);
	TCCR2B = _BV(CS22);
	TIMSK2 |= _BV(OCIE2A);  //Устанавливаем для него прерывание совпадения
}
//---------------------------------------------------------------------------

ISR(TIMER2_COMPA_vect)
{	
	DateTime::OnMillisecondsTick();
	DateTime::OnSecondsTick();
	
	if(Device::isLedEnabled == 1)
		Device::bitStateLedControllerPtr->NextDigit();
}
//---------------------------------------------------------------------------

CFTime Device::GetCurrentTime(void)
{
	dateTime currentTime = get_date_time();
	return CFTime(currentTime.hour, currentTime.minute, currentTime.second);
}
//---------------------------------------------------------------------------

void Device::SetCurrentTiem(CFTime* timePtr)
{
	dateTime currentTime = get_date_time();
	currentTime.hour = timePtr->GetHours();
	currentTime.minute = timePtr->GetMinutes();
	set_date_time(currentTime);
}
//---------------------------------------------------------------------------

void Device::ShowTemperature(uint16_t temperatureValue)
{
	uint8_t isPositive = 0;
	uint8_t integralPart = 0;
	uint8_t fractionPart = 0;

	BitLedState::SetDot(0, Device::bitStateLedControllerPtr->digitStates[2]);
	BitLedState::SetDot(1, Device::bitStateLedControllerPtr->digitStates[1]);

	ConvertTemperatureMeasurement(temperatureValue, isPositive, integralPart, fractionPart);
	
	cli();
	//currentState = __save_interrupt();
	//__disable_interrupt();
	
	if(integralPart > 9)
	{
		if(isPositive)
		BitLedState::ClearDigit(bitStateLedControllerPtr->digitStates[3]);
		else
		BitLedState::SetMinus(bitStateLedControllerPtr->digitStates[3]);
		
		BitLedState::SetDigitState(integralPart, bitStateLedControllerPtr->digitStates[2], bitStateLedControllerPtr->digitStates[1]);
		BitLedState::SetDigitState(fractionPart, bitStateLedControllerPtr->digitStates[0]);
	}
	else
	{
		BitLedState::ClearDigit(bitStateLedControllerPtr->digitStates[3]);
		
		if(isPositive)
		BitLedState::ClearDigit(bitStateLedControllerPtr->digitStates[2]);
		else
		BitLedState::SetMinus(bitStateLedControllerPtr->digitStates[2]);
		
		BitLedState::SetDigitState(integralPart, bitStateLedControllerPtr->digitStates[1]);
		BitLedState::SetDigitState(fractionPart, bitStateLedControllerPtr->digitStates[0]);
	}
	//__restore_interrupt(currentState);
	sei();
}
//---------------------------------------------------------------------------

void Device::LedOff(void)
{
	isLedEnabled = 0;
	
	dig1PIN.SetHightLevel();
	dig2PIN.SetHightLevel();
	dig3PIN.SetHightLevel();
	dig4PIN.SetHightLevel();
}
//---------------------------------------------------------------------------

void Device::LedOn(void)
{
	isLedEnabled = 1;
}
//---------------------------------------------------------------------------