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
#include "ModuleAudio.h"


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

	stahe_honda_music = App->audio->LoadMusic("Assets/Audio/Soundtrack/06 E. Honda.ogg");
	App->audio->PlayMusic(stahe_honda_music);


	stage_texture = App->textures->Load("Assets/Images/Stages/honda/hondastage.png");
	light_texture = App->textures->Load("Assets/Images/Stages/Stages.png");

	floor = { 0,407,848,64 };
	wall = { 0,160,671,199 };
	roof = { 0,359,765,48 };
	pool_top = { 568,104,336,20 };
	pool_wall = { 568,128,336,32 };
	light = { 1980,1016,60,108 };
	mirrors = { 511,208,114,130 };
	floor_tape = { 686,407,82,16 };

	App->render->camera.x = 7;

	return true;
}

//unload assets in the CleanUp
bool ModuleStageHonda::CleanUp()
{
	LOG("Unloading Honda Stage");

	App->textures->Unload(stage_texture);
	App->textures->Unload(light_texture);
	App->audio->UnloadMusic(stahe_honda_music);

	return true;
}

//Blit all and update the stage
update_status ModuleStageHonda::Update()
{
	//input
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

	//Camera Limits
	if (App->player->position.x > App->render->limit.x + SCREEN_WIDTH - 220 && App->player2->position.x > App->render->limit.x + SCREEN_WIDTH - 220 && App->render->limit.x + App->render->limit.w < 700)
	{
		App->render->camera.x += 1;
		App->render->limit.x += 1;
	}
	if (App->player->position.x < App->render->limit.x + 220 && App->player2->position.x < App->render->limit.x + 220 && App->render->limit.x > 0)
	{
		App->render->camera.x -= 1;
		App->render->limit.x -= 1;
	}

	//blit the map
	App->render->Blit(stage_texture, -71, wall.h - 35, &floor);
	App->render->Blit(stage_texture, 0, -10, &wall);
	App->render->Blit(stage_texture, 680, 164, &floor_tape);
	App->render->Blit(stage_texture, 623, roof.h - 10 , &mirrors);
	App->render->Blit(stage_texture, 0, -10, &roof);
	if (App->player->life <= 50 || App->player2->life <= 50)
	{
		App->render->Blit(stage_texture, 190, roof.h - 2, &(sun.GetCurrentFrame()));
		App->render->Blit(stage_texture, 511 - boy.GetCurrentFrame().w, roof.h - 2, &(boy.GetCurrentFrame()));
	}
	App->render->Blit(stage_texture, 190, wall.h - 49, &pool_wall);
	App->render->Blit(stage_texture, 190, wall.h - 69, &pool_top);
	App->render->Blit(light_texture, 90, 0, &light);
	App->render->Blit(light_texture, 550, 0, &light);

	

	return UPDATE_CONTINUE;
}