#ifndef __MODULEWIN_H__
#define __MODULEWIN_H__

#include "Module.h"

struct SDL_Texture;

class ModuleWin : public Module
{
public:
	ModuleWin();
	~ModuleWin();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* portraits;

	SDL_Texture* texture_text = nullptr;
	SDL_Texture* texture_winner = nullptr;
	SDL_Texture* texture_loser = nullptr;

	SDL_Rect text_rect;
	SDL_Rect winner_rect;
	SDL_Rect loser_rect;

	uint fx = 0;
	Mix_Music* music = nullptr;

	SDL_Rect portrait_win;
	SDL_Rect portrait_loose;
	int win_font = 0;
	
};

#endif // !__MODULEWIM_H__
