/* 
* OneWireContext.h
*
* Created: 09.10.2015 10:37:16
* Author: Mihalych
*/


#ifndef __ONEWIRECONTEXT_H__
#define __ONEWIRECONTEXT_H__
//---------------------------------------------------------------------------

#include "OWIHighLevelFunctions.h"
#include "DS18B20Defines.h"
//---------------------------------------------------------------------------

class OneWireContext
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		OneWireContext(uint8_t maxDevices);
		~OneWireContext();
		
		void Init(void);		
		uint8_t ReadTemperature(uint16_t* temperature);
				
		uint8_t currentSensorIndex;
		uint8_t IsSearchState(void);
		uint8_t SetNextSensor(void);
	protected:
		//OWI_device allDevices[MAX_DEVICES];
		OWI_device* allDevices;
		unsigned char rom[8];
		
		unsigned char searchFlag;			
		unsigned char crcFlag;
		unsigned char sensorsCount;
		
	private:
		//OneWireContext( const OneWireContext &c );
		OneWireContext& operator=( const OneWireContext &c );
		uint8_t maxDevicesCount;

}; //OneWireContext
//---------------------------------------------------------------------------
#endif //__ONEWIRECONTEXT_H__
