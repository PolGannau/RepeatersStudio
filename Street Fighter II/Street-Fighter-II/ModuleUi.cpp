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
#include "../SDL/include/SDL_timer.h"


ModuleUi::ModuleUi()
{}

ModuleUi::~ModuleUi()
{}

bool ModuleUi::Start()
{
	LOG("Loading Ui");
	hud = App->textures->Load("Assets/Images/Ui/Lifebar_assets.png");

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
	if ((current_time - last_time) >= KO_TIMER)
	{
		last_time = current_time;
	}
	if ((App->player->life <= 25 || App->player2->life <= 25) && (current_time - last_time) < KO_TIMER / 2)
	{
		App->render->Blit(hud, 178, 7, &ko_red, NULL);
	}

	//round wins
	if (App->player->life <= 0)
	{
		i = i + 1;
		App->render->Blit(hud, SCREEN_WIDTH-17, 10, &round_win, NULL);
	}
	if (App->player2->life <= 0)
	{
		j = j + 1;
		App->render->Blit(hud, 0, 10, &round_win, NULL);
	}
	if (i == 2)
	{
		App->fade->FadeToBlack(App->honda_stage, App->module_lose);
	}
	if (j == 2)
	{
		App->fade->FadeToBlack(App->honda_stage, App->module_win);
	}
			
	return UPDATE_CONTINUE;
}