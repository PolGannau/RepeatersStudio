#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleRyuStage.h"
#include "ModuleAudio.h"


ModuleRyuStage::ModuleRyuStage()
{}

ModuleRyuStage::~ModuleRyuStage()
{}

// Load assets
bool ModuleRyuStage::Start()
{
	LOG("Loading Ryu Stage");

	background = App->textures->Load("Assets/Images/Stages/Stages.png");
	hud = App->textures->Load("Assets/Images/Ui/uiSprites-0.png");

	//lifebar1_rect = {};
	//lifebar2_rect = {};

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

	App->textures->Unload(background);
	App->collision->Disable();
	App->player->Disable();
	App->audio->UnloadMusic(ryu_stage_music);


	return true;
}

// Update: draw background
update_status ModuleRyuStage::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	return UPDATE_CONTINUE;
}