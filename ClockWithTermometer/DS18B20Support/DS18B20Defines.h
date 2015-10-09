/*
 * DS18B20Defines.h
 *
 * Created: 31.07.2013 9:32:34
 *  Author: Dmitriy
 */ 


#ifndef DS18B20DEFINES_H_
#define DS18B20DEFINES_H_
//---------------------------------------------------------------------------

#include "../DeviceConfiguration.h"
#include "OWIPolled.h"


	//вывод, к которому подключены 1Wire устройства
	#define BUS   OWI_PIN_4

	//количество устройств на шине 1Wire
	//#define MAX_DEVICES       0x02

	#define     CPU_FREQUENCY   1.000

	// Port configuration registers for 1-Wire buses.
	// Make sure that all three registers belong to the same port.
	#define     OWI_PORT        PORTD   //!< 1-Wire PORT Data register. 
	#define     OWI_PIN         PIND    //!< 1-Wire Input pin register.
	#define     OWI_DDR         DDRD    //!< 1-Wire
	
//---------------------------------------------------------------------------
#endif /* DS18B20DEFINES_H_ */