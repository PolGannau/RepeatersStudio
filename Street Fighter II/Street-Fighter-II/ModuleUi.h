#ifndef __MODULEUI_H__
#define __MODULEUI_H__

#include "Module.h"
#include <string>

#define KO_TIMER 750
#define TIMER_VALUE 9900

struct SDL_Texture;

class ModuleUi :public Module
{
public:
	ModuleUi();
	~ModuleUi();

	bool Start();
	update_status Update();
	bool CleanUp();
	void Puntuation();
	void TimerBlit();

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
	int score_font = 0;
	char* p1score;
	char* p2score;
	char* hscore;
	//
	int char_font = 0;
	//
	int timer_font = 0;
	char timer[10];
	uint time_fight = 99;
	uint start_time;
	uint time_deviation;
};
#endif // !__MODULEUI_H__
