#include "ModuleLose.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleRyuStage.h"
#include "ModuleSceneIntro.h"
#include "Globals.h"
#include "ModuleFadeToBlack.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleWin.h"


ModuleLose::ModuleLose()
{}

ModuleLose::~ModuleLose()
{}

bool ModuleLose::Start()
{
	LOG("Startin Lose Scene.......");
	
	loose_music = App->audio->LoadMusic("Assets/Audio/Soundtrack/14 Continue.ogg");
	App->audio->PlayMusic(loose_music);
	//disable the player and stage
	App->player2->Disable();
	App->player->Disable();
	App->ryu_stage->Disable();

	//load the images and create textures
	texture_loser = App->textures->Load("Assets/Images/Ui/losescreen.png");

	return true;
}

update_status ModuleLose::Update()
{
	if (update_status::UPDATE_ERROR)
		LOG("Could not update lose scene");
	
	App->render->Blit(texture_loser, 0, 0, NULL);

	//to exit the lose scene Space must be pressed
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
		App->fade->FadeToBlack(App->module_lose, App->scene_intro);
	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_DOWN)
		App->fade->FadeToBlack(App->module_lose, App->module_win);

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
