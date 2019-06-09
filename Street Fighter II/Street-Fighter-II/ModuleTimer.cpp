#include "ModuleTimer.h"
#include "Application.h"

ModuleTimer::ModuleTimer() {

}

ModuleTimer::~ModuleTimer() {

}

int ModuleTimer::GetTimer() {
	return (timeout - SDL_GetTicks()) / 1000;
}