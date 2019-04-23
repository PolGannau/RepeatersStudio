#ifndef __MODULELOSE_H__
#define __MODULELOSE_H__

#include "Module.h"

struct SDL_Texture;

class ModuleLose : public Module
{
public:
	ModuleLose();
	~ModuleLose();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	uint fx = 0;
};
#endif // !__MODULELOSE_H__
