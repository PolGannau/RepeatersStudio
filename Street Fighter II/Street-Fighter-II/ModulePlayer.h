#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

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
	
	//standing
	Animation idle;
	Animation turn;
	Animation forward;
	Animation backward;
	///normal
	Animation kick;
	Animation lightKick;
	Animation mediumKick;
	Animation heavyKick;
	Animation punch;
	Animation lightPunch;
	Animation mediumPunch;
	Animation heavyPunch;
	///close
	Animation closeLightKick;
	Animation closeMediumKick;
	Animation closeHeavyKick;
	Animation closeLightPunch;
	Animation closeMediumPunch;
	Animation closeHeavyPunch;

	//crouching
	Animation idleCrouch;
	Animation crouching;
	Animation standing;
	Animation crouchKick;
	Animation crouchLightKick;
	Animation crouchMediumKick;
	Animation crouchHeavyKick;
	Animation crouchPunch;
	Animation crouchLightPunch;
	Animation crouchMediumPunch;
	Animation crouchHeavyPunch;

	//jumping
	Animation jump;
	//Animation jumpdown;
	Animation forwardJump;
	Animation backwardsJump;
	Animation jumpKick;
	Animation jumpLightKick;
	Animation jumpMediumKick;
	Animation jumpHeavyKick;
	Animation jumpDiagonalLightKick;
	Animation jumpDiagonalMediumKick;
	Animation jumpDiagonalHeavyKick;
	Animation jumpPunch;
	Animation jumpLightPunch;
	Animation jumpMediumPunch;
	Animation jumpHeavyPunch;
	Animation jumpDiagonalLightPunch;
	Animation jumpDiagonalMediumPunch;
	Animation jumpDiagonalHeavyPunch;
	
	//grabs
	Animation hold;
	Animation throwing;

	//victory
	Animation victory;
	Animation victory2;

	//special
	Animation SumoHeadbutt;
	Animation HundredSlaps;
	Animation DoubleKnee;

	//hurt
	Animation standingHit;
	Animation standingGutHit;
	Animation crouchHit;
	Animation stunned;

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

	//float gravity = 2;
	//int jumpheight = 120;
	//int floorheight = 622;
	int speed = 1;
	float life;

	/*Mix_Chunk* kickfx = nullptr;
	Mix_Chunk* punchfx = nullptr;*/
	Mix_Chunk* hadokenfx = nullptr;
	//bool backJumpdown = false;
};

#endif
