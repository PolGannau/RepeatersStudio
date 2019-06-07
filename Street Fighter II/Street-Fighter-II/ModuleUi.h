#ifndef __MODULEUI_H__
#define __MODULEUI_H__

#include "Module.h"

#define KO_TIMER 750

struct SDL_Texture;

class ModuleUi :public Module
{
public:
	ModuleUi();
	~ModuleUi();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* hud = nullptr;

	SDL_Rect lifebar1_rect1;
	SDL_Rect lifebar2_rect1;
	SDL_Rect lifebar1_rect2;
	SDL_Rect lifebar2_rect2;
	SDL_Rect ko_red;
	SDL_Rect ko_white;
	SDL_Rect round_win;

	int pos_bar;
	int aux = 0;
	unsigned int current_time, last_time = 0;
	int i = 0;
	int	j = 0;
	//
	//int current_timer = 0;
	int timer_font = 0;
	char timer_numbers[3];
	//
	int score_font = 0;
	int p1_score = 0;
	int p2_score = 0;
	int high_score = 0;
	char player_score[10];
	//
	int char_font = 0;
	//char char_name[10];
	//

};
#endif // !__MODULEUI_H__
