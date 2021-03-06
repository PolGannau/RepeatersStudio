#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleRyuStage.h"
#include "ModuleStageHonda.h"
#include "ModulePlayersManager.h"
#include "ModuleSceneIntro.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleWin.h"
#include "ModuleUi.h"
#include "ModuleLose.h"
//#include "ModuleParticles.h"
//#include "ModuleEnemies.h"
#include "ModuleFonts.h"
#include "ModuleTimer.h"


Application::Application()
{
	int i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = input = new ModuleInput();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = fonts = new ModuleFonts();
	modules[i++] = scene_intro = new ModuleSceneIntro();
	modules[i++] = ryu_stage = new ModuleRyuStage();
	modules[i++] = honda_stage = new ModuleStageHonda();
	//modules[i++] = enemies = new ModuleEnemies();
	//modules[i++] = particles = new ModuleParticles();
	modules[i++] = manager = new ModulePlayersManager();
	modules[i++] = collision = new ModuleCollision();
	modules[i++] = module_ui = new ModuleUi();
	modules[i++] = fade = new ModuleFadeToBlack();
	modules[i++] = audio = new ModuleAudio();
	modules[i++] = module_win = new ModuleWin();
	modules[i++] = module_lose = new ModuleLose();
	modules[i++] = timer = new ModuleTimer();
}

Application::~Application()
{
	for (int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Deactivate modules here ----
	//scene_space->Disable();
	//collision->Disable();
	//enemies->Disable();
	manager->Disable();
	// ----------------------------

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->IsEnabled() ? modules[i]->CleanUp() : true;

	return ret;
}