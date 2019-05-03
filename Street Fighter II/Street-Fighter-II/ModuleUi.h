#ifndef __MODULEUI_H__
#define __MODULEUI_H__

#include "Module.h"

struct SDL_Texture;

class ModuleUi :public Module
{
public:
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* hud = nullptr;

	SDL_Rect lifebar1_rect1;
	SDL_Rect lifebar2_rect1;
	SDL_Rect lifebar1_rect2;
	SDL_Rect lifebar2_rect2;
	SDL_Rect ko_red;
	SDL_Rect ko_white;

	int pos_bar;
	int aux1;
	int aux2;
};
#endif // !__MODULEUI_H__
