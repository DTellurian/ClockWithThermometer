/*
 * Button.h
 *
 * Created: 16.05.2012 13:56:39
 *  Author: Mihalych
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
//---------------------------------------------------------------------------

#include "../BaseTypes/Pin.h"

class ButtonsController;
//---------------------------------------------------------------------------

class Button
{
	public:			 					
		void OnTick(void);
		
		void SetDelay(uint16_t delayMs);
		void SetSealingDelay(uint16_t firstSealingDelayMs, uint16_t betweenSealingDelayMs);
		
		volatile uint8_t enabled;
		volatile uint8_t enableSealing;
	
		volatile uint8_t enabledButtonUpFire;
		volatile uint16_t buttonUpDelayMs;
	protected:	
		Button(void);
		Button(ButtonsController* buttonsControllerPtr, uint16_t delayMs);
		void Initialize(ButtonsController* buttonsControllerPtr, uint16_t delayMs);
				
		void ProceedFire(uint8_t isSealingEvent);
		void ProceedButtonUpFire(void);
		
		ButtonsController* buttonsControllerPtr;				
		
		volatile uint16_t delayMs;
		
		volatile uint16_t firstSealingDelayMs;
		volatile uint16_t betweenSealingDelayMs;
		
		volatile uint8_t wasPressed;
		volatile uint64_t pressedMilliseconds;
		
		volatile uint8_t fireFlag;
		
		volatile uint8_t sealingFireFlag;
		volatile uint16_t sealingFireCounter;			
		
		virtual uint8_t IsPressed(void){return 0;};	
	private:
		Button(const Button& c);
		Button& operator=(const Button& c);
};
//---------------------------------------------------------------------------
#endif /* BUTTON_H_ */