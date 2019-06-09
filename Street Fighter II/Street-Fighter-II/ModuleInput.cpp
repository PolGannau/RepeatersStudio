#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "../SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module()
{
	for (uint i = 0; i < MAX_KEYS; ++i)
		keyboard[i] = KEY_IDLE;
}

// Destructor
ModuleInput::~ModuleInput()
{
}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	// controller
	LOG("Init controller");

	if (SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) < 0)
	{
		LOG("GamePad controller could not initialize! SDL_Error: %s\n", SDL_GetError());
	}


	int maxJoys = SDL_NumJoysticks();


	for (int i = 0; i < maxJoys; ++i)

	{
		if (i >= MAX_GAMEPADS) break;

		if (SDL_IsGameController(i))
		{
			gamepad[i] = SDL_GameControllerOpen(i);
		}
		if (SDL_IsGameController(i))
		{
			gamepad2[i] = SDL_GameControllerOpen(i);
		}
	}

	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keys[i] == 1)
		{
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}
	SDL_PollEvent(&Events);

	if (keyboard[SDL_SCANCODE_ESCAPE] || Events.type == SDL_QUIT)
		return update_status::UPDATE_STOP;

	if (keyboard[SDL_QUIT]) {
		return update_status::UPDATE_STOP;
	}

	// Controller

	for (int i = 0; i < MAX_GAMEPADS; ++i)
	{
		if (gamepad[i] != nullptr)
		{
			controller_state[BUTTON_A] = SDL_GameControllerGetButton(gamepad[i], SDL_CONTROLLER_BUTTON_A);
		}
		if (gamepad[i] != nullptr)
		{
			controller_state[BUTTON_B] = SDL_GameControllerGetButton(gamepad[i], SDL_CONTROLLER_BUTTON_B);
		}
		if (gamepad[i] != nullptr)
		{
			controller_state[BUTTON_X] = SDL_GameControllerGetButton(gamepad[i], SDL_CONTROLLER_BUTTON_X);
		}
		if (gamepad[i] != nullptr)
		{
			controller_state[BUTTON_Y] = SDL_GameControllerGetButton(gamepad[i], SDL_CONTROLLER_BUTTON_Y);
		}
		/*if (gamepad[i]!=nullptr)
		{
			controller_state[BUTTON_DPAD_DOWN] = SDL_GameControllerGetButton(gamepad[i], SDL_CONTROLLER_BUTTON_DPAD_DOWN);
		}
		if (gamepad[i] != nullptr)
		{
			controller_state[BUTTON_DPAD_UP] = SDL_GameControllerGetButton(gamepad[i], SDL_CONTROLLER_BUTTON_DPAD_UP);
		}
		if (gamepad[i] != nullptr)
		{
			controller_state[BUTTON_DPAD_LEFT] = SDL_GameControllerGetButton(gamepad[i], SDL_CONTROLLER_BUTTON_DPAD_LEFT);
		}
		if (gamepad[i] != nullptr)
		{
			controller_state[BUTTON_DPAD_RIGHT] = SDL_GameControllerGetButton(gamepad[i], SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
		}*/
		/*if (gamepad[i] != nullptr)
		{
			controller_state[BUTTON_L1] = SDL_GameControllerGetButton(gamepad[i], SDL_CONTROLLER_AXIS_TRIGGERLEFT);
		}*/
		if (gamepad[i] != nullptr)
		{
			controller_state[BUTTON_START] = SDL_GameControllerGetButton(gamepad[i], SDL_CONTROLLER_BUTTON_START);
		}
		if (gamepad[i] != nullptr)
		{
			controller_state[BUTTON_BACK] = SDL_GameControllerGetButton(gamepad[i], SDL_CONTROLLER_BUTTON_BACK);
		}
		/*if (gamepad2[i] != nullptr)
		{
		controller_state[BUTTON_A] = SDL_GameControllerGetButton(gamepad2[i], SDL_CONTROLLER_BUTTON_A);
		}*/
	}

	for (int i = 0; i < MAX_BUTTONS; ++i)
	{
		if (controller_state[i] == 1) {
			if (controller[i] == KEY_IDLE)
				controller[i] = KEY_DOWN;
			else
				controller[i] = KEY_REPEAT;
		}
		else
		{
			if (controller[i] == KEY_REPEAT || controller[i] == KEY_DOWN)
				controller[i] = KEY_UP;
			else
				controller[i] = KEY_IDLE;
		}
	}

	if (Events.type == SDL_CONTROLLERDEVICEADDED)
	{
		if (Events.cdevice.which > MAX_GAMEPADS - 1)
		{
			LOG("Maximum number of gamepads reached, you cannot connect more...");

		}

		else if (SDL_IsGameController(Events.cdevice.which))
		{
			gamepad[Events.cdevice.which] = SDL_GameControllerOpen(Events.cdevice.which);
			LOG("Controller added: %d", Events.cdevice.which);
		}

	}


	// Controller inputs: Axis
	for (int i = 0; i < MAX_GAMEPADS; ++i)
	{
		if (gamepad[i] != nullptr)
		{
			GamepadDir[i].X = SDL_GameControllerGetAxis(gamepad[i], SDL_CONTROLLER_AXIS_LEFTX);
			GamepadDir[i].Y = SDL_GameControllerGetAxis(gamepad[i], SDL_CONTROLLER_AXIS_LEFTY);
		}
		if (gamepad2[i] != nullptr)
		{
			GamepadDir[i].X = SDL_GameControllerGetAxis(gamepad2[i], SDL_CONTROLLER_AXIS_LEFTX);
			GamepadDir[i].Y = SDL_GameControllerGetAxis(gamepad2[i], SDL_CONTROLLER_AXIS_LEFTY);
		}
	}


	if (GamepadDir[0].X > GamepadDir[0].deadzone)
	{
		keyboard[SDL_SCANCODE_D] = KEY_REPEAT;
	}

	else if (GamepadDir[0].X < -GamepadDir[0].deadzone)
	{
		keyboard[SDL_SCANCODE_A] = KEY_REPEAT;
	}


	if (GamepadDir[0].Y < -GamepadDir[0].deadzone)
	{
		keyboard[SDL_SCANCODE_W] = KEY_DOWN;
	}

	else if (GamepadDir[0].Y > GamepadDir[0].deadzone)
	{
		keyboard[SDL_SCANCODE_S] = KEY_REPEAT;
	}

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}
