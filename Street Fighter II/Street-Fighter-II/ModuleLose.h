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

	SDL_Texture* texture_winner = nullptr;
	SDL_Texture* texture_loser = nullptr;
	SDL_Texture* texture_text = nullptr;
	SDL_Rect text_rect;
	Mix_Music* loose_music = nullptr;
};
#endif // !__MODULELOSE_H__
