//---------------------------------------------------------------------------

#ifndef CFTimeH
#define CFTimeH
//---------------------------------------------------------------------------

#include <inttypes.h>
//#include <stdint.h>
//#include <stdlib.h>
//---------------------------------------------------------------------------

class CFTime
{
	public:
		CFTime(void);           
		CFTime(uint8_t hours, uint8_t minutes, uint8_t seconds);
		CFTime(uint64_t totalSeconds);
		
		void ToString(char* stringPtr);

		void AddSecond(void);
		void AddMinute(uint8_t onlyMinutes = 0);
		void AddHour(void);
		
		void SubtractSecond(void);
		void SubtractMinute(uint8_t onlyMinutes = 0);
		void SubtractHour(void);
		
		uint8_t GetHoursFirstDigit(void);
		uint8_t GetHoursSecondDigit(void);

		uint8_t GetMinutesFirstDigit(void);
		uint8_t GetMinutesSecondDigit(void);

		uint8_t GetSecondsFirstDigit(void);
		uint8_t GetSecondsSecondDigit(void);
		
		uint8_t IsEquals(const CFTime& target) const;
		uint8_t IsLastSecondOfDay(void) const;
		
		void SetTime(uint8_t hours, uint8_t minutes, uint8_t seconds);
		void GetTime(uint8_t& hours, uint8_t& minutes, uint8_t& seconds);
		
		uint64_t GetTotalMilliseconds() const;
		uint64_t GetTotalSeconds(void) const;
		
		uint8_t GetHours(void) const;
		uint8_t GetMinutes(void) const;
		uint8_t GetSeconds(void) const;
	private:
		volatile uint8_t hours;
		volatile uint8_t minutes;
		volatile uint8_t seconds;
};
//---------------------------------------------------------------------------
#endif