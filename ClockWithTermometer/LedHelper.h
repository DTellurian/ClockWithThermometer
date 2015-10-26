/*
 * LedHelper.h
 *
 * Created: 18.02.2015 13:10:35
 *  Author: Mihalych
 */ 


#ifndef LEDHELPER_H_
#define LEDHELPER_H_
//---------------------------------------------------------------------------

#include "BaseTypes/CFTime.h"
//---------------------------------------------------------------------------

class LedHelper
{
	public:
		LedHelper(void);
		
		void ShowTime(CFTime* timePtr, uint8_t showSeconds);
		void ProceedTick(void);
		
		uint8_t leftSideBlinkEnabled;
		uint8_t leftSideVisibility;
		
		uint8_t rightSideBlinkEnabled;
		uint8_t rightSideVisibility;
		
		uint8_t pointBlinkEnabled;
		
		uint64_t millisecondToBlink;
		
		void ShowAllBlinked(void);
	private:
		LedHelper(const LedHelper& c);
		LedHelper& operator=(const LedHelper& c);
};
//---------------------------------------------------------------------------
#endif /* LEDHELPER_H_ */