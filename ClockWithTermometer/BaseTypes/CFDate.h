/*
 * CFDate.h
 *
 * Created: 18.04.2013 0:06:59
 *  Author: Dmitriy
 */ 


#ifndef CFDATE_H_
#define CFDATE_H_
//---------------------------------------------------------------------------

#include <inttypes.h>
#define MaxDayNumber 7
#define FirstDayNumber 1
//---------------------------------------------------------------------------
class CFDate
{
	public:
		CFDate(void);
		
		void AddDay(void);		
		void SubstractDay(void);
		uint8_t GetDayNumber(void);
		uint8_t GetDaysInterval(uint8_t externDayNumber);
	private:
		volatile uint8_t dayNumber;
};
//---------------------------------------------------------------------------
#endif /* CFDATE_H_ */