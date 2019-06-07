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
	
	/// HONDA ANIMATIONS
	//standing
	Animation idle;
	Animation turnLeft;
	Animation turnRight;
	Animation forward;
	Animation backward;

	Animation lightKick;
	Animation mediumKick;
	Animation heavyKick;

	Animation lightPunch;
	Animation mediumPunch;
	Animation heavyPunch;
	//close
	Animation closeLightKick;
	Animation closeMediumKick;
	Animation closeHeavyKick;

	//crouching
	Animation idleCrouch;
	Animation crouchTurn;
	Animation crouching;//standing to crouch
	Animation standing;//crouch to standing

	Animation crouchLightKick;
	Animation crouchMediumKick;
	Animation crouchHeavyKick;

	Animation crouchLightPunch;
	Animation crouchMediumPunch;
	Animation crouchHeavyPunch;

	//jumping
	Animation jump;

	Animation neutralJump;//jump with no directions
	Animation forwardJump;
	Animation backwardJump;

	Animation jumpLightKick;
	Animation jumpMediumKick;
	Animation jumpHeavyKick;
	Animation jumpDiagonalLightKick;
	Animation jumpDiagonalMediumKick;
	Animation jumpDiagonalHeavyKick;

	Animation jumpLightPunch;
	Animation jumpMediumPunch;
	Animation jumpHeavyPunch;
	Animation jumpDiagonalLightPunch;//same as jump LightPunch
	Animation jumpDiagonalMediumPunch;//same as jump MediumPunch
	Animation jumpDiagonalHeavyPunch;//same as jump HeavyPunch

									 //grabs
	Animation throwing;//throws enemy
	Animation knees;//grabs and kicks the enemy
	Animation hug;//crush enemy

				  //victory
	Animation victory;
	Animation victory2;

	//special
	//Animation SumoHeadbutt;
	Animation LightSumoHeadbutt;
	Animation MediumSumoHeadbutt;
	Animation HeavySumoHeadbutt;
	//Animation HundredSlaps;
	Animation LightHundredSlaps;
	Animation MediumHundredSlaps;
	Animation HeavyHundredSlaps;
	Animation DoubleKnee;

	//hurt
	Animation Hit;//gets hit
	Animation GutHit;//gets hit hard
	Animation crouchHit;//gets hit while crouched
	Animation stunned;//
	Animation knockdown;//falling
	Animation KO;//
	Animation recover;//honda gets up from the ground
					  /// END HONDA ANIMATIONS

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
	bool round_won = false;
	bool game_won = false;

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
