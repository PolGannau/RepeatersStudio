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
#define MAX_BUTTONS 10

enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

enum BUTTONS
{
	BUTTON_A,
	BUTTON_B,
	BUTTON_X,
	BUTTON_Y,
	BUTTON_L1,
	BUTTON_R1,
	BUTTON_L2,
	BUTTON_R2,
	BUTTON_BACK,
	BUTTON_START,
	BUTTON_DPAD_UP,
	BUTTON_DPAD_DOWN,
	BUTTON_DPAD_LEFT,
	BUTTON_DPAD_RIGHT
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
	
	KEY_STATE keyboard[MAX_KEYS];
	SDL_Event Events;

	KEY_STATE controller[MAX_BUTTONS];
	KEY_STATE controller2[MAX_BUTTONS];

	bool controller_state[MAX_BUTTONS];
	SDL_GameController* gamepad[MAX_GAMEPADS] = { nullptr };
	SDL_GameController* gamepad2[MAX_GAMEPADS] = { nullptr };

	struct ControlDir
	{
		bool up = false;
		bool down = false;
		bool left = false;
		bool right = false;
		Sint16 X = 0;
		Sint16 Y = 0;
		int deadzone = 5000;
	};

	ControlDir GamepadDir[MAX_GAMEPADS];
};

#endif // __ModuleInput_H__