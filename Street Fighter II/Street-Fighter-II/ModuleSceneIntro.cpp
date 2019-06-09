#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleRyuStage.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "ModuleAudio.h"
#include "ModuleLose.h"
#include "ModuleWin.h"
#include "ModuleStageHonda.h"
#include "ModuleUi.h"
#include "ModuleFonts.h"


ModuleSceneIntro::ModuleSceneIntro()
{
	intro.PushBack({ 0,0,384,224 });
	intro.PushBack({ 385,0,384,224 });
	intro.PushBack({ 770,0,384,224 });
	intro.PushBack({ 1155,0,384,224 });
	intro.PushBack({ 1540,0,384,224 });
	intro.PushBack({ 0,225,384,224 });
	intro.PushBack({ 385,225,384,224 });
	intro.PushBack({ 770,225,384,224 });
	intro.PushBack({ 1155,225,384,224 });
	intro.PushBack({ 1540,225,384,224 });
	intro.PushBack({ 0,450,384,224 });
	intro.PushBack({ 385,450,384,224 });
	intro.PushBack({ 770,450,384,224 });
	intro.PushBack({ 1155,450,384,224 });
	intro.PushBack({ 1540,450,384,224 });
	intro.PushBack({ 0,675,384,224 });
	intro.PushBack({ 385,675,384,224 });
	intro.PushBack({ 770,675,384,224 });
	intro.PushBack({ 1155,675,384,224 });
	intro.PushBack({ 1540,675,384,224 });
	intro.PushBack({ 0,900,384,224 });
	intro.PushBack({ 385,900,384,224 });
	intro.PushBack({ 770,900,384,224 });
	intro.PushBack({ 1155,900,384,224 });
	intro.PushBack({ 1540,900,384,224 });
	intro.PushBack({ 0,1125,384,224 });
	intro.PushBack({ 385,1125,384,224 });
	intro.PushBack({ 770,1125,384,224 });
	intro.PushBack({ 1155,1125,384,224 });
	intro.PushBack({ 1540,1125,384,224 });
	intro.PushBack({ 0,1350,384,224 });
	intro.PushBack({ 385,1350,384,224 });
	intro.PushBack({ 770,1350,384,224 });
	intro.PushBack({ 1155,1350,384,224 });
	intro.PushBack({ 1540,1350,384,224 });
	intro.PushBack({ 0,1575,384,224 });
	intro.PushBack({ 385,1575,384,224 });
	intro.PushBack({ 770,1575,384,224 });
	intro.PushBack({ 1155,1575,384,224 });
	intro.PushBack({ 1540,1575,384,224 });
	intro.PushBack({ 0,1800,384,224 });
	intro.PushBack({ 385,1800,384,224 });
	intro.PushBack({ 770,1800,384,224 });
	intro.PushBack({ 1155,1800,384,224 });
	intro.PushBack({ 1540,1800,384,224 });
	intro.PushBack({ 0,2025,384,224 });
	intro.PushBack({ 385,2025,384,224 });
	intro.PushBack({ 770,2025,384,224 });
	intro.PushBack({ 1155,2025,384,224 });
	intro.PushBack({ 1540,2025,384,224 });
	intro.PushBack({ 0,2250,384,224 });
	intro.PushBack({ 385,2250,384,224 });
	intro.PushBack({ 770,2250,384,224 });
	intro.PushBack({ 1155,2250,384,224 });
	intro.PushBack({ 1540,2250,384,224 });
	intro.PushBack({ 0,2475,384,224 });
	intro.PushBack({ 385,2475,384,224 });
	intro.PushBack({ 770,2475,384,224 });
	intro.PushBack({ 1155,2475,384,224 });
	intro.PushBack({ 1540,2475,384,224 });
	intro.PushBack({ 0,2700,384,224 });
	intro.PushBack({ 385,2700,384,224 });
	intro.PushBack({ 770,2700,384,224 });
	intro.PushBack({ 1155,2700,384,224 });
	intro.PushBack({ 1540,2700,384,224 });
	intro.PushBack({ 0,2925,384,224 });
	intro.PushBack({ 385,2925,384,224 });
	intro.PushBack({ 770,2925,384,224 });
	intro.PushBack({ 1155,2925,384,224 });
	intro.PushBack({ 1540,2925,384,224 });
	intro.PushBack({ 0,3150,384,224 });
	intro.PushBack({ 385,3150,384,224 });
	intro.PushBack({ 770,3150,384,224 });
	intro.PushBack({ 1155,3150,384,224 });
	intro.PushBack({ 1540,3150,384,224 });
	intro.PushBack({ 0,3375,384,224 });
	intro.PushBack({ 385,3375,384,224 });
	intro.PushBack({ 770,3375,384,224 });
	intro.PushBack({ 1155,3375,384,224 });
	intro.PushBack({ 1540,3375,384,224 });
	intro.PushBack({ 0,3600,384,224 });
	intro.PushBack({ 385,3600,384,224 });
	intro.PushBack({ 770,3600,384,224 });
	intro.PushBack({ 1155,3600,384,224 });
	intro.PushBack({ 1540,3600,384,224 });
	intro.PushBack({ 0,3825,384,224 });
	intro.PushBack({ 385,3825,384,224 });
	intro.PushBack({ 770,3825,384,224 });
	intro.PushBack({ 1155,3825,384,224 });
	intro.PushBack({ 1540,3825,384,224 });
	intro.PushBack({ 0,4050,384,224 });
	intro.speed = 1.0f;
	intro.loop = false;
	
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro Scene");

	intro_image = App->textures->Load("Assets/Images/IntroAnimation/introscreen.png");
	App->ryu_stage->Disable();
	App->module_lose->Disable();
	App->module_win->Disable();
	App->module_ui->Disable();
	App->honda_stage->Disable();

	intro_mus = App->audio->LoadMusic("Assets/Audio/Soundtrack/02 The World Warrior.ogg");
	App->audio->PlayMusic(intro_mus);
	//App->render->camera.x = App->render->camera.y = 0;
	capcom_font = App->fonts->Load("Assets/Images/Ui/Fonts/FontCapcom.png", "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~'!@©$%^&*()-_+=[]{}| :;¨º<>,./?", 1);
	repeaters_font = App->fonts->Load("Assets/Images/Ui/Fonts/Font_sys.png", "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789Ý&!¨#$%()*+,-./:;<=>?@[]^ '{}~abcdefghijklmnopqrstuvwxyz", 1);
	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro Scene");

	App->textures->Unload(intro_image);
	App->audio->UnloadMusic(intro_mus);
	App->module_ui->Enable();

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->render->Blit(intro_image, 0, 0, &intro.GetCurrentFrame(),1,false);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->honda_stage);
		//App->audio->FadeMusic(600);
	}
	
	App->fonts->BlitText(130, 200, capcom_font, "©CAPCOM CO..LTD.");
	App->fonts->BlitText(37, 210, repeaters_font, "Fbonbef'Pspkfdu'Bz'Tif'Rfqfbufst'Suvejp");
	if (App->input->keyboard[SDL_SCANCODE_F9] == KEY_DOWN && App->fade->IsFading() == false)
		App->fade->FadeToBlack(this, App->ryu_stage);

	return UPDATE_CONTINUE;
}

//Fanmade Project By The Repeaters Studio