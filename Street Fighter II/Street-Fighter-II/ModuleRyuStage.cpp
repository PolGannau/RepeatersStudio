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
#include "ModuleUi.h"


ModuleRyuStage::ModuleRyuStage()
{}

ModuleRyuStage::~ModuleRyuStage()
{}

// Load assets
bool ModuleRyuStage::Start()
{
	LOG("Loading Ryu Stage");

	background_texture = App->textures->Load("Assets/Images/Stages/RyuStage.png");
	

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

	
	
	//blit the stage itself
	App->render->Blit(background_texture, 0, 0, &background_rect, 0.5F);
	App->render->Blit(background_texture, 230, 60, &temple_mini, 1.2F);
	App->render->Blit(background_texture, 0, 0, &roof_brown, 1.3F);
	App->render->Blit(background_texture, 0, 0, &floor, 2.5F);
	App->render->Blit(background_texture, 50, 100, &sign, 2.5F);
	return UPDATE_CONTINUE;
}