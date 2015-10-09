/*
 * DS18B20.cpp
 *
 * Created: 27.07.2013 23:04:08
 *  Author: Dmitriy
 */ 
//---------------------------------------------------------------------------

#include "DS18B20.h"
//---------------------------------------------------------------------------

unsigned char DS18B20_ReadTemperature(unsigned char bus, unsigned char * id, uint16_t* temperature)
{
    unsigned char scratchpad[9];
    unsigned char i;
  
    /*подаем сигнал сброса
    команду для адресации 1-Wire устройства на шине
    подаем команду - запук преобразования */
    OWI_DetectPresence(bus);
    OWI_MatchRom(id, bus);
    OWI_SendByte(DS18B20_CONVERT_T ,bus);

    /*ждем, когда датчик завершит преобразование*/ 
    while (!OWI_ReadBit(bus));

    /*подаем сигнал сброса
    команду для адресации 1-Wire устройства на шине
    команду - чтение внутренней памяти
    затем считываем внутреннюю память датчика в массив
    */
    OWI_DetectPresence(bus);
    OWI_MatchRom(id, bus);
    OWI_SendByte(DS18B20_READ_SCRATCHPAD, bus);
    for (i = 0; i<=8; i++){
      scratchpad[i] = OWI_ReceiveByte(bus);
    }
    
    if(OWI_CheckScratchPadCRC(scratchpad) != OWI_CRC_OK){
      return READ_CRC_ERROR;
    }
    
    *temperature = (unsigned int)scratchpad[0];
    *temperature |= ((unsigned int)scratchpad[1] << 8);
    
    return READ_SUCCESSFUL;
}
//---------------------------------------------------------------------------

void ConvertTemperatureMeasurement(uint16_t measurementResult, uint8_t& isPositive, uint8_t& integralPart, uint8_t& fractionPart)
{
	if((measurementResult & 0x8000) == 0)
	{
		isPositive = 1;
	}
	else
	{
		isPositive = 0;
		measurementResult = ~measurementResult + 1;
	}
	
	integralPart = (uint8_t)(measurementResult >> 4);
	fractionPart = integralPart;
	fractionPart = (uint8_t)(measurementResult  & 15);
	fractionPart = (fractionPart >> 1) + (fractionPart >> 3);
}
//---------------------------------------------------------------------------

void ConvertTemperatureMeasurement(uint16_t measurementResult, int16_t& result)//-27.3 => -273
{
	uint8_t isPositive;
	uint8_t integralPart;
	uint8_t fractionPart;
	
	ConvertTemperatureMeasurement(measurementResult, isPositive, integralPart, fractionPart);
	
	result = (integralPart * 10 + fractionPart) * (isPositive == 1 ? 1 : -1);
}
//---------------------------------------------------------------------------