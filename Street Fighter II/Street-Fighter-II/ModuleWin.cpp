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
	texture = App->textures->Load("Assets/Images/Ui/UiSprites-1.png");
	winner_rect = { 265, 1157, 265, 354 };
	

	return false;
}

update_status ModuleWin::Update()
{
	if (update_status::UPDATE_ERROR)
		LOG("Could not update Win Scene");

	App->render->Blit(texture, 128, 56, winner_rect, 1.0F, true);
	return update_status();
}

bool ModuleWin::CleanUp()
{
	return false;
}
