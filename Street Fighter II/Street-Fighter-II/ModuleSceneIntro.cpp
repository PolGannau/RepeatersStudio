#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleRyuStage.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"


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
	App->ryu_stage->Disable();
	//App->render->camera.x = App->render->camera.y = 0;

	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro Scene");

	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->render->Blit(background, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->ryu_stage);
	
	}

	return UPDATE_CONTINUE;
}