#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleHonda.h"
#include "ModulePlayer.h"
//#include "ModuleFonts.h"
#include "ModuleAudio.h"

#include<stdio.h>

ModuleHonda::ModuleHonda(PLAYER_NUMBER num) { player_num = num; }

ModuleHonda::~ModuleHonda() {};

bool ModuleHonda::Start()
{
	coll_body = App->collision->AddCollider({ 50,50,50,50 }, COLLIDER_PLAYER_BODY, this);
	return true;
}

bool ModuleHonda::CleanUp()
{
	if (coll_body != nullptr)coll_body->to_delete = true;
	return true;
}

update_status ModuleHonda::Update()
{
	return update_status::UPDATE_CONTINUE;
}

void ModuleHonda::OnCollision(Collider * c1, Collider * c2)
{
}
