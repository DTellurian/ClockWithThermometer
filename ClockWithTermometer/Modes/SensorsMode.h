/* 
* SensorsMode.h
*
* Created: 09.10.2015 8:43:09
* Author: Mihalych
*/


#ifndef __SENSOR1MODE_H__
#define __SENSOR1MODE_H__
//---------------------------------------------------------------------------

#include "..\ModesSupport\Mode.h"
#include "..\Buttons\ButtonsControllerConsumer.h"
//---------------------------------------------------------------------------
class SensorsMode : public Mode, public ButtonsControllerConsumer
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		SensorsMode(void);
		~SensorsMode();
		
		virtual void ProceedModeOnTick(void);
		virtual void EnterMode(void);
		virtual void ExitMode(void);
		virtual void ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled);
		virtual void ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled);
	protected:
	private:
		//SensorsMode( const SensorsMode &c );
		SensorsMode& operator=( const SensorsMode &c );
		
		uint8_t displayValue;
		uint16_t temperatureToShow;
		uint64_t nextMillisecondsToMeasure;
		
		void ReadAndDisplay(void);

}; //SensorsMode
//---------------------------------------------------------------------------
#endif //__SENSOR1MODE_H__
