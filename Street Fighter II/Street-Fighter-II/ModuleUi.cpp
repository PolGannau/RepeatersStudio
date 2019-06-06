#include "ModuleUi.h"
#include "Application.h"
#include "ModuleRyuStage.h"
#include "ModuleStageHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer2.h"
#include "ModuleWin.h"
#include "ModuleLose.h"
#include "ModuleFonts.h"
#include "../SDL/include/SDL_timer.h"


ModuleUi::ModuleUi()
{}

ModuleUi::~ModuleUi()
{}

bool ModuleUi::Start()
{
	LOG("Loading Ui");
	hud = App->textures->Load("Assets/Images/Ui/Lifebar_assets.png");
	
	timer_font = App->fonts->Load("Assets/Images/Ui/FontsCaps2.png","ABCDEFGHIJKLMNOPQRSTUVWXYZ.?1234567890!", 1);
	//start_time = SDL_GetTicks()*1000;
	score_font = App->fonts->Load("Assets/Images/Ui/Fonts/FontPScore.png", "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~'!@#$%^&*()-_+=[]{}| :;¨º<>,./?", 1);
	char_font = App->fonts->Load("Assets/Images/Ui/Fonts/CharName.png", "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789~·!@#$%^&*()-+=[]{}|:;ç'<>,./? ", 1);

	lifebar1_rect2 = { 2,2,149,13 };
	lifebar2_rect2 = { 2,2,149,13 };
	lifebar1_rect1 = { 0,18,153,17 };
	lifebar2_rect1 = { 0,18,153,17 };
	ko_white = { 34,37,26,22 };
	ko_red = { 1,36,27,24 };
	round_win = { 66,36,17,20 };

	pos_bar = 149;


	return true;
}

bool ModuleUi::CleanUp()
{
	LOG("Unloading Ui");

	App->textures->Unload(hud);
	App->fonts->UnLoad(timer_font);
	App->fonts->UnLoad(score_font);
	App->fonts->UnLoad(char_font);

	return true;
}

update_status ModuleUi::Update()
{
	//decresion of lifebar player 2
	lifebar2_rect2.w = 149 * App->player2->life / 100;

	//decresion of lifebar player 1
	lifebar1_rect2.w = 149 * App->player->life / 100;

	//blit the health bars
	//red ones
	App->render->Blit(hud, 27, 10, &lifebar1_rect1, NULL);
	App->render->Blit(hud, 23 + lifebar1_rect1.w + ko_red.w, 10 , &lifebar2_rect1, NULL);
	//orange ones
	App->render->Blit(hud, 178 - lifebar1_rect2.w, 12, &lifebar1_rect2, NULL);
	App->render->Blit(hud, 25 + lifebar1_rect1.w + ko_red.w , 12, &lifebar2_rect2, NULL);

	//blit the K.O
	App->render->Blit(hud, 178, 7, &ko_red, NULL);
	App->render->Blit(hud, 179, 8, &ko_white, NULL);
	   
	current_time = SDL_GetTicks();
	
	App->fonts->BlitText(2, 0, score_font, "1P");
	App->fonts->BlitText(150, 0, score_font, "HI");
	App->fonts->BlitText(280, 0, score_font, "2P");
	App->fonts->BlitText(30, 26, char_font, "E.HONDA");
	App->fonts->BlitText(270, 26, char_font, "E.HONDA");

	//timer_font = (current_time * 1000) - start_time;
	//App->fonts->BlitText(178, 15, timer_font, timer_numbers);

	if ((current_time - last_time) >= KO_TIMER)
	{
		last_time = current_time;
	}
	if ((App->player->life <= 25 || App->player2->life <= 25) && (current_time - last_time) < KO_TIMER / 4)
	{
		App->render->Blit(hud, 178, 7, &ko_red, NULL);
	}

	//round wins
	/*if (i == 1)App->render->Blit(hud, SCREEN_WIDTH - 17, 10, &round_win, NULL);
	if (j == 1)App->render->Blit(hud, 0, 10, &round_win, NULL);*/


	return UPDATE_CONTINUE;
}