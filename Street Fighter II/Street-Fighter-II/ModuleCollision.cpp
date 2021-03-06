
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFonts.h"

ModuleCollision::ModuleCollision()
{
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	matrix[COLLIDER_BODY_PLAYER_ONE][COLLIDER_BODY_PLAYER_ONE] = false;
	matrix[COLLIDER_BODY_PLAYER_ONE][COLLIDER_BODY_PLAYER_TWO] = true;
	matrix[COLLIDER_BODY_PLAYER_ONE][COLLIDER_ATTACK_PLAYER_ONE] = false;
	matrix[COLLIDER_BODY_PLAYER_ONE][COLLIDER_ATTACK_PLAYER_TWO] = true;

	matrix[COLLIDER_BODY_PLAYER_TWO][COLLIDER_BODY_PLAYER_ONE] = true;
	matrix[COLLIDER_BODY_PLAYER_TWO][COLLIDER_BODY_PLAYER_TWO] = false;
	matrix[COLLIDER_BODY_PLAYER_TWO][COLLIDER_ATTACK_PLAYER_ONE] = true;
	matrix[COLLIDER_BODY_PLAYER_TWO][COLLIDER_ATTACK_PLAYER_TWO] = false;

	matrix[COLLIDER_ATTACK_PLAYER_ONE][COLLIDER_BODY_PLAYER_ONE] = false;
	matrix[COLLIDER_ATTACK_PLAYER_ONE][COLLIDER_BODY_PLAYER_TWO] = true;
	matrix[COLLIDER_ATTACK_PLAYER_ONE][COLLIDER_ATTACK_PLAYER_ONE] = false;
	matrix[COLLIDER_ATTACK_PLAYER_ONE][COLLIDER_ATTACK_PLAYER_TWO] = true;

	matrix[COLLIDER_ATTACK_PLAYER_TWO][COLLIDER_BODY_PLAYER_ONE] = true;
	matrix[COLLIDER_ATTACK_PLAYER_TWO][COLLIDER_BODY_PLAYER_TWO] = false;
	matrix[COLLIDER_ATTACK_PLAYER_TWO][COLLIDER_ATTACK_PLAYER_ONE] = true;
	matrix[COLLIDER_ATTACK_PLAYER_TWO][COLLIDER_ATTACK_PLAYER_TWO] = false;
}

// Destructor
ModuleCollision::~ModuleCollision()
{}

update_status ModuleCollision::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr && colliders[i]->to_delete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	// Test all collisions
	Collider* c1;
	Collider* c2;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if (colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for (uint k = i + 1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if (colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if (c1->CheckCollision(c2->rect) == true)
			{
				if (matrix[c1->type][c2->type] && c1->callback)
					c1->callback->OnCollision(c1, c2);

				if (matrix[c2->type][c1->type] && c2->callback)
					c2->callback->OnCollision(c2, c1);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleCollision::Update()
{

	DebugDraw();

	return UPDATE_CONTINUE;
}

void ModuleCollision::DebugDraw()
{
	if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN)
		debug = !debug;

	if (debug == false)
		return;

	if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_DOWN)
	{
		matrix[COLLIDER_BODY_PLAYER_ONE][COLLIDER_ATTACK_PLAYER_TWO] = !matrix[COLLIDER_BODY_PLAYER_ONE][COLLIDER_ATTACK_PLAYER_TWO];
		matrix[COLLIDER_ATTACK_PLAYER_TWO][COLLIDER_BODY_PLAYER_ONE] = !matrix[COLLIDER_ATTACK_PLAYER_TWO][COLLIDER_BODY_PLAYER_ONE];
		matrix[COLLIDER_BODY_PLAYER_TWO][COLLIDER_ATTACK_PLAYER_ONE] = !matrix[COLLIDER_BODY_PLAYER_TWO][COLLIDER_ATTACK_PLAYER_ONE];
		matrix[COLLIDER_ATTACK_PLAYER_ONE][COLLIDER_BODY_PLAYER_TWO] = !matrix[COLLIDER_ATTACK_PLAYER_ONE][COLLIDER_BODY_PLAYER_TWO];
		matrix[COLLIDER_ATTACK_PLAYER_ONE][COLLIDER_ATTACK_PLAYER_TWO] = !matrix[COLLIDER_ATTACK_PLAYER_ONE][COLLIDER_ATTACK_PLAYER_TWO];
		matrix[COLLIDER_ATTACK_PLAYER_TWO][COLLIDER_ATTACK_PLAYER_ONE] = !matrix[COLLIDER_ATTACK_PLAYER_TWO][COLLIDER_ATTACK_PLAYER_ONE];
	}

	Uint8 alpha = 80;
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
			continue;

		switch (colliders[i]->type)
		{
		case COLLIDER_NONE: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case COLLIDER_BODY_PLAYER_ONE: // green
			if(matrix[COLLIDER_BODY_PLAYER_ONE][COLLIDER_ATTACK_PLAYER_TWO])App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			else App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, 0);
			break;
		case COLLIDER_BODY_PLAYER_TWO: // green
			if (matrix[COLLIDER_BODY_PLAYER_TWO][COLLIDER_ATTACK_PLAYER_ONE])App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			else App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, 0);
			break;
		case COLLIDER_ATTACK_PLAYER_ONE: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case COLLIDER_ATTACK_PLAYER_TWO: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		}
	}
}

// Called before quitting
bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");
	
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return true;
}

Collider* ModuleCollision::AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback)
{
	Collider* ret = nullptr;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, callback);
			break;
		}
	}

	return ret;
}

// -----------------------------------------------------

bool Collider::CheckCollision(const SDL_Rect& r) const
{
	return (rect.x < r.x + r.w &&
		rect.x + rect.w > r.x &&
		rect.y < r.y + r.h &&
		rect.h + rect.y > r.y);
}