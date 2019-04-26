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

ModuleWin::ModuleWin()
{}

ModuleWin::~ModuleWin()
{}

bool ModuleWin::Start()
{
	LOG("loading Win Scene.........");
	
	//Disable player and stage
	App->player->Disable();
	App->ryu_stage->Disable();

	//We create a rect to put the winner texture in it.
	texture_winner = App->textures->Load("Assets/Images/Ui/Portraits/ryu.png");
	texture_loser = App->textures->Load("Assets/Images/Ui/Portraits/dmgryu.png");
	texture_text = App->textures->Load("Assets/Images/Ui/uiSprites-0.png");

	//text_rect={}

	return true;
}

update_status ModuleWin::Update()
{
	if (update_status::UPDATE_ERROR)
	{
		LOG("Could not update Win Scene");
	}

	//blit the images of the fighters (winner and loser)
	App->render->Blit(texture_winner, 50, 50, NULL);
	App->render->Blit(texture_loser, 100, 100, NULL);

	//App->render->Blit(texture_text, 50,200, texture_rect, NULL);


	//to exit the scene Space must be pressed
	if (SDL_SCANCODE_SPACE)
		App->fade->FadeToBlack(App->module_win, App->scene_intro);



	return UPDATE_CONTINUE;
}

bool ModuleWin::CleanUp()
{
	LOG("Unloading ModuleWin...........");

	//to clean up the module disable all the images and sounds of it
	App->textures->Unload(texture_winner);
	App->textures->Unload(texture_loser);
	App->textures->Unload(texture_text);


	return true;
}
