#include "ModuleTimer.h"
#include "Application.h"

ModuleTimer* ModuleTimer::instancevalue = NULL;


ModuleTimer* ModuleTimer::Instance() {

	if (instancevalue == NULL) {
		instancevalue = new ModuleTimer;
	}

	return instancevalue;
}

void ModuleTimer::Release() {

	delete instancevalue;
	instancevalue = NULL;

}

ModuleTimer::ModuleTimer() {

	Reset();
	timescalevalue = 1.0f;
	
}

ModuleTimer::~ModuleTimer() {

}

void ModuleTimer::Reset() {

	startticks = SDL_GetTicks();
	elapsedticks = 0;
	deltatimevalue = 0.0f;
	
}

float ModuleTimer::DeltaTime() {

	return deltatimevalue;

}

void ModuleTimer::TimeScale(float t) {

	timescalevalue = t;

}

float ModuleTimer::TimeScale() {

	return timescalevalue;

}

void ModuleTimer::TimerUpdate() {

	elapsedticks = SDL_GetTicks() - startticks;
	deltatimevalue = elapsedticks * 0.001f;
	
	
}