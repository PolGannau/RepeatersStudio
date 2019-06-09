#include "ModuleWin.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "Globals.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "ModuleRyuStage.h"
#include "ModuleStageHonda.h"
#include "ModuleInput.h"
#include "ModuleLose.h"
#include "ModuleAudio.h"
#include "ModuleUi.h"
#include "ModuleFonts.h"
#include "ModulePlayersManager.h"

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
	App->honda_stage->Disable();
	App->manager->Disable();
	App->module_ui->Disable();

	//We create a rect to put the winner texture in it.
	//texture_winner = App->textures->Load("Assets/Images/Ui/winscreen.png");
	portraits = App->textures->Load("Assets/Images/Ui/characterselect-endscreen.png");
	win_font = App->fonts->Load("Assets/Images/Ui/Fonts/CharName.png", "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789~·!@#$%^&*()-+=[]{}|:;ç'<>,./? ", 1);
	portrait_loose = { 301, 225, 72, 96 };
	portrait_win = { 959, 386, 72, 96 };

	return true;
}

update_status ModuleWin::Update()
{
	if (update_status::UPDATE_ERROR)
	{
		LOG("Could not update Win Scene");
	}

	//blit the images of the fighters (winner and loser)
	//App->render->Blit(texture_winner, 0, 0, NULL);
	App->render->Blit(portraits, 50, 50, &portrait_loose, NULL);
	App->render->Blit(portraits, 260, 50, &portrait_win, NULL);

	App->fonts->BlitText(110, 10, win_font, "PLAYER 1 WINS!");
	App->fonts->BlitText(50, 170, win_font, "CAN'T YOU DO BETTER THAN");
	App->fonts->BlitText(50, 185, win_font, "THAT?");

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
	App->textures->Unload(portraits);


	return true;
}
