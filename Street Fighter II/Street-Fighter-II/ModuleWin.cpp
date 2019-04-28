#include "ModuleWin.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "Globals.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "ModuleSceneIntro.h"
#include "ModulePlayer2.h"
#include "ModuleRyuStage.h"
#include "ModuleInput.h"
#include "ModuleLose.h"
#include "ModuleAudio.h"

ModuleWin::ModuleWin()
{}

ModuleWin::~ModuleWin()
{}

bool ModuleWin::Start()
{
	LOG("loading Win Scene.........");
	
	music = App->audio->LoadMusic("Assets/Audio/Soundtrack/14 Continue.ogg");
	App->audio->PlayMusic(music);
	//Disable player and stage
	App->player->Disable();
	App->player2->Disable();
	App->ryu_stage->Disable();

	//We create a rect to put the winner texture in it.
	texture_winner = App->textures->Load("Assets/Images/Ui/winscreen.png");

	return true;
}

update_status ModuleWin::Update()
{
	if (update_status::UPDATE_ERROR)
	{
		LOG("Could not update Win Scene");
	}

	//blit the images of the fighters (winner and loser)
	App->render->Blit(texture_winner, 0, 0, NULL);


	//to exit the scene Space must be pressed
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
		App->fade->FadeToBlack(App->module_win, App->scene_intro);
	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_DOWN)
		App->fade->FadeToBlack(App->module_win, App->module_lose);



	return UPDATE_CONTINUE;
}

bool ModuleWin::CleanUp()
{
	LOG("Unloading ModuleWin...........");

	//to clean up the module disable all the images and sounds of it
	App->textures->Unload(texture_winner);
	App->textures->Unload(texture_loser);
	App->textures->Unload(texture_text);
	App->audio->UnloadMusic(music);


	return true;
}
