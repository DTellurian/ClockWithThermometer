/*
 * ButtonsController.h
 *
 * Created: 16.05.2012 14:00:38
 *  Author: Mihalych
 */ 


#ifndef BUTTONSCONTROLLER_H_
#define BUTTONSCONTROLLER_H_
//---------------------------------------------------------------------------

#include "ButtonsControllerDefines.h"
#include "Button.h"
#include "ButtonsControllerConsumer.h"
//---------------------------------------------------------------------------


class ButtonsController 
{
	public:
		ButtonsController(void);		
		
		virtual void ButtonsControllerOnTick(void);
		friend class Button;
		
		void AttachButton(Button* buttonPtr);
		void AttachConsumer(ButtonsControllerConsumer* consumerPtr);	
	private:
		ButtonsController(const ButtonsController& c);
		ButtonsController& operator=(const ButtonsController& c);
		
		//Button** buttons;
		Button* buttons[ButtonsControllerButtonsCount];
		uint8_t attachedButtonsCount;
		
		ButtonsControllerConsumer* consumers[ButtonsControllerConsumersCount];
		//ButtonsControllerConsumer** consumers;
		uint8_t attachedConsumersCount;
	
		void ProceedButtonFire(Button* buttonPtr, uint8_t isSealedFire, uint8_t sealedFireNumber);
		void ProceedButtonUpFire(Button* buttonPtr);
};
//---------------------------------------------------------------------------
#endif /* BUTTONSCONTROLLER_H_ */