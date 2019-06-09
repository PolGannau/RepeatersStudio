#include "ModulePlayersManager.h"
#include "ModuleHonda.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "../SDL_Mixer/include/SDL_mixer.h"

ModulePlayersManager::ModulePlayersManager()
{}

ModulePlayersManager::~ModulePlayersManager()
{}

bool ModulePlayersManager::Start()
{
	graphics = App->textures->Load("../Game/Assets/Images/Characters/hondaSprite.png");
	graphics2 = App->textures->Load("../Game/Assets/Images/Characters/hondaSprite2.png");

	nonhit_sfx = App->audio->LoadEffect("Assets/Audio/Voice&SFX/GeneralAttacks/unhit_fist.wav");
	lightpunch_sfx = App->audio->LoadEffect("Assets/Audio/Voice&SFX/GeneralAttacks/Hit short.wav");
	mediumpunch_sfx = App->audio->LoadEffect("Assets/Audio/Voice&SFX/GeneralAttacks/Mid Punch.wav");
	heavypunch_sfx = App->audio->LoadEffect("Assets/Audio/Voice&SFX/GeneralAttacks/Hard Punch.wav");
	lightkick_sfx = App->audio->LoadEffect("Assets/Audio/Voice&SFX/GeneralAttacks/Kick.wav");
	mediumkick_sfx = App->audio->LoadEffect("Assets/Audio/Voice&SFX/GeneralAttacks/Mid kick.wav");
	heavykick_sfx = App->audio->LoadEffect("Assets/Audio/Voice&SFX/GeneralAttacks/Hard kick.wav");
	special_sfx = App->audio->LoadEffect("Assets/Audio/Voice&SFX/GeneralAttacks/Hard Hit.wav");
	block_sfx = App->audio->LoadEffect("Assets/Audio/Voice&SFX/GeneralAttacks/Blocked Punch.wav");
	laugh_sfx = App->audio->LoadEffect("Assets/Audio/Voice&SFX/Honda/Laugh.wav");
	
	player = CreatePlayer(PLAYER_NUMBER::NUMBER_ONE);
	player2 = CreatePlayer(PLAYER_NUMBER::NUMBER_TWO);
	player->vspeed = 0;
	player2->vspeed = 0;
	player->position.x = 100;
	player2->position.x = 300;

	return true;
}

bool ModulePlayersManager::CleanUp()
{
	if (player != nullptr)
	{
		LOG("Unloading Player...");
		player->Disable();
	}
	if (player2 != nullptr)
	{
		LOG("Unloading Player2...");
		player2->Disable();
	}
	player = player2 = nullptr;
	LOG("Unloading Character Spritesheet...");
	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);

	App->audio->UnloadSoundEffects(nonhit_sfx);
	App->audio->UnloadSoundEffects(lightpunch_sfx);
	App->audio->UnloadSoundEffects(mediumpunch_sfx);
	App->audio->UnloadSoundEffects(heavypunch_sfx);
	App->audio->UnloadSoundEffects(lightkick_sfx);
	App->audio->UnloadSoundEffects(mediumkick_sfx);
	App->audio->UnloadSoundEffects(heavykick_sfx);
	App->audio->UnloadSoundEffects(special_sfx);
	App->audio->UnloadSoundEffects(block_sfx);
	App->audio->UnloadSoundEffects(laugh_sfx);

	return true;
}

ModuleHonda* ModulePlayersManager::CreatePlayer(PLAYER_NUMBER num)
{
	ModuleHonda* user = new ModuleHonda(num);
	if (user != nullptr)
	{
		user->Start();
		return user;
	}
	if (num == PLAYER_NUMBER::NUMBER_ONE)LOG("Error Loading Player 1...");
	if (num == PLAYER_NUMBER::NUMBER_TWO)LOG("Error Loading Player 2...");
	player->hp = 90;
	update_status::UPDATE_ERROR;
}

