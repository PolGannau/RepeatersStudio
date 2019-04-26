#include "ModuleLose.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleRyuStage.h"
#include "ModuleSceneEnd.h"
#include "Globals.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"


ModuleLose::ModuleLose()
{}

ModuleLose::~ModuleLose()
{}

bool ModuleLose::Start()
{
	//disable the player and stage
	App->player->Disable();
	App->ryu_stage->Disable();

	//load the images
	texture_loser=App->textures->Load("Game/")


	return true;
}

update_status ModuleLose::Update()
{
	return update_status();
}

bool ModuleLose::CleanUp()
{
	return false;
}
