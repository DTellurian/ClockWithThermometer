/*
 * ModesController.h
 *
 * Created: 19.05.2012 16:25:06
 *  Author: Dmitriy
 */ 


#ifndef MODESCONTROLLER_H_
#define MODESCONTROLLER_H_
//---------------------------------------------------------------------------

#include "Mode.h"
//---------------------------------------------------------------------------

class ModesController
{
	public:
		ModesController();
		
		void SetCurrentMode(Mode* modePtr);
		
		Mode* currentModePtr;
	protected:
	private:		
		ModesController( const ModesController&c );
		ModesController& operator=( const ModesController&c );
};
//---------------------------------------------------------------------------
#endif /* MODESCONTROLLER_H_ */