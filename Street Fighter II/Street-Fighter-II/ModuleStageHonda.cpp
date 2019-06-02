#include "ModuleStageHonda.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleUi.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollision.h"
#include "ModuleWin.h"
#include "ModuleLose.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "Animation.h"


ModuleStageHonda::ModuleStageHonda()
{
	boy.PushBack({ 32,0,64,104 });
	boy.PushBack({ 97,0,95,104 });
	boy.speed = 0.01F;

	sun.PushBack({ 191,0,225,104 });
	sun.PushBack({ 415,0,223,104 });
	sun.speed = 0.2F;
}

ModuleStageHonda::~ModuleStageHonda()
{}

//Load assets in the Start
bool ModuleStageHonda::Start()
{
	LOG("Loading Honda Stage");

	App->player->Enable();
	App->player2->Enable();
	App->collision->Enable();


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
	if (App->input->keyboard[SDL_SCANCODE_M] == KEY_REPEAT)
		App->render->camera.x += 5;
	    App->render->limit.x += 5;
	if (App->input->keyboard[SDL_SCANCODE_N] == KEY_REPEAT)
		App->render->camera.x -= 5;
	App->render->limit.x -= 5;
	if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_DOWN)
		App->fade->FadeToBlack(this, App->module_win);
	if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_DOWN)
		App->fade->FadeToBlack(this, App->module_lose);

	App->render->Blit(stage_texture, 0, wall.h - 35, &floor);
	App->render->Blit(stage_texture, 0, -10, &wall);
	App->render->Blit(stage_texture, 0, -10, &roof);
	if (App->player->life <= 50 || App->player2->life <= 50)
	{
		App->render->Blit(stage_texture, 190, roof.h - 2, &(sun.GetCurrentFrame()));
		App->render->Blit(stage_texture, 511 - boy.GetCurrentFrame().w, roof.h - 2, &(boy.GetCurrentFrame()));
	}
	App->render->Blit(stage_texture, 190, wall.h - 49, &pool_wall);
	App->render->Blit(stage_texture, 190, wall.h - 69, &pool_top);

	

	return UPDATE_CONTINUE;
}