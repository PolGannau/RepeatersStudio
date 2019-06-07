#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleHonda.h"
#include "ModulePlayer.h"
//#include "ModuleFonts.h"
#include "ModuleAudio.h"

#include<stdio.h>

ModuleHonda::ModuleHonda()
{

}

ModuleHonda::~ModuleHonda()
{

}

bool ModuleHonda::Start()
{

}

bool ModuleHonda::CleanUp()
{
	return false;
}

update_status ModuleHonda::Update()
{
	return update_status();
}

void ModuleHonda::OnCollision(Collider * c1, Collider * c2)
{
}
