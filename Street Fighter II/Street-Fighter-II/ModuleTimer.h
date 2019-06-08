#ifndef _MODULETIMER_H_
#define _MODULETIMER_H_
#include "../SDL/include/SDL.h"
#include "Module.h"


class ModuleTimer : public Module 
{
private:

	static ModuleTimer* instancevalue;

	unsigned int startticks;
	unsigned int elapsedticks;

	float deltatimevalue;
	float timescalevalue;

public:
	//ModuleTimer(float DeltaTime, float TimeScale);

	ModuleTimer();
	~ModuleTimer();

	static ModuleTimer* Instance();
	static void Release();

	void Reset();
	float DeltaTime();

	void TimeScale(float t);
	float TimeScale();

	void TimerUpdate();


};

#endif // !_TIMER_H_

