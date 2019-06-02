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
	void SetCharacterAndPaint(SDL_Rect r);

public:

	SDL_Texture* graphics = nullptr;
	int font_score = -1;
	char score_text[10];
	uint score = 0;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation idleCrouch;
	Animation forward;
	Animation backward;
	Animation crouching;
	Animation standing;
	Animation jump;
	//Animation jumpdown;
	Animation forwardJump;
	Animation backwardsJump;
	Animation punch;
	Animation crouchPunch;
	Animation jumpPunch;
	Animation kick;
	Animation crouchKick;
	Animation jumpKick;
	Animation hadokenRyu;
	Animation shoryuken;
	Animation tatsumaki;

	iPoint position;
	Collider* coll_head = nullptr;
	Collider* coll_body = nullptr;
	Collider* coll_legs = nullptr;
	Collider* coll_attack = nullptr;
	bool destroyed = false;
	bool Bpunch = false;
	bool BcrouchPunch = false;
	bool Bkick = false;
	bool backJumpPunch = false;
	bool backJumpKick = false;
	bool BcrouchKick = false;
	bool Bhadoken = false;
	bool Bjump = false;
	bool BforwardJump = false;
	bool BbackJump = false;
	bool Bcrouch = false;
	bool Bstand = false;

	float life;

	/*Mix_Chunk* kickfx = nullptr;
	Mix_Chunk* punchfx = nullptr;*/
	Mix_Chunk* hadokenfx = nullptr;
	//bool backJumpdown = false;
};

#endif