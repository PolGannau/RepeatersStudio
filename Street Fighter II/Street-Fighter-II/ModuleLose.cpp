#include "ModuleLose.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleRyuStage.h"
#include "ModuleSceneEnd.h"
#include "ModuleSceneIntro.h"
#include "Globals.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"


ModuleLose::ModuleLose()
{}

ModuleLose::~ModuleLose()
{}

bool ModuleLose::Start()
{
	LOG("Startin Lose Scene.......");
	
	loose_music = App->audio->LoadMusic("Assets/Audio/Soundtrack/14 Continue.ogg");

	//disable the player and stage
	App->player->Disable();
	App->ryu_stage->Disable();

	//load the images and create textures
	texture_loser = App->textures->Load("Assets/Images/Ui/Portraits/dmgryu.png");
	texture_winner = App->textures->Load("Assets/Images/Ui/Portraits/ryu.png");
	texture_text = App->textures->Load("Assets/Images/Ui/uiSprites-0.png");

	text_rect = { 818,597,631,103 };

	return true;
}

update_status ModuleLose::Update()
{
	if (update_status::UPDATE_ERROR)
		LOG("Could not update lose scene");
	App->audio->PlayMusic(loose_music);
	App->render->Blit(texture_loser, 50, 50, NULL);
	App->render->Blit(texture_winner, 100, 100, NULL);
	App->render->Blit(texture_text, 50, 150, text_rect, NULL);

	//to exit the lose scene Space must be pressed
	if (SDL_SCANCODE_SPACE)
		App->fade->FadeToBlack(App->module_lose, App->scene_intro);

	return UPDATE_CONTINUE;
}

bool ModuleLose::CleanUp()
{
	//to clean up the module we must disable and unload all
	App->textures->Unload(texture_loser);
	App->textures->Unload(texture_winner);
	App->textures->Unload(texture_text);
	App->audio->UnloadMusic(loose_music);
	return true;
}
