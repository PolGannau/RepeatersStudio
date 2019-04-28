#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleCollision.h"
#include "ModuleRyuStage.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleLose.h"
#include "ModuleWin.h"
#include "ModuleParticles.h"


ModuleRyuStage::ModuleRyuStage()
{}

ModuleRyuStage::~ModuleRyuStage()
{}

// Load assets
bool ModuleRyuStage::Start()
{
	LOG("Loading Ryu Stage");

	background_texture = App->textures->Load("Assets/Images/Stages/RyuStage.png");
	hud = App->textures->Load("Assets/Images/Ui/Lifebar_assets.png");

	lifebar1_rect2 = { 2,2,149,13 };
	lifebar2_rect2 = { 2,2,149,13 };
	lifebar1_rect1 = { 0,18,153,17 };
	lifebar2_rect1 = { 0,18,153,17 };
	ko_white = { 34,37,26,22 };
	ko_red = { 1,36,27,24 };

	background_rect = { 49,39,1405,192 };
	roof_brown = { 1477,10,504,212 };
	floor = { 44,298,622,237 };
	temple_mini = { 764,478,104,57 };
	sign = { 984,281,35,103 };

	App->player->Enable();
	App->player2->Enable();
	App->collision->Enable();

	pos_bar = 149;

	ryu_stage_music = App->audio->LoadMusic("Assets/Audio/Soundtrack/05 Ryu.ogg");
	App->audio->PlayMusic(ryu_stage_music);

	floor_collider = App->collision->AddCollider({ 0,218,622,10 }, COLLIDER_FLOOR, this);

	return true;
}

// UnLoad assets
bool ModuleRyuStage::CleanUp()
{
	LOG("Unloading Ryu Stage");

	App->textures->Unload(background_texture);
	App->collision->Disable();
	App->player->Disable();
	App->audio->UnloadMusic(ryu_stage_music);
	App->render->camera.x = 0;

	return true;
}

// Update: draw background
update_status ModuleRyuStage::Update()
{
	//camera
	if (App->player->position.x > App->render->limit.x + SCREEN_WIDTH - 100 && App->player2->position.x > App->render->limit.x + SCREEN_WIDTH - 100 && App->render->limit.x + App->render->limit.w < 475)
	{
		App->render->camera.x += 1;
		App->render->limit.x += 1;
	}
	if (App->player->position.x < App->render->limit.x + 100 && App->player2->position.x < App->render->limit.x + 100 && App->render->limit.x > 0)
	{
		App->render->camera.x -= 1;
		App->render->limit.x -= 1;
	}

	//decresion of life
	aux1 = lifebar1_rect2.w;
	aux2 = lifebar2_rect2.w;
	lifebar1_rect2.w = 149 * App->player->life / 100;
	lifebar2_rect2.w = 149 * App->player2->life / 100;
	lifebar1_rect2.x = lifebar1_rect2.x + aux1 - lifebar1_rect2.w;
	lifebar2_rect2.x = lifebar2_rect2.x + aux2 - lifebar2_rect2.w;
	
	//blit the stage itself
	App->render->Blit(background_texture, 0, 0, &background_rect, 0.5F);
	App->render->Blit(background_texture, 230, 60, &temple_mini, 1.2F);
	App->render->Blit(background_texture, 0, 0, &roof_brown, 1.3F);
	App->render->Blit(background_texture, 0, 0, &floor, 2.5F);
	App->render->Blit(background_texture, 50, 100, &sign, 2.5F);

	//blit the health bars
	App->render->Blit(hud, 27, 10, &lifebar1_rect1, NULL);
	App->render->Blit(hud, SCREEN_WIDTH - lifebar1_rect2.w - ko_red.w - lifebar1_rect2.w - 30, 12, &lifebar1_rect2, NULL);
	App->render->Blit(hud, SCREEN_WIDTH - lifebar2_rect1.w - 28, 10, &lifebar2_rect1, NULL);
	App->render->Blit(hud, SCREEN_WIDTH - pos_bar - 30 , 12, &lifebar2_rect2, NULL);

	//blit the K.O
	App->render->Blit(hud, 178, 7, &ko_red, NULL);
	App->render->Blit(hud, 179, 8, &ko_white, NULL);

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_DOWN)
		//App->fade->FadeToBlack(App->ryu_stage, App->module_lose);
		App->fade->FadeToBlack(this, (Module*)App->module_lose);
	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_DOWN)
		//App->fade->FadeToBlack(App->ryu_stage, App->module_win);
		App->fade->FadeToBlack(this, (Module*)App->module_win);
	if (App->input->keyboard[SDL_SCANCODE_F10] == KEY_DOWN)
	{
		lifebar1_rect2.w = 149;
		lifebar2_rect2.w = 149;
	}
	if (App->player->life <= 0)
		App->fade->FadeToBlack(this, App->module_lose);
	if (App->player2->life <= 0)
		App->fade->FadeToBlack(this, App->module_win);
	return UPDATE_CONTINUE;
}