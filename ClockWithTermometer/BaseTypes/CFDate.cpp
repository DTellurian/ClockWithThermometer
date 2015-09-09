/*
 * CFDate.cpp
 *
 * Created: 18.04.2013 0:07:15
 *  Author: Dmitriy
 */ 
//---------------------------------------------------------------------------

#include "CFDate.h"
//---------------------------------------------------------------------------

CFDate::CFDate(void)
	:dayNumber(FirstDayNumber)
{
	
}
//---------------------------------------------------------------------------

void CFDate::AddDay(void)
{
	if(dayNumber == MaxDayNumber)
		dayNumber = FirstDayNumber;
	else
		dayNumber++;
}
//---------------------------------------------------------------------------		

void CFDate::SubstractDay(void)
{
	if(dayNumber == FirstDayNumber)
		dayNumber = MaxDayNumber;
	else
		dayNumber--;
}
//---------------------------------------------------------------------------

uint8_t CFDate::GetDayNumber(void)
{
	return dayNumber;
}
//---------------------------------------------------------------------------

uint8_t CFDate::GetDaysInterval(uint8_t externDayNumber)
{
	if(dayNumber >= externDayNumber)	
		return dayNumber - externDayNumber;
	else
		return MaxDayNumber - externDayNumber + dayNumber;
}
//---------------------------------------------------------------------------
