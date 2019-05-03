#include "ModuleStageHonda.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"


ModuleStageHonda::ModuleStageHonda()
{}

ModuleStageHonda::~ModuleStageHonda()
{}

//Load assets in the Start
bool ModuleStageHonda::Start()
{
	LOG("Loading Honda Stage");

	stage_texture = App->textures->Load("Assets/Images/Stages/honda/hondastage.png");

	floor = { 0,407,848,64 };
	wall = { 0,160,671,199 };
	roof = { 0,359,765,48 };
	pool_top = { 568,104,336,20 };
	pool_wall = { 568,128,336,32 };


	return true;
}

//unload assets in the CleanUp
bool ModuleStageHonda::CleanUp()
{
	LOG("Unloading Honda Stage");

	App->textures->Unload(stage_texture);

	return true;
}

//Blit all and update the stage
update_status ModuleStageHonda::Update()
{
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_DOWN)
		App->render->camera.x += 1;
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_DOWN)
		App->render->camera.x -= 1;


	App->render->Blit(stage_texture, 0, wall.h - 50, &floor);
	App->render->Blit(stage_texture, 0, 0, &wall);
	App->render->Blit(stage_texture, 0, 0, &roof);	


	return UPDATE_CONTINUE;
}