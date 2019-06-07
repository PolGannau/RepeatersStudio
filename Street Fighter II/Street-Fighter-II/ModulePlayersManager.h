#ifndef __MODULE_PLAYERSMANAGER_H__
#define __MODULE_PLAYERSMANAGER_H__

#include "Module.h"

struct SDL_Texture;

// This class controls the characters (Player1 and Player2)
class ModulePlayersManager : public Module
{
public:
	ModulePlayersManager();
	~ModulePlayersManager();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	//As this is a manager it handles all the players textures
	SDL_Textures*		graphics = nullptr;

};

#endif // !__MODULE_PLAYERSMANAGER_H__