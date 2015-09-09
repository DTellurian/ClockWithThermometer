/*
 * TimerMode.h
 *
 * Created: 19.02.2015 17:47:20
 *  Author: Mihalych
 */ 


#ifndef TIMERMODE_H_
#define TIMERMODE_H_
//---------------------------------------------------------------------------

#include "..\ModesSupport\Mode.h"
#include "..\Buttons\ButtonsControllerConsumer.h"
//---------------------------------------------------------------------------

class TimerMode : public Mode, public ButtonsControllerConsumer
{
	public:
		TimerMode(void);
	
		virtual void ProceedModeOnTick(void);
		virtual void EnterMode(void);
		virtual void ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled);
		virtual void ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled);
	private:
		uint8_t isRun;
		uint64_t startSecondsCount;
		uint64_t lastMeasuredSecondsCount;
};
//---------------------------------------------------------------------------
#endif /* TIMERMODE_H_ */