#include "ModulePlayersManager.h"
#include "ModuleHonda.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"

ModulePlayersManager::ModulePlayersManager()
{}

ModulePlayersManager::~ModulePlayersManager()
{}

bool ModulePlayersManager::Start()
{
	graphics = App->textures->Load("../Game/Assets/Images/Characters/hondaSprite.png");
	player = CreatePlayer(PLAYER_NUMBER::NUMBER_ONE);
	player2 = CreatePlayer(PLAYER_NUMBER::NUMBER_TWO);
	player->vspeed = 0;
	player2->vspeed = 0;

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
	update_status::UPDATE_ERROR;
}

update_status ModulePlayersManager::Update()
{
	/// PLAYER INPUT CONTROL AND LOGIC ---------------------------------------------------
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && player->state == ON_FLOOR)
	{
		player->state = JUMPING;
		player->vspeed += player->VerticalSpeed;
	}
	if ((player->position.y > 212) && player->state == JUMPING)
	{
		player->state = ON_FLOOR;
		player->position.y = 212;
	}
	switch (player->state)
	{
	case ON_FLOOR:
		player->position.y = 212;
		player->current_animation = &player->idle;
		break;
	case JUMPING:
		player->current_animation = &player->neutralJump;
		player->vspeed += player->acceleration;
		player->position.y += player->vspeed;
		break;
	}

	/// PLAYER 2 INPUT CONTROL AND LOGIC ---------------------------------------------------
	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_DOWN && player2->state == ON_FLOOR)
	{
		player2->state = JUMPING;
		player2->vspeed += player2->VerticalSpeed;
	}
	if ((player2->position.y > 212) && player2->state == JUMPING)
	{
		player2->state = ON_FLOOR;
		player2->position.y = 212;
	}
	switch (player2->state)
	{
	case ON_FLOOR:
		player2->position.y = 212;
		player2->current_animation = &player2->idle;
		break;
	case JUMPING:
		player2->current_animation = &player2->neutralJump;
		player2->vspeed += player2->acceleration;
		player2->position.y += player2->vspeed;
		break;
	}

	player->Update();
	player2->Update();

	return update_status::UPDATE_CONTINUE;
}

