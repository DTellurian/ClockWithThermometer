/* 
* IdleMode.h
*
* Created: 12.10.2015 15:17:13
* Author: Mihalych
*/


#ifndef __IDLEMODE_H__
#define __IDLEMODE_H__
//---------------------------------------------------------------------------

#include "..\ModesSupport\Mode.h"
#include "..\Buttons\ButtonsControllerConsumer.h"
//---------------------------------------------------------------------------

enum IdleModeState
{
	DeviceActive,
	WaitForWakeUp	
};

class IdleMode : public Mode, public ButtonsControllerConsumer
{
	//variables
	public:
	protected:
	private:

	//functions
	public:
		IdleMode();
		~IdleMode();
		
		virtual void ProceedModeOnTick(void);
		virtual void EnterMode(void);
		virtual void ExitMode(void);
		virtual void ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled);
		virtual void ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled);
	protected:
	private:
		IdleMode( const IdleMode &c );
		IdleMode& operator=( const IdleMode &c );
		
		IdleModeState state;
		uint64_t wakeupTimeLimit;
		
		void GoToSleep(void);

}; //IdleMode
//---------------------------------------------------------------------------
#endif //__IDLEMODE_H__
