/*
 * ButtonsControllerConsumer.h
 *
 * Created: 19.05.2012 22:48:13
 *  Author: Dmitriy
 */ 


#ifndef BUTTONSCONTROLLERCONSUMER_H_
#define BUTTONSCONTROLLERCONSUMER_H_

//---------------------------------------------------------------------------

#include "Button.h"
//---------------------------------------------------------------------------

class ButtonsControllerConsumer
{
	public:
		virtual void ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber, uint8_t& handled){};
		virtual void ProceedButtonUpFire(Button* buttonPtr, uint8_t& handled){};
};
//---------------------------------------------------------------------------
#endif /* BUTTONSCONTROLLERCONSUMER_H_ */