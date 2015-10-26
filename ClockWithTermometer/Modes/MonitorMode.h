/* 
* MonitorMode.h
*
* Created: 12.10.2015 15:17:01
* Author: Mihalych
*/


#ifndef __MONITORMODE_H__
#define __MONITORMODE_H__
//---------------------------------------------------------------------------

#include "..\ModesSupport\Mode.h"
#include "..\Buttons\ButtonsControllerConsumer.h"
//---------------------------------------------------------------------------

enum MonitorState
{
	ModeNameDisplay,
	TimeDisplay,
	SensorsDisplay
};
//---------------------------------------------------------------------------

class MonitorMode : public Mode, public ButtonsControllerConsumer
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		MonitorMode();
		~MonitorMode();
		
		virtual void ProceedModeOnTick(void);
		virtual void EnterMode(void);
		virtual void ExitMode(void);
		virtual void ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled);
		virtual void ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled);
	protected:
	private:
		//MonitorMode( const MonitorMode &c );
		MonitorMode& operator=( const MonitorMode &c );
		
		uint8_t sensorIndex;
		MonitorState monitorState;
		uint64_t nextStateShowTime;
		
		uint64_t nextMillisecondsToSensorMeasure;
}; //MonitorMode
//---------------------------------------------------------------------------
#endif //__MONITORMODE_H__
