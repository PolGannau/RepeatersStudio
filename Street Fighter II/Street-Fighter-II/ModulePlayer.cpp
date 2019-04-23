#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
//#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
//#include "ModuleFonts.h"
#include "ModulePlayer.h"

#include<stdio.h>

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	// idle animation (arcade sprite sheet)
	idle.PushBack({ 68, 646, 60, 89 });
	idle.PushBack({ 118, 736, 59, 90 });
	idle.PushBack({ 424, 827, 58, 92 });
	idle.PushBack({ 147, 919, 55, 93 });
	//idle.PushBack({ 366, 12, 60, 92 });
	idle.speed = 0.1f;

	// walk forward animation (arcade sprite sheet)
	forward.PushBack({ 546, 474, 53, 83 });
	forward.PushBack({ 789, 558, 60, 88 });
	forward.PushBack({ 844, 827, 64, 92 });
	forward.PushBack({ 853, 646, 63, 90 });
	forward.PushBack({ 195, 827, 54, 91 });
	forward.PushBack({ 379, 646, 50, 89 });
	forward.speed = 0.1f;

	// walk backwards animation
	backward.PushBack({ 264, 646, 57, 89 });
	backward.PushBack({ 467, 558, 61, 87 });
	backward.PushBack({ 640, 646, 59, 90 });
	backward.PushBack({ 0, 736, 57, 90 });
	backward.PushBack({ 395, 736, 58, 90 });
	backward.PushBack({ 0, 827, 58, 91 });
	backward.speed = 0.1f;

	// punch animation
	punch.PushBack({ 131, 827, 64, 91 });
	punch.PushBack({ 861, 736, 92, 91 });
	punch.speed = 0.2f;

	// kick animation
	kick.PushBack({ 358, 827, 66, 92 });
	kick.PushBack({ 747, 919, 114, 94 });
	kick.speed = 0.2f;

	// neutral jump animation
	njump.PushBack({ 844, 1108, 56, 104 });
	njump.PushBack({ 542, 646, 50, 89 });
	njump.PushBack({ 827, 319, 54, 77 });
	njump.PushBack({ 315, 243, 48, 70 });
	njump.PushBack({ 592, 646, 48, 89 });
	njump.PushBack({ 252, 1212, 55, 109 });
	njump.speed = 0.1f;

	//forward jump animation
	fjump.PushBack({ 252, 1212, 55, 109 });
	fjump.PushBack({ 814, 396, 61, 78 });
	fjump.PushBack({ 387, 0, 104, 42 });
	fjump.PushBack({ 130, 476, 53, 82 });
	fjump.PushBack({ 610, 0, 122, 44 });
	fjump.PushBack({ 511, 560, 71, 87 });
	fjump.PushBack({ 622, 1114, 55, 103 });
	fjump.speed = 0.1f;

	//backwards jump animation
	bjump.PushBack({ 622, 1114, 55, 103 });
	bjump.PushBack({ 55, 1219, 55, 109 });
	bjump.PushBack({ 814, 396, 61, 78 });
	bjump.PushBack({ 387, 0, 104, 42 });
	bjump.PushBack({ 130, 476, 53, 82 });
	bjump.PushBack({ 610, 0, 122, 44 });
	bjump.PushBack({ 511, 560, 71, 87 });
	bjump.speed = 0.1f;

	//shoryuken animation
	/*shoryuken.PushBack({ 511, 560, 71, 87 });
	shoryuken.PushBack({ 511, 560, 71, 87 });
	shoryuken.PushBack({ 511, 560, 71, 87 });
	shoryuken.PushBack({ 511, 560, 71, 87 });
	shoryuken.PushBack({ 511, 560, 71, 87 });
	shoryuken.PushBack({ 511, 560, 71, 87 });
	shoryuken.speed = 0.1f;*/


}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("../Game/Assets/Images/Characters/RyuSprite.png");
	return ret;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	
	if (Bpunch) 
	{
		current_animation = &punch;
		if (current_animation->Finished()) {
			current_animation->Reset();
			Bpunch = false;
		}
	}
	else if (Bkick)
	{
		current_animation = &kick;
		if (current_animation->Finished()) {
			current_animation->Reset();
			Bkick = false;
		}
	}
	else current_animation = &idle;
	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT)
	{
		current_animation = &forward;
		position.x += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT)
	{
		current_animation = &backward;
		position.x -= speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_W] == 1)
	{
		current_animation = &njump;
		position.y -= speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_E] == 1)
	{
		Bpunch = true;
	}
	if (App->input->keyboard[SDL_SCANCODE_Q] == 1)
	{
		Bkick = true;
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	
}