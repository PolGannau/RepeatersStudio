#ifndef __MODULE_PLAYERSMANAGER_H__
#define __MODULE_PLAYERSMANAGER_H__

#include "Module.h"
#include "ModuleHonda.h"

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

	ModuleHonda* CreatePlayer(PLAYER_NUMBER);
public:
	//As this is a manager it handles all the players textures
	SDL_Texture*		graphics = nullptr;

	//Player 1 & Player 2 pointers
	ModuleHonda*		player;
	ModuleHonda*		player2;

	int p1puntuation;
	int p2puntuation;
};

#endif // !__MODULE_PLAYERSMANAGER_H__