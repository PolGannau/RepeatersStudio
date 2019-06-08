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
	//JUMP
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_DOWN && player->state == ON_FLOOR)
	{
		player->state = JUMPING;
		player->vspeed += player->VerticalSpeed;
	}
	//BACKWARD
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_DOWN && player->state == ON_FLOOR)
	{
		player->state = STATE_CHARACTER::ON_FLOOR;
		player->movement = MOVEMENT_CHARACTER::BACKWARD;
	}
	else if (App->input->keyboard[SDL_SCANCODE_A] == KEY_UP)MOVEMENT_CHARACTER::NO_MOVE;
	//FORWARD
	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_DOWN && player->state == ON_FLOOR)
	{
		player->state = STATE_CHARACTER::ON_FLOOR;
		player->movement = MOVEMENT_CHARACTER::FORWARD;
	}
	else if (App->input->keyboard[SDL_SCANCODE_D] == KEY_UP)MOVEMENT_CHARACTER::NO_MOVE;

	/// PLAYER 2 INPUT CONTROL AND LOGIC -------------------------------------------------
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_DOWN && player2->state == ON_FLOOR)
	{
		player2->state = JUMPING;
		player2->vspeed += player2->VerticalSpeed;
	}

	if (player->position.x < player2->position.x)player2->flip = true;
	else player->flip = true;

	player2->Update();
	player->Update();

	return update_status::UPDATE_CONTINUE;
}

