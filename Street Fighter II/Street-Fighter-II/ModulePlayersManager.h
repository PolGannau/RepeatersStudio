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

	//sfx
	//Sound Effects
	Mix_Chunk* lightpunch_sfx;
	Mix_Chunk* mediumpunch_sfx;
	Mix_Chunk* heavypunch_sfx;
	Mix_Chunk* lightkick_sfx;
	Mix_Chunk* mediumkick_sfx;
	Mix_Chunk* heavykick_sfx;
	Mix_Chunk* special_sfx;
	Mix_Chunk* block_sfx;
	Mix_Chunk* laugh_sfx;
	Mix_Chunk* nonhit_sfx;

	//Sound Effects
	Mix_Chunk* lightpunch_sfx;
	Mix_Chunk* mediumpunch_sfx;
	Mix_Chunk* heavypunch_sfx;
	Mix_Chunk* lightkick_sfx;
	Mix_Chunk* mediumkick_sfx;
	Mix_Chunk* heavykick_sfx;
	Mix_Chunk* special_sfx;
	Mix_Chunk* block_sfx;
	Mix_Chunk* laugh_sfx;


		
};

#endif // !__MODULE_PLAYERSMANAGER_H__