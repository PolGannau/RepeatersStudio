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
	SDL_Texture* hud = nullptr;

	SDL_Rect lifebar1_rect1;
	SDL_Rect lifebar2_rect1;
	SDL_Rect lifebar1_rect2;
	SDL_Rect lifebar2_rect2;

	SDL_Rect background_rect;
	SDL_Rect temple_mini;
	SDL_Rect roof_brown;
	SDL_Rect sign;
	SDL_Rect floor;
	SDL_Rect ko_red;
	SDL_Rect ko_white;

	Collider* floor_collider;

	int aux1;
	int aux2;
	int pos_bar;

	Mix_Music* ryu_stage_music = nullptr;
};

#endif // __MODULESCENESPACE_H__