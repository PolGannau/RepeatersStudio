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
	Animation SumoHeadbutt;
	//Animation LightSumoHeadbutt;
	//Animation MediumSumoHeadbutt;
	//Animation HeavySumoHeadbutt;
	Animation HundredSlaps;
	//Animation LightHundredSlaps;
	//Animation MediumHundredSlaps;
	//Animation HeavyHundredSlaps;
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
};

#endif // !__MODULEHONDA_H__