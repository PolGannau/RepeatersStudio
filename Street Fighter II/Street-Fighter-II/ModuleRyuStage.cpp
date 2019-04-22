#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleRyuStage.h"
//#include "ModuleParticles.h"

ModuleRyuStage::ModuleRyuStage()
{}

ModuleRyuStage::~ModuleRyuStage()
{}

// Load assets
bool ModuleRyuStage::Start()
{
	LOG("Loading space scene");

	background = App->textures->Load("Assets/Images/Ui/capcom logo.png");
	//hud = App->textures->Load("rtype/hud.png");

	App->player->Enable();
	//App->particles->Enable();
	App->collision->Enable();
	//App->enemies->Enable();

	// Colliders ---
	/*App->collision->AddCollider({ 0, 224, 3930, 16 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1375, 0, 111, 96 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1375, 145, 111, 96 }, COLLIDER_WALL);
	*/

	return true;
}

// UnLoad assets
bool ModuleRyuStage::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);

	
	App->collision->Disable();
	//App->particles->Disable();
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleRyuStage::Update()
{
	App->render->Blit(background, 0, 0, NULL);
	//App->render->Blit(hud, 0, 240, NULL, 0.0f, false);

	return UPDATE_CONTINUE;
}