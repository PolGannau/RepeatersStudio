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
	idle.PushBack({ 133, 649, 60, 89 });
	idle.PushBack({ 206, 739, 59, 90 });
	idle.PushBack({ 441, 830, 58, 92 });
	idle.PushBack({ 161, 923, 55, 93 });
	//idle.PushBack({ 366, 12, 60, 92 });
	idle.speed = 0.2f;

	// walk forward animation (arcade sprite sheet)
	forward.PushBack({ 568, 476, 53, 83 });
	forward.PushBack({ 776, 560, 60, 88 });
	forward.PushBack({ 722, 830, 64, 92 });
	forward.PushBack({ 593, 649, 63, 90 });
	forward.PushBack({ 0, 830, 54, 91 });
	forward.PushBack({ 368, 649, 50, 89 });
	forward.speed = 0.1f;

	// walk backwards animation
	backward.PushBack({ 311, 649, 57, 89 });
	backward.PushBack({ 388, 560, 61, 87 });
	backward.PushBack({ 534, 649, 59, 90 });
	backward.PushBack({ 0, 739, 57, 90 });
	backward.PushBack({ 710, 646, 58, 90 });
	backward.PushBack({ 905, 739, 58, 91 });
	backward.speed = 0.1f;

	// punch animation
	punch.PushBack({ 759, 739, 64, 91 });
	punch.PushBack({ 813, 739, 92, 91 });
	punch.speed = 0.1f;

	// kick animation
	kick.PushBack({ 375, 830, 66, 92 });
	kick.PushBack({ 617, 923, 114, 94 });
	kick.speed = 0.1f;

	// neutral jump animation
	njump.PushBack({ 746, 1114, 56, 104 });
	njump.PushBack({ 193, 649, 50, 89 });
	njump.PushBack({ 538, 319, 54, 77 });
	njump.PushBack({ 315, 243, 48, 70 });
	njump.PushBack({ 486, 649, 48, 89 });
	njump.PushBack({ 55, 1219, 55, 109 });
	njump.speed = 0.1f;

	//forward jump animation
	fjump.PushBack({ 55, 1219, 55, 109 });
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
	graphics = App->textures->Load("../Game/Assets/Images/Characters/ryuSprites.png");
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
	Animation* current_animation = &idle;

	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		current_animation = &forward;
		position.x += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == 1)
	{
		current_animation = &backward;
		position.x -= speed;
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	
}