#include "ModuleWin.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "Globals.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"

ModuleWin::ModuleWin()
{}

ModuleWin::~ModuleWin()
{}

bool ModuleWin::Start()
{
	LOG("loading Win Scene");
	//We create a rect to put the winner texture in it.
	texture_winner = App->textures->Load("Assets/Images/Ui/Portraits/ryu.png");
	texture_loser = App->textures->Load("Assets/Images/Ui/Portraits/dmgryu.png";)

	return false;
}

update_status ModuleWin::Update()
{
	if (update_status::UPDATE_ERROR)
		LOG("Could not update Win Scene");

	App->render->Blit(texture_winner, 50, 50, NULL);
	return update_status();
}

bool ModuleWin::CleanUp()
{
	return false;
}
