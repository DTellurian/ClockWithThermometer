/*
 * BitLedState.cpp
 *
 * Created: 18.07.2013 14:38:57
 *  Author: Dmitriy
 */ 
//---------------------------------------------------------------------------

#include "BitLedState.h"
//---------------------------------------------------------------------------

void BitLedState::SetDigitState(uint8_t decimalValue, uint8_t& digitState)
{
	uint8_t lastDigit = decimalValue % 10;
	
	SetDigitPinState(lastDigit, digitState);
}
//---------------------------------------------------------------------------

void BitLedState::SetDot(uint8_t isOn, uint8_t& digitState)
{
	if(isOn)
		digitState = digitState | 0b00000001;
	else
		digitState = digitState & 0b11111110;
}
//---------------------------------------------------------------------------

void BitLedState::InverseDot(uint8_t& digitState)
{
	if(digitState & 0b00000001)
		SetDot(0, digitState);
	else
		SetDot(1, digitState);
}
//---------------------------------------------------------------------------

void BitLedState::ClearDigit(uint8_t& digitState)
{
	digitState = (digitState & 0b00000001) | 0b00000000;
}
//---------------------------------------------------------------------------

void BitLedState::SetDigitState(uint8_t decimalValue, uint8_t& secondDigitState, uint8_t& firstDigitState)
{
	SetDigitState(decimalValue, firstDigitState);
	SetDigitState(decimalValue / 10, secondDigitState);
}
//---------------------------------------------------------------------------

void BitLedState::SetDigitState(uint16_t decimalValue, uint8_t& thirdDigitState, uint8_t& secondDigitState, uint8_t& firstDigitState)
{
	SetDigitState(decimalValue, firstDigitState);
	SetDigitState(decimalValue / 10, secondDigitState);
	SetDigitState(decimalValue / 100, thirdDigitState);
}
//---------------------------------------------------------------------------

void BitLedState::SetDigitPinState(uint8_t decimalValue, uint8_t& digitState)
{
	if(decimalValue == 0)
		digitState = (digitState & 0b00000001) | 0b11111100;
	else if(decimalValue == 1)
		digitState = (digitState & 0b00000001) | 0b01100000;
	else if(decimalValue == 2)
		digitState = (digitState & 0b00000001) | 0b11011010;
	else if(decimalValue == 3)
		digitState = (digitState & 0b00000001) | 0b11110010;
	else if(decimalValue == 4)
		digitState = (digitState & 0b00000001) | 0b01100110;
	else if(decimalValue == 5)
		digitState = (digitState & 0b00000001) | 0b10110110;
	else if(decimalValue == 6)
		digitState = (digitState & 0b00000001) | 0b10111110;
	else if(decimalValue == 7)
		digitState = (digitState & 0b00000001) | 0b11100000;
	else if(decimalValue == 8)
		digitState = (digitState & 0b00000001) | 0b11111110;
	else if(decimalValue == 9)
		digitState = (digitState & 0b00000001) | 0b11110110;
}
//---------------------------------------------------------------------------

void BitLedState::SetMinus(uint8_t& digitState)
{
	digitState = (digitState & 0b00000001) | 0b00000010;
}
//---------------------------------------------------------------------------