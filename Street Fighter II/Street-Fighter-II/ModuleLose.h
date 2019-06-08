#ifndef __MODULELOSE_H__
#define __MODULELOSE_H__

#include "Module.h"
#include "../SDL/include/SDL_render.h"

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

	SDL_Texture* portraits = nullptr;

	SDL_Texture* texture_winner = nullptr;
	SDL_Texture* texture_loser = nullptr;
	SDL_Texture* texture_text = nullptr;
	SDL_Rect text_rect;
	Mix_Music* loose_music = nullptr;
	SDL_Rect portrait_win;
	SDL_Rect portrait_loose;
	int loose_font = 0;

};
#endif // !__MODULELOSE_H__
