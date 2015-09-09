/*
 * BitLedState.h
 *
 * Created: 18.07.2013 14:38:42
 *  Author: Dmitriy
 */ 


#ifndef BITLEDSTATE_H_
#define BITLEDSTATE_H_

//---------------------------------------------------------------------------

#include <inttypes.h>
//---------------------------------------------------------------------------

enum OnLevelType
{	
	Low,
	Hight
};
//---------------------------------------------------------------------------

#define LEDS_IN_DIGIT 8
#define MAX_LED_INDEX_IN_DIGIT 7

class BitLedState
{
	public:
		static void SetDigitState(uint8_t decimalValue, uint8_t& digitState);			
		
		static void SetDot(uint8_t isOn, uint8_t& digitState);
		static void InverseDot(uint8_t& digitState);
		
		static void ClearDigit(uint8_t& digitState);
		static void SetDigitState(uint8_t decimalValue, uint8_t& secondDigitState, uint8_t& firstDigitState);
		static void SetDigitState(uint16_t decimalValue, uint8_t& thirdDigitState, uint8_t& secondDigitState, uint8_t& firstDigitState);
		
		static void SetMinus(uint8_t& digitState);		
	private:
		
		static void SetDigitPinState(uint8_t decimalValue, uint8_t& digitState);
	
		BitLedState(void);
		BitLedState(const BitLedState&);
};
//---------------------------------------------------------------------------

#endif /* BITLEDSTATE_H_ */