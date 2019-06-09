#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "../SDL/include/SDL_scancode.h"
#include "../SDL/include/SDL_gamecontroller.h"
#include "../SDL/include/SDL_events.h"

#define MAX_KEYS 300
#define MAX_CONTROLLERS 2
#define MAX_GAMEPADS 2
#define MAX_BUTTONS 15

enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

class ModuleInput : public Module
{
public:

	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	
	struct Controller
	{
		SDL_GameController *controller = nullptr;
		SDL_JoystickID joyId = -1;
	};

	KEY_STATE keyboard[MAX_KEYS];
	KEY_STATE Controller1[SDL_CONTROLLER_BUTTON_MAX];
	KEY_STATE Controller2[SDL_CONTROLLER_BUTTON_MAX];
	
	SDL_GameControllerButton stringbutton[SDL_CONTROLLER_BUTTON_MAX];
	
	Controller controller[MAX_CONTROLLERS];
	
	SDL_Event event;
};

#endif // __ModuleInput_H__