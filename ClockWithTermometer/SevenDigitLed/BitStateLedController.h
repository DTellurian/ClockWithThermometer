/*
 * BitStateLedController.h
 *
 * Created: 22.07.2013 22:49:41
 *  Author: Dmitriy
 */ 


#ifndef BITSTATELEDCONTROLLER_H_
#define BITSTATELEDCONTROLLER_H_
//---------------------------------------------------------------------------

#include "..\BaseTypes\Pin.h"
#include "BitLedState.h"
//---------------------------------------------------------------------------

//    _    _    _    _
//   /_/  /_/  /_/  /_/
//  /_/  /_/  /_/  /_/
//  [3]  [2]  [1]  [0]

class BitStateLedController
{
	public:
		BitStateLedController(Pin* aPtr, Pin* bPtr, Pin* cPtr, Pin* dPtr, Pin* ePtr, Pin* fPtr, Pin* gPtr, Pin* dpPtr, OnLevelType ledOnValue, OnLevelType digitsOnValue, uint8_t digitsCount);
		
		uint8_t* digitStates;
		Pin** digitPins;		
		uint8_t digitsCount;	
		
		Pin* pinPtrArray[LEDS_IN_DIGIT];
		
		void NextDigit(void);
	private:
		BitStateLedController(void);
		BitStateLedController(const BitStateLedController&);
	
		uint8_t currentDigitIndex;
		
		OnLevelType ledOnValue;
		OnLevelType digitsOnValue;
};
//---------------------------------------------------------------------------
#endif /* BITSTATELEDCONTROLLER_H_ */