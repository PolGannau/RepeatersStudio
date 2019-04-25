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

	SDL_Texture* background = nullptr;
	uint fx = 0;
	SDL_Texture* texture = nullptr;
	SDL_Rect* winner_rect;
	SDL_Rect* loser_rect;
};

#endif // !__MODULEWIM_H__