update_status ModulePlayersManager::Update()
{

	/// PLAYER INPUT CONTROL AND LOGIC ---------------------------------------------------
	//JUMP
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_DOWN && player->state == ON_FLOOR || 
		App->input->Controller1[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_DOWN && player->state == ON_FLOOR)
	{
		player->state = JUMPING;
		player->vspeed += player->VerticalSpeed;
	}
	else if (SDL_GameControllerGetAxis(App->input->controller[0].controller, SDL_CONTROLLER_AXIS_LEFTY)<-32600 && player->state == ON_FLOOR)
	{
		player->state = JUMPING;
		player->vspeed += player->VerticalSpeed;
	}
	//BACKWARD
	else if (App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT || 
		SDL_GameControllerGetAxis(App->input->controller[0].controller, SDL_CONTROLLER_AXIS_LEFTX)<-10000 ||
		App->input->Controller1[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		player->movement = MOVEMENT_CHARACTER::BACKWARD;
	}
	//FORWARD
	else if (App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT || 
		SDL_GameControllerGetAxis(App->input->controller[0].controller, SDL_CONTROLLER_AXIS_LEFTX)>10000 ||
		App->input->Controller1[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		player->movement = MOVEMENT_CHARACTER::FORWARD;
	}
	//CROUCH
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_REPEAT && player->state == ON_FLOOR ||
		SDL_GameControllerGetAxis(App->input->controller[0].controller, SDL_CONTROLLER_AXIS_LEFTY) > 10000 && player->state == ON_FLOOR ||
		App->input->Controller1[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_REPEAT && player->state == ON_FLOOR)
	
		player->state = STATE_CHARACTER::STANDING_TO_CROUCHING;
	
	else if (App->input->keyboard[SDL_SCANCODE_S] == KEY_UP && player->state == CROUCHING ||
		SDL_GameControllerGetAxis(App->input->controller[0].controller, SDL_CONTROLLER_AXIS_LEFTY) < 10000 && player->state == CROUCHING ||
		App->input->Controller1[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_UP && player->state == CROUCHING)
	
		player->state = STATE_CHARACTER::CROUCHING_TO_STANDING;
	
	//LIGHT KICK
	if (App->input->keyboard[SDL_SCANCODE_F] == KEY_DOWN && player->action == NO_ACTION || 
		App->input->Controller1[SDL_CONTROLLER_BUTTON_A] == KEY_STATE::KEY_DOWN)
	{
		player->action = LIGHT_KICK;
		App->audio->PlaySoundEffect(nonhit_sfx);
	}
	//MEDIUM KICK
	if (App->input->keyboard[SDL_SCANCODE_G] == KEY_DOWN && player->action == NO_ACTION ||
		App->input->Controller1[SDL_CONTROLLER_BUTTON_B] == KEY_STATE::KEY_DOWN)
	{
		player->action = MEDIUM_KICK;
		App->audio->PlaySoundEffect(nonhit_sfx);
	}
	//HEAVY KICK
	if (App->input->keyboard[SDL_SCANCODE_H] == KEY_DOWN && player->action == NO_ACTION ||
		App->input->Controller1[SDL_CONTROLLER_BUTTON_RIGHTSHOULDER] == KEY_STATE::KEY_DOWN)
	{
		player->action = HEAVY_KICK;
		App->audio->PlaySoundEffect(nonhit_sfx);
	}
	//LIGHT PUNCH
	if (App->input->keyboard[SDL_SCANCODE_C] == KEY_DOWN && player->action == NO_ACTION ||
		App->input->Controller1[SDL_CONTROLLER_BUTTON_X] == KEY_STATE::KEY_DOWN)
	{
		player->action = LIGHT_PUNCH;
		App->audio->PlaySoundEffect(nonhit_sfx);
	}
	//MEDIUM PUNCH
	if (App->input->keyboard[SDL_SCANCODE_V] == KEY_DOWN && player->action == NO_ACTION ||
		App->input->Controller1[SDL_CONTROLLER_BUTTON_Y] == KEY_STATE::KEY_DOWN)
	{
		player->action = MEDIUM_PUNCH;
		App->audio->PlaySoundEffect(nonhit_sfx);
	}
	//HEAVY PUNCH
	if (App->input->keyboard[SDL_SCANCODE_B] == KEY_DOWN && player->action == NO_ACTION ||
		App->input->Controller1[SDL_CONTROLLER_BUTTON_LEFTSHOULDER] == KEY_STATE::KEY_DOWN)
	{
		player->action = HEAVY_PUNCH;
		App->audio->PlaySoundEffect(nonhit_sfx);
	}

	/// PLAYER 2 INPUT CONTROL AND LOGIC -------------------------------------------------
	//JUMP
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_DOWN && player2->state == ON_FLOOR ||
		App->input->Controller2[SDL_CONTROLLER_BUTTON_DPAD_UP] == KEY_STATE::KEY_DOWN && player2->state == ON_FLOOR)
	{
		player2->state = JUMPING;
		player2->vspeed += player2->VerticalSpeed;
	}
	else if (SDL_GameControllerGetAxis(App->input->controller[1].controller, SDL_CONTROLLER_AXIS_LEFTY)<-32600 && player2->state == ON_FLOOR)
	{
		player2->state = JUMPING;
		player2->vspeed += player2->VerticalSpeed;
	}
	//BACKWARD
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_REPEAT ||
		SDL_GameControllerGetAxis(App->input->controller[1].controller, SDL_CONTROLLER_AXIS_LEFTX)<-10000 ||
		App->input->Controller2[SDL_CONTROLLER_BUTTON_DPAD_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		player2->movement = MOVEMENT_CHARACTER::BACKWARD;
	}
	//FORWARD
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_REPEAT ||
		SDL_GameControllerGetAxis(App->input->controller[1].controller, SDL_CONTROLLER_AXIS_LEFTX)>10000 ||
		App->input->Controller2[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		player2->movement = MOVEMENT_CHARACTER::FORWARD;
	}
	//CROUCH
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_REPEAT && player2->state == ON_FLOOR ||
		SDL_GameControllerGetAxis(App->input->controller[1].controller, SDL_CONTROLLER_AXIS_LEFTY) > 10000 && player2->state == ON_FLOOR ||
		App->input->Controller2[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_REPEAT && player2->state == ON_FLOOR)
	{
		player2->state = STATE_CHARACTER::STANDING_TO_CROUCHING;
	}
	else if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_UP && player2->state == CROUCHING ||
		SDL_GameControllerGetAxis(App->input->controller[1].controller, SDL_CONTROLLER_AXIS_LEFTY) < 10000 && player2->state == CROUCHING ||
		App->input->Controller2[SDL_CONTROLLER_BUTTON_DPAD_DOWN] == KEY_STATE::KEY_UP && player2->state == CROUCHING)
	{
		player2->state = STATE_CHARACTER::CROUCHING_TO_STANDING;
	}
	//LIGHT KICK
	if (App->input->keyboard[SDL_SCANCODE_KP_7] == KEY_DOWN && player2->action == NO_ACTION ||
		App->input->Controller2[SDL_CONTROLLER_BUTTON_A] == KEY_STATE::KEY_DOWN)
	{
		player2->action = LIGHT_KICK;
		App->audio->PlaySoundEffect(nonhit_sfx);
	}
	//MEDIUM KICK
	if (App->input->keyboard[SDL_SCANCODE_KP_8] == KEY_DOWN && player2->action == NO_ACTION ||
		App->input->Controller2[SDL_CONTROLLER_BUTTON_B] == KEY_STATE::KEY_DOWN)
	{
		player2->action = MEDIUM_KICK;
		App->audio->PlaySoundEffect(nonhit_sfx);
	}
	//HEAVY KICK
	if (App->input->keyboard[SDL_SCANCODE_KP_9] == KEY_DOWN && player2->action == NO_ACTION ||
		App->input->Controller2[SDL_CONTROLLER_BUTTON_RIGHTSHOULDER] == KEY_STATE::KEY_DOWN)
	{
		player2->action = HEAVY_KICK;
		App->audio->PlaySoundEffect(nonhit_sfx);
	}
	//LIGHT PUNCH
	if (App->input->keyboard[SDL_SCANCODE_KP_4] == KEY_DOWN && player2->action == NO_ACTION ||
		App->input->Controller2[SDL_CONTROLLER_BUTTON_X] == KEY_STATE::KEY_DOWN)
	{
		player2->action = LIGHT_PUNCH;
		App->audio->PlaySoundEffect(nonhit_sfx);
	}
	//MEDIUM PUNCH
	if (App->input->keyboard[SDL_SCANCODE_KP_5] == KEY_DOWN && player2->action == NO_ACTION ||
		App->input->Controller2[SDL_CONTROLLER_BUTTON_Y] == KEY_STATE::KEY_DOWN)
	{
		player2->action = MEDIUM_PUNCH;
		App->audio->PlaySoundEffect(nonhit_sfx);
	}
	//HEAVY PUNCH
	if (App->input->keyboard[SDL_SCANCODE_KP_6] == KEY_DOWN && player2->action == NO_ACTION ||
		App->input->Controller2[SDL_CONTROLLER_BUTTON_LEFTSHOULDER] == KEY_STATE::KEY_DOWN)
	{
		player2->action = HEAVY_PUNCH;
		App->audio->PlaySoundEffect(nonhit_sfx);
	}

	if (player->position.x < player2->position.x)
	{
		player->flip = false;
		player2->flip = true;
	}
	if (player2->position.x < player->position.x)
	{
		player->flip = true;
		player2->flip = false;
	}

	player2->Update();
	player->Update();

	return update_status::UPDATE_CONTINUE;
}

