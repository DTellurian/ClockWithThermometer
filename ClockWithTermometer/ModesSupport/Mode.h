/*
 * Mode.h
 *
 * Created: 19.05.2012 16:23:17
 *  Author: Dmitriy
 */ 


#ifndef MODE_H_
#define MODE_H_

//---------------------------------------------------------------------------

#include <stdint.h>
//---------------------------------------------------------------------------
class Mode
{
	public:
		Mode();
		
		friend class ModesController;
		virtual void ProceedModeOnTick(void){};
			
	protected:
		virtual void EnterMode(void){};
		virtual void ExitMode(void){};
		
		uint8_t isActive;
		
	private:
		Mode( const Mode&c );
		Mode& operator=( const Mode&c );
};
//---------------------------------------------------------------------------
#endif /* MODE_H_ */