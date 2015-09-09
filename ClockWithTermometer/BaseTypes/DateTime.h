/*
 * DateTime.h
 *
 * Created: 10.08.2012 10:17:05
 *  Author: Mihalych
 */ 


#ifndef DATETIME_H_
#define DATETIME_H_
//---------------------------------------------------------------------------

#include <inttypes.h>
#include "CFTime.h"
#include "CFDate.h"
//---------------------------------------------------------------------------

class DateTime
{
	public:
		static void Initialize(uint16_t ticksInSecond, uint16_t millisecondsInTick);
		
		static void OnSecondsTick(void);
		static void OnMillisecondsTick(void);
		
		static CFTime CurrentTime;
		static CFDate CurrentDate;
		
		static volatile uint64_t milliseconds;
	private:
		DateTime(void);
		
		static volatile uint16_t ticksCount;
		
		static uint16_t ticksInSecond;
		static uint16_t millisecondsInTick;			
};

//---------------------------------------------------------------------------
#endif /* DATETIME_H_ */