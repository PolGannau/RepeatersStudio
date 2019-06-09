#include "ModuleUi.h"
#include "Application.h"
#include "ModuleRyuStage.h"
#include "ModuleStageHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleWin.h"
#include "ModuleLose.h"
#include "ModuleFonts.h"
#include "ModuleTimer.h"
#include "ModulePlayersManager.h"
#include "../SDL/include/SDL_timer.h"


ModuleUi::ModuleUi()
{}

ModuleUi::~ModuleUi()
{}

bool ModuleUi::Start()
{
	LOG("Loading Ui");
	hud = App->textures->Load("Assets/Images/Ui/Lifebar_assets.png");
	
	
	score_font = App->fonts->Load("Assets/Images/Ui/Fonts/FontPScore.png", "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~'!@#$%^&*()-_+=[]{}| :;¨º<>,./?", 1);
	char_font = App->fonts->Load("Assets/Images/Ui/Fonts/CharName.png", "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789~·!@#$%^&*()-+=[]{}|:;ç'<>,./? ", 1);
	timer_font = App->fonts->Load("Assets/Images/Ui/Fonts/timervalues.png", "0123456789<> ", 1);

	lifebar1_rect2 = { 2,2,149,13 };
	lifebar2_rect2 = { 2,2,149,13 };
	lifebar1_rect1 = { 0,18,153,17 };
	lifebar2_rect1 = { 0,18,153,17 };
	ko_white = { 34,37,26,22 };
	ko_red = { 1,36,27,24 };
	round_win = { 66,36,17,20 };

	pos_bar = 149;
	
	start_time = SDL_GetTicks()/1000;

	return true;
}

bool ModuleUi::CleanUp()
{
	LOG("Unloading Ui");
	
	App->textures->Unload(hud);
	App->fonts->UnLoad(score_font);
	App->fonts->UnLoad(char_font);
	App->fonts->UnLoad(timer_font);
	return true;
}

update_status ModuleUi::Update()
{
	//decresion of lifebar player 2
	//lifebar2_rect2.w = 149 * App->player2->life / 100;

	//decresion of lifebar player 1
	//lifebar1_rect2.w = 149 * App->player->life / 100;

	//blit the health bars
	//red ones
	App->render->Blit(hud, 27, 12, &lifebar1_rect1, NULL);
	App->render->Blit(hud, 23 + lifebar1_rect1.w + ko_red.w, 12 , &lifebar2_rect1, NULL);
	//orange ones
	App->render->Blit(hud, 178 - lifebar1_rect2.w, 14, &lifebar1_rect2, NULL);
	App->render->Blit(hud, 25 + lifebar1_rect1.w + ko_red.w , 14, &lifebar2_rect2, NULL);

	//blit the K.O
	App->render->Blit(hud, 178, 9, &ko_red, NULL);
	App->render->Blit(hud, 179, 10, &ko_white, NULL);
	   

	App->fonts->BlitText(2, 0, score_font, "1P");
	App->fonts->BlitText(150, 0, score_font, "HI");
	App->fonts->BlitText(280, 0, score_font, "2P");
	App->fonts->BlitText(30, 30, char_font, "E.HONDA");
	App->fonts->BlitText(270, 30, char_font, "E.HONDA");
	   	 
	TimerBlit();

	Puntuation();
	App->fonts->BlitText(-App->render->camera.x / SCREEN_SIZE + 120 - strlen(p1score) * 12, 0, score_font, p1score);
	App->fonts->BlitText(-App->render->camera.x / SCREEN_SIZE + 380 - strlen(p2score) * 12, 0, score_font, p2score);
	App->fonts->BlitText(-App->render->camera.x / SCREEN_SIZE + 260 - strlen(hscore) * 12, 0, score_font, hscore);

	/*if ((current_time - last_time) >= KO_TIMER)
	{
		last_time = current_time;
	}
	if ((App->manager->player->hp <= 25 || App->manager->player2->hp <= 25) && (current_time - last_time) < KO_TIMER / 4)
	{
		App->render->Blit(hud, 178, 7, &ko_red, NULL);
	}

	//round wins
	//player2 round win
	if (App->manager->player->life <= 0 && !App->honda_stage->control)
	{
		if (App->player2->round_won)App->player2->game_won = true;
		App->player2->round_won = true;
		if (App->player2->game_won == true)App->fade->FadeToBlack(App->honda_stage, App->module_lose);
		App->fade->FadeToBlack(App->honda_stage, App->honda_stage);
		App->honda_stage->control = false;
	}
	if (App->player2->round_won == true)App->render->Blit(hud, SCREEN_WIDTH - 17, 10, &round_win, NULL);

	//player1 round win
	if (App->player2->life <= 0 && !App->honda_stage->control)
	{
		if (App->player->round_won)App->player->game_won = true;
		App->player->round_won = true;
		if (App->player->game_won == true)App->fade->FadeToBlack(App->honda_stage, App->module_win);
		App->fade->FadeToBlack(App->honda_stage, App->honda_stage);
		App->honda_stage->control = false;
	}
	if (App->player->round_won == true)App->render->Blit(hud, 0, 10, &round_win, NULL);
	*/
	Puntuation();
	App->fonts->BlitText(-App->render->camera.x / SCREEN_SIZE + 120 - strlen(p1score) * 12, 0, score_font, p1score);
	App->fonts->BlitText(-App->render->camera.x / SCREEN_SIZE + 380 - strlen(p2score) * 12, 0, score_font, p2score);
	App->fonts->BlitText(-App->render->camera.x / SCREEN_SIZE + 260 - strlen(hscore) * 12, 0, score_font, hscore);

	return UPDATE_CONTINUE;
}

void ModuleUi::Puntuation() {
	std::string p1score_str = std::to_string(App->manager->player->score);
	std::string p2score_str = std::to_string(App->manager->player2->score);
	int score1 = App->manager->player->score;
	int score2 = App->manager->player2->score;

	if (score1 > score2) {
		std::string hscore_str = std::to_string(App->manager->player->score);
		hscore = new char[hscore_str.length() + 1];
		strcpy_s(hscore, hscore_str.length() + 1, hscore_str.c_str());
	}
	else {
		std::string hscore_str = std::to_string(App->manager->player2->score);
		hscore = new char[hscore_str.length() + 1];
		strcpy_s(hscore, hscore_str.length() + 1, hscore_str.c_str());
	}

	p1score = new char[p1score_str.length() + 1];
	strcpy_s(p1score, p1score_str.length() + 1, p1score_str.c_str());

	p2score = new char[p2score_str.length() + 1];
	strcpy_s(p2score, p2score_str.length() + 1, p2score_str.c_str());
}

void ModuleUi::TimerBlit() {

	if (start_time <= SDL_GetTicks() - 1000 && time_fight > 0) {
		--time_fight;
		start_time = SDL_GetTicks();
	}
	sprintf_s(timer, 10, "%7d", time_fight);
	App->fonts->BlitText(99, 35, timer_font, timer);

	
}

