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

	lifebar1_rect2 = { 0,0,153,17 };
	lifebar2_rect2 = { 0,0,153,17 };
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

	ryu_stage_music = App->audio->LoadMusic("Assets/Audio/Soundtrack/05 Ryu.ogg");
	App->audio->PlayMusic(ryu_stage_music);

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


	return true;
}

// Update: draw background
update_status ModuleRyuStage::Update()
{
	App->render->Blit(background_texture, 0, 0, &background_rect, NULL);
	App->render->Blit(background_texture, 230, 60, &temple_mini, NULL);
	App->render->Blit(background_texture, 0, 0, &roof_brown, NULL);
	App->render->Blit(background_texture, 0, 0, &floor, NULL);
	App->render->Blit(background_texture, 50, 100, &sign, NULL);

	App->render->Blit(hud, 25, 10, &lifebar1_rect1, NULL);
	App->render->Blit(hud, 25, 10, &lifebar1_rect2, NULL);
	App->render->Blit(hud, SCREEN_WIDTH - lifebar2_rect1.w - 26, 10, &lifebar2_rect1, NULL);
	App->render->Blit(hud, SCREEN_WIDTH - lifebar2_rect2.w - 26, 10, &lifebar2_rect2, NULL);

	App->render->Blit(hud, 178, 7, &ko_red, NULL);
	App->render->Blit(hud, 179, 8, &ko_white, NULL);

	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_DOWN)
		App->fade->FadeToBlack(App->ryu_stage, App->module_lose);
	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_DOWN)
		App->fade->FadeToBlack(App->ryu_stage, App->module_win);


	return UPDATE_CONTINUE;
}