#ifndef __MODULEHONDA_H__
#define __MODULEHONDA_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
struct Collider;

enum class TYPE_ACTION
{
	NO_ACTION = 0,
	LIGHT_KICK,
	MEDIUM_KICK,
	HEAVY_KICK,
	LIGHT_PUNCH,
	MEDIUM_PUNCH,
	HEAVY_PUNCH,
};

enum class STATE_CHARACTER
{
	ON_FLOOR = 0,
	IDLE,
	TURN,
	FORWARD,
	BACKWARD,
	STANDING_TO_CROUCHING,
	IDLE_CROUCHING,
	CROUCHING_TO_STANDING,
	JUMPING,
	FALLING,
	MAX
};

// This class controls how Honda works
class ModuleHonda : public Module
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
	// Scores
	int			font_score = -1;
	char		score_text[10];
	uint		score = 0;

	// Current Animation Control
	Animation*	current_animation = nullptr;

	// Position
	iPoint position;

	// Character Colliders
	Collider* coll_head = nullptr;
	Collider* coll_body = nullptr;
	Collider* coll_legs = nullptr;
	Collider* coll_attack = nullptr;

	// Sound FX

	/// HONDA ANIMATIONS
	//standing
	Animation idle;
	Animation turn;
	Animation forward;
	Animation backward;

	//normal
	Animation kick;
	Animation lightKick;
	Animation mediumKick;
	Animation heavyKick;
	Animation punch;
	Animation lightPunch;
	Animation mediumPunch;
	Animation heavyPunch;

	//close
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
	/// END HONDA ANIMATIONS
};

#endif // !__MODULEHONDA_H__