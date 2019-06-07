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

ModuleHonda::ModuleHonda(PLAYER_NUMBER num)
{
}

ModuleHonda::~ModuleHonda() {};

bool ModuleHonda::Start()
{
	return true;
}

bool ModuleHonda::CleanUp()
{
	return true;
}

update_status ModuleHonda::Update()
{
	return update_status::UPDATE_CONTINUE;
}

void ModuleHonda::OnCollision(Collider * c1, Collider * c2)
{
}
