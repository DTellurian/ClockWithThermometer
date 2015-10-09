/* 
* Sensor1Mode.h
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
class Sensor1Mode : public Mode, public ButtonsControllerConsumer
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		Sensor1Mode(void);
		~Sensor1Mode();
		
		virtual void ProceedModeOnTick(void);
		virtual void EnterMode(void);
		virtual void ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled);
		virtual void ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled);
	protected:
	private:
		//Sensor1Mode( const Sensor1Mode &c );
		Sensor1Mode& operator=( const Sensor1Mode &c );
		
		uint8_t displayValue;
		uint16_t temperatureToShow;
		
		void ReadAndDisplay(void);

}; //Sensor1Mode
//---------------------------------------------------------------------------
#endif //__SENSOR1MODE_H__
