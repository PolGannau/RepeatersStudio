#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleRyuStage.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "ModuleAudio.h"
#include "ModuleLose.h"
#include "ModuleWin.h"


ModuleSceneIntro::ModuleSceneIntro()
{}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro Scene");

	background = App->textures->Load("Assets/Images/Ui/title.png");
	App->player->Disable();
	App->player2->Disable();
	App->ryu_stage->Disable();
	App->module_lose->Disable();
	App->module_win->Disable();

	intro_mus = App->audio->LoadMusic("Assets/Audio/Soundtrack/02 The World Warrior.ogg");
	App->audio->PlayMusic(intro_mus);
	//App->render->camera.x = App->render->camera.y = 0;

	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro Scene");

	App->textures->Unload(background);
	App->audio->UnloadMusic(intro_mus);

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->ryu_stage);
		//App->audio->FadeMusic(600);
	}

	return UPDATE_CONTINUE;
}