/* 
* OneWireContext.cpp
*
* Created: 09.10.2015 10:37:15
* Author: Mihalych
*/
//---------------------------------------------------------------------------

#include "OneWireContext.h"
#include "OWIBitFunctions.h"
#include <stdlib.h>
#include "DS18B20.h"
//---------------------------------------------------------------------------

// default constructor
OneWireContext::OneWireContext(uint8_t maxDevices)
	:searchFlag(SEARCH_SENSORS), crcFlag(0), sensorsCount(0), currentSensorIndex(0), maxDevicesCount(maxDevices)
{
	allDevices = (OWI_device*)calloc(maxDevices, sizeof(OWI_device));
} //OneWireContext
//---------------------------------------------------------------------------

// default destructor
OneWireContext::~OneWireContext()
{
} //~OneWireContext
//---------------------------------------------------------------------------

void OneWireContext::Init(void)
{
	#ifndef SIMULATION
	OWI_Init(BUS);
	#else
	Device::sensorsCount = 2;
	#endif
}
//---------------------------------------------------------------------------

uint8_t OneWireContext::ReadTemperature(uint16_t* temperature)
{
	if (searchFlag == SEARCH_SENSORS)
	{
		sensorsCount = 0;
		crcFlag = OWI_SearchDevices(allDevices, maxDevicesCount, BUS, &sensorsCount);
			
		if (crcFlag != SEARCH_CRC_ERROR)
		{
			searchFlag = SENSORS_FOUND;
			currentSensorIndex = 0;
		}
		else
			return 0;
	}
	
	crcFlag = DS18B20_ReadTemperature(BUS, allDevices[currentSensorIndex].id, temperature);
	
	if (crcFlag == READ_CRC_ERROR)
	{
		searchFlag = SEARCH_SENSORS;
		_delay_ms(3000);
		
		return 0;
	}
	
	return 1;
}
//---------------------------------------------------------------------------
