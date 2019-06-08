#include "ModulePlayersManager.h"
#include "ModuleHonda.h"
#include "Application.h"
#include "ModuleRender.h"
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
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_DOWN)
	{
		player->state = JUMPING;
		player->vspeed += player->VerticalSpeed;
	}
	//BACKWARD
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT)
	{
		player->movement = MOVEMENT_CHARACTER::BACKWARD;
		if (player->position.x > App->render->limit.x + 64)player->position.x -= 1;
	}
	//FORWARD
	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT)
	{
		player->movement = MOVEMENT_CHARACTER::FORWARD;
		if(player->position.x < (App->render->limit.x + player->auxiliar.w + 220))player->position.x += 1;
	}
	//CROUCH
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_REPEAT && player->state == ON_FLOOR)player->state = STATE_CHARACTER::STANDING_TO_CROUCHING;
	else if (App->input->keyboard[SDL_SCANCODE_S] == KEY_UP && player->state == CROUCHING)player->state = STATE_CHARACTER::CROUCHING_TO_STANDING;
	//LIGHT KICK
	if (App->input->keyboard[SDL_SCANCODE_F] == KEY_DOWN && player->action == NO_ACTION)
	{
		player->action = LIGHT_KICK;
	}
	if (App->input->keyboard[SDL_SCANCODE_G] == KEY_DOWN && player->action == NO_ACTION)
	{
		player->action = MEDIUM_KICK;
	}
	if (App->input->keyboard[SDL_SCANCODE_H] == KEY_DOWN && player->action == NO_ACTION)
	{
		player->action = HEAVY_KICK;
	}

	/// PLAYER 2 INPUT CONTROL AND LOGIC -------------------------------------------------
	player2->movement = NO_MOVE;
	//JUMP
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_DOWN && player2->state == ON_FLOOR)
	{
		player2->state = JUMPING;
		player2->vspeed += player2->VerticalSpeed;
	}
	//BACKWARD
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_REPEAT && player2->state == ON_FLOOR)
	{
		player2->state = STATE_CHARACTER::ON_FLOOR;
		player2->movement = MOVEMENT_CHARACTER::BACKWARD;
		if(player2->position.x > App->render->limit.x + 64)player2->position.x -= 1;
	}
	//FORWARD
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_REPEAT && player2->state == ON_FLOOR)
	{
		player2->state = STATE_CHARACTER::ON_FLOOR;
		player2->movement = MOVEMENT_CHARACTER::FORWARD;
		if (player2->position.x < (App->render->limit.x + player2->auxiliar.w + 220))player2->position.x += 1;
	}
	//CROUCH
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_REPEAT && player2->state == ON_FLOOR)player2->state = STATE_CHARACTER::STANDING_TO_CROUCHING;
	else if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_UP && player2->state == CROUCHING)player2->state = STATE_CHARACTER::CROUCHING_TO_STANDING;

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

