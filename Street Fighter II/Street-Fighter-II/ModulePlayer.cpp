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
	
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	/*graphics = App->textures->Load("rtype/ship.png");

	destroyed = false;
	position.x = 150;
	position.y = 120;
	score = 0;

	col = App->collision->AddCollider({ position.x, position.y, 32, 16 }, COLLIDER_PLAYER, this);


	font_score = App->fonts->Load("fonts/rtype_font.png", "! @,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz", 1);


	*/
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	/*App->textures->Unload(graphics);
	App->fonts->UnLoad(font_score);
	if (col)
		col->to_delete = true;
		*/
	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	
	
}