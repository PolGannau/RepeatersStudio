#ifndef __MODULESCENEINTRO_H__
#define __MODULESCENEINTRO_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro();
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	Animation intro;

	SDL_Texture* background = nullptr;
	SDL_Texture* intro_image = nullptr;
	uint fx = 0;
	Mix_Music* intro_mus = nullptr;

	int capcom_font = 0;
	int repeaters_font = 0;
};

#endif // __MODULESCENEINTRO_H__