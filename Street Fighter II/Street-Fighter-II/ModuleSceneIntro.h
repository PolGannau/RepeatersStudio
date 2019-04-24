#ifndef __MODULESCENEINTRO_H__
#define __MODULESCENEINTRO_H__

#include "Module.h"

struct SDL_Texture;
struct Mix_Music;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro();
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	uint fx = 0;
	Mix_Music* intro_mus = nullptr;

};

#endif // __MODULESCENEINTRO_H__