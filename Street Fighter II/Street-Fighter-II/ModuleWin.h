#ifndef __MODULEWIN_H__
#define __MODULEWIN_H__

#include "Module.h"

struct SDL_Texture;

class ModuleWin : public Module
{
public:
	ModuleWin();
	~ModuleWin();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* texture_text = nullptr;
	uint fx = 0;
	SDL_Texture* texture_winner = nullptr;
	SDL_Texture* texture_loser = nullptr;
};

#endif // !__MODULEWIM_H__
