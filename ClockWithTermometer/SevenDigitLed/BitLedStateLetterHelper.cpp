/* 
* BitLedStateLetterHelper.cpp
*
* Created: 12.10.2015 11:53:59
* Author: Mihalych
*/


#include "BitLedStateLetterHelper.h"
//---------------------------------------------------------------------------

// default constructor
BitLedStateLetterHelper::BitLedStateLetterHelper()
{
} //BitLedStateLetterHelper
//---------------------------------------------------------------------------

// default destructor
BitLedStateLetterHelper::~BitLedStateLetterHelper()
{
} //~BitLedStateLetterHelper
//---------------------------------------------------------------------------

void BitLedStateLetterHelper::SetA(uint8_t& digitState)
{
	digitState = 0b11101110;	
}
//---------------------------------------------------------------------------

void BitLedStateLetterHelper::SetE(uint8_t& digitState)
{
	digitState = 0b10011110;
}
//---------------------------------------------------------------------------

void BitLedStateLetterHelper::SetH(uint8_t& digitState)
{
	digitState = 0b01101110;
}
//---------------------------------------------------------------------------

void BitLedStateLetterHelper::SetR(uint8_t& digitState)
{
	digitState = 0b10001100;
}
//---------------------------------------------------------------------------

void BitLedStateLetterHelper::SetI(uint8_t& digitState)
{
	digitState = 0b01100000;
}
//---------------------------------------------------------------------------

void BitLedStateLetterHelper::SetL(uint8_t& digitState)
{
	digitState = 0b00011100;
}
//---------------------------------------------------------------------------

void BitLedStateLetterHelper::SetO(uint8_t& digitState)
{
	digitState = 0b11111100;
}
//---------------------------------------------------------------------------

void BitLedStateLetterHelper::SetS(uint8_t& digitState)
{
	digitState = 0b10110110;
}
//---------------------------------------------------------------------------

void BitLedStateLetterHelper::SetF(uint8_t& digitState)
{
	digitState = 0b10001110;
}
//---------------------------------------------------------------------------

void BitLedStateLetterHelper::SetD(uint8_t& digitState)
{
	digitState = 0b01111010;
}
//---------------------------------------------------------------------------

void BitLedStateLetterHelper::SetP(uint8_t& digitState)
{
	digitState = 0b11001110;
}
//---------------------------------------------------------------------------