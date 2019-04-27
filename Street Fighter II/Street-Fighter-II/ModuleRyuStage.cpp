#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
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
	hud = App->textures->Load("Assets/Images/Ui/uiSprites-0.png");

	//lifebar1_rect2 = {0,164,331,39}
	//lifebar2_rect2 = {0,164,331,39}
	//lifebar1_rect1={948,125,331,39}
	//lifebar2_rect2={948,125,331,39}

	background_rect = { 44,29,1405,192 };
	roof_brown = { 1477,10,504,212 };
	floor = { 42,298,622,237 };

	App->player->Enable();
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
	App->render->Blit(background_texture, 0, 0, &roof_brown, NULL);
	App->render->Blit(background_texture, 0, 0, &floor, NULL);


	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_DOWN)
		App->fade->FadeToBlack(App->ryu_stage, App->module_lose);
	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_DOWN)
		App->fade->FadeToBlack(App->ryu_stage, App->module_win);


	return UPDATE_CONTINUE;
}