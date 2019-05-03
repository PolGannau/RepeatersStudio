#ifndef __MODULERYUSTAGE_H__
#define __MODULERYUSTAGE_H__

#include "Module.h"

struct SDL_Texture;

class ModuleRyuStage : public Module
{
public:
	ModuleRyuStage();
	~ModuleRyuStage();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background_texture = nullptr;

	SDL_Rect background_rect;
	SDL_Rect temple_mini;
	SDL_Rect roof_brown;
	SDL_Rect sign;
	SDL_Rect floor;

	Collider* floor_collider;

	Mix_Music* ryu_stage_music = nullptr;
};

#endif // __MODULESCENESPACE_H__