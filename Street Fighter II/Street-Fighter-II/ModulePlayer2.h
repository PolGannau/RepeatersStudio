#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	int font_score = -1;
	char score_text[10];
	uint score = 0;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation idlec;
	Animation forward;
	Animation backward;
	Animation crouching;
	Animation standing;
	Animation njump;
	//Animation njumpdown;
	Animation fjump;
	Animation bjump;
	Animation punch;
	Animation cpunch;
	Animation jpunch;
	Animation kick;
	Animation ckick;
	Animation jkick;
	Animation hadokenRyu;
	Animation shoryuken;
	Animation tatsumaki;

	iPoint position;
	Collider* col;
	bool destroyed = false;
	bool Bpunch = false;
	bool Bcpunch = false;
	bool Bkick = false;
	bool Bjpunch = false;
	bool Bjkick = false;
	bool Bckick = false;
	bool Bhadoken = false;
	bool Bnjump = false;
	bool Bfjump = false;
	bool Bbjump = false;
	bool Bcrouch = false;
	bool Bstand = false;

	/*Mix_Chunk* kickfx = nullptr;
	Mix_Chunk* punchfx = nullptr;*/
	Mix_Chunk* hadokenfx = nullptr;
	//bool Bnjumpdown = false;
};

#endif