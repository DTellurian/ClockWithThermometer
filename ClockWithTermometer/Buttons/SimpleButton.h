/*
 * SimpleButton.h
 *
 * Created: 19.01.2014 18:04:05
 *  Author: Mihalych
 */ 


#ifndef SIMPLEBUTTON_H_
#define SIMPLEBUTTON_H_
//---------------------------------------------------------------------------

#include "Button.h"
//---------------------------------------------------------------------------

class SimpleButton : public Button
{
	public:						
		SimpleButton(ButtonsController* buttonsControllerPtr, Pin* pinPtr, uint16_t delayMs);		
	
	protected:
		virtual uint8_t IsPressed(void);
		
	private:
		SimpleButton(void);
		
		Pin* pinPtr;
};
//---------------------------------------------------------------------------
#endif /* SIMPLEBUTTON_H_ */