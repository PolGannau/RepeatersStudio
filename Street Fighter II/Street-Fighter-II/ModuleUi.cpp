#include "ModuleUi.h"
#include "Application.h"
#include "ModuleRyuStage.h"
#include "ModuleStageHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"


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

	pos_bar = lifebar1_rect2.w = lifebar2_rect2.w = 149;


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
	//decresion of life
	aux1 = lifebar1_rect2.w;
	aux2 = lifebar2_rect2.w;
	lifebar1_rect2.w = 149 * App->player->life / 100;
	lifebar2_rect2.w = 149 * App->player2->life / 100;
	lifebar1_rect2.x = lifebar1_rect2.x + aux1 - lifebar1_rect2.w;
	lifebar2_rect2.x = lifebar2_rect2.x + aux2 - lifebar2_rect2.w;

	//blit the health bars
	App->render->Blit(hud, 27, 10, &lifebar1_rect1, NULL);
	App->render->Blit(hud, SCREEN_WIDTH - lifebar1_rect2.w - ko_red.w - lifebar1_rect2.w - 30, 12, &lifebar1_rect2, NULL);
	App->render->Blit(hud, SCREEN_WIDTH - lifebar2_rect1.w - 28, 10, &lifebar2_rect1, NULL);
	App->render->Blit(hud, SCREEN_WIDTH - pos_bar - 30, 12, &lifebar2_rect2, NULL);

	//blit the K.O
	App->render->Blit(hud, 178, 7, &ko_red, NULL);
	App->render->Blit(hud, 179, 8, &ko_white, NULL);

	if (App->input->keyboard[SDL_SCANCODE_F10] == KEY_DOWN)
	{
		lifebar1_rect2.w = 149;
		lifebar2_rect2.w = 149;
	}

	return UPDATE_CONTINUE;
}