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
	//SDL_Texture* stars = nullptr;
};

#endif // __MODULESCENESPACE_H__