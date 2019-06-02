#ifndef __MODULESTAGEHONDA_H__
#define __MODULESTAGEHONDA_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleStageHonda :public Module
{
public:
	ModuleStageHonda();
	~ModuleStageHonda();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* stage_texture;

	SDL_Rect wall;
	SDL_Rect floor;
	SDL_Rect roof;
	SDL_Rect pool_wall;
	SDL_Rect pool_top;
	SDL_Rect water_low;
	SDL_Rect water_medium;
	SDL_Rect water_full;
	SDL_Rect win_guy_small;
	SDL_Rect win_guy_big;
	SDL_Rect sun_red;
	SDL_Rect sun_yellow;

	Animation boy;
	Animation sun;
};
#endif // !__MODULESTAGEHONDA_H__
