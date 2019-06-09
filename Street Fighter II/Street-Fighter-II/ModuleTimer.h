#ifndef _MODULETIMER_H_
#define _MODULETIMER_H_
#include "../SDL/include/SDL.h"
#include "Module.h"


class ModuleTimer : public Module
{
public:

	ModuleTimer();
	~ModuleTimer();

public:
	
	int GetTimer();
	Uint32 timeout;
	Uint32 countdown;
	Uint32 endfight;
	Uint32 autowin;

};

#endif // !_TIMER_H_

