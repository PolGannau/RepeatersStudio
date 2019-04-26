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

	SDL_Texture* background = nullptr;
	SDL_Texture* hud = nullptr;

	SDL_Rect* lifebar1_rect;
	SDL_Rect* lifebar2_rect;

	Mix_Music* ryu_stage_music = nullptr;
};

#endif // __MODULESCENESPACE_H__