/*
 * DS18B20.h
 *
 * Created: 27.07.2013 23:04:01
 *  Author: Dmitriy
 */ 


#ifndef DS18B20_H_
#define DS18B20_H_
//---------------------------------------------------------------------------

#include "OWIPolled.h"
#include "OWIHighLevelFunctions.h"
#include "OWIBitFunctions.h"
#include "../OneWireCommon/OWIcrc.h"
//---------------------------------------------------------------------------

//код семейства и коды команд датчика DS18B20
#define DS18B20_FAMILY_ID                0x28 
#define DS18B20_CONVERT_T                0x44
#define DS18B20_READ_SCRATCHPAD          0xbe
#define DS18B20_WRITE_SCRATCHPAD         0x4e
#define DS18B20_COPY_SCRATCHPAD          0x48
#define DS18B20_RECALL_E                 0xb8
#define DS18B20_READ_POWER_SUPPLY        0xb4

//прототипы функций
unsigned char DS18B20_ReadTemperature(unsigned char bus, unsigned char * id, uint16_t *temperature);

//коды ошибок для функции чтения температуры
#define READ_SUCCESSFUL   0x00
#define READ_CRC_ERROR    0x01

#define SEARCH_SENSORS 0x00
#define SENSORS_FOUND 0xff

void ConvertTemperatureMeasurement(uint16_t measurementResult, uint8_t& isPositive, uint8_t& integralPart, uint8_t& fractionPart);
void ConvertTemperatureMeasurement(uint16_t measurementResult, int16_t& result);//-27.3 => -273

//---------------------------------------------------------------------------
#endif /* DS18B20_H_ */