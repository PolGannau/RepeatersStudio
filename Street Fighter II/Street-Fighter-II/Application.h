#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 15

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleParticles;
class ModuleRyuStage;
class ModuleStageHonda;
class ModuleSceneIntro;
class ModuleFadeToBlack;
class ModulePlayersManager;
class ModuleCollision;
class ModuleEnemies;
class ModuleFonts;
class ModuleAudio;
class Module;
class ModuleWin;
class ModuleLose;
class ModuleUi;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleFonts* fonts;
	ModuleRyuStage* ryu_stage;
	ModuleStageHonda* honda_stage;
	ModuleSceneIntro* scene_intro;
	ModulePlayersManager* manager;
	ModuleCollision* collision;
	ModuleUi* module_ui;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleEnemies* enemies;
	ModuleAudio* audio;
	ModuleWin* module_win;
	ModuleLose* module_lose;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__
