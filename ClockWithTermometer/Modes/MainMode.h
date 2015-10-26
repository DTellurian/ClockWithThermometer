/*
 * MainMode.h
 *
 * Created: 17.02.2015 13:33:21
 *  Author: Mihalych
 */ 


#ifndef MAINMODE_H_
#define MAINMODE_H_
//---------------------------------------------------------------------------

#include "..\ModesSupport\Mode.h"
#include "..\Buttons\ButtonsControllerConsumer.h"
//---------------------------------------------------------------------------

class MainMode : public Mode, public ButtonsControllerConsumer
{
	public:
		MainMode(void);
		
		virtual void ProceedModeOnTick(void);
		virtual void EnterMode(void);
		virtual void ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled);
		virtual void ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled);
	private:
		MainMode( const MainMode&c );
		MainMode& operator=( const MainMode&c );
};
//---------------------------------------------------------------------------
#endif /* MAINMODE_H_ */