/*
 * BitStateLedController.cpp
 *
 * Created: 22.07.2013 22:49:54
 *  Author: Dmitriy
 */ 
//---------------------------------------------------------------------------

#include "BitStateLedController.h"
#include <stdlib.h>
//---------------------------------------------------------------------------

BitStateLedController::BitStateLedController(Pin* aPtr, Pin* bPtr, Pin* cPtr, Pin* dPtr, Pin* ePtr, Pin* fPtr, Pin* gPtr, Pin* dpPtr, OnLevelType ledOnValue, OnLevelType digitsOnValue, uint8_t digitsCount)
	:currentDigitIndex(0)
{	
	this->ledOnValue = ledOnValue;
	this->digitsOnValue = digitsOnValue;
	this->digitsCount = digitsCount;
	
	this->digitStates = (uint8_t*)calloc(digitsCount, sizeof(uint8_t));
	this->digitPins = (Pin**)calloc(digitsCount, sizeof(Pin*));

	aPtr->SetAsOutput();
	bPtr->SetAsOutput();
	cPtr->SetAsOutput();
	dPtr->SetAsOutput();
	ePtr->SetAsOutput();
	fPtr->SetAsOutput();
	gPtr->SetAsOutput();
	dpPtr->SetAsOutput();
	
	pinPtrArray[0] = dpPtr;
	pinPtrArray[1] = gPtr;
	pinPtrArray[2] = fPtr;
	pinPtrArray[3] = ePtr;
	pinPtrArray[4] = dPtr;
	pinPtrArray[5] = cPtr;
	pinPtrArray[6] = bPtr;
	pinPtrArray[7] = aPtr;
}
//---------------------------------------------------------------------------

void BitStateLedController::NextDigit(void)
{	
	/*
	digitPins[0]->SetValue(!digitsOnValue);
	digitPins[1]->SetValue(digitsOnValue);
	digitPins[2]->SetValue(digitsOnValue);
	digitPins[3]->SetValue(!digitsOnValue);
	*/
	digitPins[currentDigitIndex]->SetValue(!digitsOnValue);
	
	if(currentDigitIndex != digitsCount - 1)
		currentDigitIndex++;
	else
		currentDigitIndex = 0;	
	
	for(uint8_t i = 0; i <= MAX_LED_INDEX_IN_DIGIT; i++)
	{
		uint8_t pinState = (digitStates[currentDigitIndex] & (0x01 << i)) > 0 ? ledOnValue : !ledOnValue;
		pinPtrArray[i]->SetValue(pinState);
	}
	
	digitPins[currentDigitIndex]->SetValue(digitsOnValue);
}
//---------------------------------------------------------------------------