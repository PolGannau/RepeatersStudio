#ifndef __MODULESTAGEHONDA_H__
#define __MODULESTAGEHONDA_H__

#include "Module.h"
#include "Animation.h"

#define BOY_TIMER 750

struct SDL_Texture;

class ModuleStageHonda :public Module
{
public:
	ModuleStageHonda();
	~ModuleStageHonda();

	bool Start();
	update_status Update();
	bool CleanUp();
	void GetTime();

public:
	SDL_Texture* stage_texture;
	SDL_Texture* light_texture;

	SDL_Rect wall;
	SDL_Rect floor;
	SDL_Rect roof;
	SDL_Rect pool_wall;
	SDL_Rect pool_top;
	SDL_Rect water_low;
	SDL_Rect water_medium;
	SDL_Rect water_full;
	SDL_Rect win_guy_small;
	SDL_Rect win_guy_big;
	SDL_Rect sun_red;
	SDL_Rect sun_yellow;
	SDL_Rect light;
	SDL_Rect mirrors;
	SDL_Rect floor_tape;
	SDL_Rect boy_small;
	SDL_Rect boy_big;

	bool control;

	unsigned int current_time = 0;
	unsigned int last_time = 0;

	Animation sun;

	Mix_Music* stahe_honda_music;

	//
	int timer_font = 0;
	char* timer;
	unsigned int timer_start;
	unsigned int timer_aux;
	int timer_delay;
	int time1;
	int time2;
	uint time_fight = 99;
};
#endif // !__MODULESTAGEHONDA_H__
