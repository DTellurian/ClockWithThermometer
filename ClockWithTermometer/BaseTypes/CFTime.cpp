/*
 * CFTime.cpp
 *
 * Created: 23.05.2012 21:14:26
 *  Author: Dmitriy
 */ 
//---------------------------------------------------------------------------

#include "CFTime.h"
#include <stdio.h>
//---------------------------------------------------------------------------

#define MinutesSecondsMaxCount 60
#define HourSecondsMaxCount 3600

CFTime::CFTime(void)
{
	seconds = 40;
	minutes = 59;
	hours = 23;
}
//---------------------------------------------------------------------------

CFTime::CFTime(uint8_t hours, uint8_t minutes, uint8_t seconds)
{
	this->SetTime(hours, minutes, seconds);
}
//---------------------------------------------------------------------------

CFTime::CFTime(uint64_t totalSeconds)
{
	hours = (uint8_t)(totalSeconds / HourSecondsMaxCount);
	totalSeconds -= hours * HourSecondsMaxCount;
	
	minutes = (uint8_t)(totalSeconds / MinutesSecondsMaxCount);
	seconds = totalSeconds - minutes * 	MinutesSecondsMaxCount;	
}
//---------------------------------------------------------------------------

void CFTime::ToString(char* stringPtr)
{
	//itoa(hours, stringPtr, 10);
	sprintf(stringPtr, "%.2d:%.2d:%.2d", hours, minutes, seconds); 
}
//---------------------------------------------------------------------------

void CFTime::AddSecond(void)
{
	if(seconds == 59)	
	{
		seconds = 0;
		AddMinute();
	}
	else
		seconds++;
}
//---------------------------------------------------------------------------

void CFTime::AddMinute(uint8_t onlyMinutes)
{
	if(minutes == 59)
	{
		minutes = 0;
		
		if(onlyMinutes != 1)
			AddHour();
	}
	else
		minutes++;
}
//---------------------------------------------------------------------------	

void CFTime::AddHour(void)
{	
	if(hours == 23)
		hours = 0;
	else
		hours++;
}
//---------------------------------------------------------------------------

void CFTime::SubtractSecond(void)
{
	if(seconds == 0)	
	{
		seconds = 59;
		SubtractMinute();
	}
	else
		seconds--;
}
//---------------------------------------------------------------------------

void CFTime::SubtractMinute(uint8_t onlyMinutes)
{
	if(minutes == 0)
	{
		minutes = 59;
		
		if(onlyMinutes != 1)
			SubtractHour();
	}
	else
		minutes--;
}
//---------------------------------------------------------------------------

void CFTime::SubtractHour(void)
{
	if(hours == 0)
		hours = 23;
	else
		hours--;
}
//---------------------------------------------------------------------------

uint8_t CFTime::GetHoursFirstDigit(void)
{
	return hours / 10;
}
//---------------------------------------------------------------------------

uint8_t CFTime::GetHoursSecondDigit(void)
{
	return hours % 10;
}
//---------------------------------------------------------------------------

uint8_t CFTime::GetMinutesFirstDigit(void)
{
	return minutes / 10;
}
//---------------------------------------------------------------------------

uint8_t CFTime::GetMinutesSecondDigit(void)
{
	return minutes % 10;
}
//---------------------------------------------------------------------------

uint8_t CFTime::GetSecondsFirstDigit(void)
{
	return seconds / 10;
}
//---------------------------------------------------------------------------

uint8_t CFTime::GetSecondsSecondDigit(void)
{
	return seconds % 10;
}
//---------------------------------------------------------------------------

uint8_t CFTime::IsEquals(const CFTime& target) const
{
	return target.seconds == seconds &&
		target.minutes == minutes &&
		target.hours == hours;
}
//---------------------------------------------------------------------------

#define LastDayHour 23
#define LastHourMinute 59
#define  LastMinuteSecond 59

uint8_t CFTime::IsLastSecondOfDay(void) const
{
	return seconds == LastMinuteSecond&&
		minutes == LastHourMinute&&
		hours == LastDayHour;	
}
//---------------------------------------------------------------------------

void CFTime::SetTime(uint8_t hours, uint8_t minutes, uint8_t seconds)
{	
	if(hours >= 0 && hours < 24)
		this->hours = hours;
	else
		this->hours = 0;
		
	if(minutes >= 0 && minutes < MinutesSecondsMaxCount)
		this->minutes = minutes;
	else
		this->minutes = 0;
		
	if(seconds >= 0 && seconds < MinutesSecondsMaxCount)
		this->seconds = seconds;	
	else
		this->seconds = 0;
}
//---------------------------------------------------------------------------

void CFTime::GetTime(uint8_t& hours, uint8_t& minutes, uint8_t& seconds)
{
	hours = this->hours;
	minutes = this->minutes;
	seconds = this->seconds;
}
//---------------------------------------------------------------------------

uint64_t CFTime::GetTotalMilliseconds() const
{
	uint64_t result = (uint64_t)seconds * 1000;
	result += (uint64_t)minutes * MinutesSecondsMaxCount  * 1000;
	result += (uint64_t)hours * HourSecondsMaxCount * 1000;
	return result;	
}
//---------------------------------------------------------------------------

uint64_t CFTime::GetTotalSeconds(void) const
{
	uint64_t result = (uint64_t)seconds;
	result += (uint64_t)minutes * MinutesSecondsMaxCount;
	result += (uint64_t)hours * HourSecondsMaxCount;
	return result;
}
//---------------------------------------------------------------------------

uint8_t CFTime::GetHours(void) const
{
	return hours;
}
//---------------------------------------------------------------------------

uint8_t CFTime::GetMinutes(void) const
{
	return minutes;
}
//---------------------------------------------------------------------------

uint8_t CFTime::GetSeconds(void) const
{
	return seconds;
}
//---------------------------------------------------------------------------