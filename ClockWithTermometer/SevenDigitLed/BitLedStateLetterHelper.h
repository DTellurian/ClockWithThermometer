/* 
* BitLedStateLetterHelper.h
*
* Created: 12.10.2015 11:53:59
* Author: Mihalych
*/


#ifndef __BITLEDSTATELETTERHELPER_H__
#define __BITLEDSTATELETTERHELPER_H__
//---------------------------------------------------------------------------

#include <inttypes.h>
//---------------------------------------------------------------------------

class BitLedStateLetterHelper
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		static void SetA(uint8_t& digitState);
		static void SetE(uint8_t& digitState);
		static void SetH(uint8_t& digitState);
		static void SetR(uint8_t& digitState);
		static void SetI(uint8_t& digitState);
		static void SetL(uint8_t& digitState);
		static void SetO(uint8_t& digitState);
		static void SetS(uint8_t& digitState);
		static void SetF(uint8_t& digitState);
		static void Circle(uint8_t& digitState, uint16_t delayMs);
		
		~BitLedStateLetterHelper();
	protected:
	private:
		BitLedStateLetterHelper();
		BitLedStateLetterHelper( const BitLedStateLetterHelper &c );
		BitLedStateLetterHelper& operator=( const BitLedStateLetterHelper &c );

}; //BitLedStateLetterHelper
//---------------------------------------------------------------------------
#endif //__BITLEDSTATELETTERHELPER_H__
