/*
 * TimeSetMode.h
 *
 * Created: 18.02.2015 12:45:29
 *  Author: Mihalych
 */ 


#ifndef TIMESETMODE_H_
#define TIMESETMODE_H_
//---------------------------------------------------------------------------

#include "..\ModesSupport\Mode.h"
#include "..\Buttons\ButtonsControllerConsumer.h"
//---------------------------------------------------------------------------

class TimeSetMode : public Mode, public ButtonsControllerConsumer
{
	public:
		TimeSetMode(void);
			
		virtual void ProceedModeOnTick(void);
		
		virtual void EnterMode(void);
		virtual void ExitMode(void);
		
		virtual void ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled);
		virtual void ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled);
				
	private:
		uint8_t isMinutesEditing;
		void SetTime(void);
};
//---------------------------------------------------------------------------
#endif /* TIMESETMODE_H_ */