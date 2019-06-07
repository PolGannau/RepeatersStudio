#ifndef __MODULEHONDA_H__
#define __MODULEHONDA_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
struct Collider;

enum class PLAYER_NUMBER
{
	NO_NUMBER,
	NUMBER_ONE,
	NUMBER_TWO,
	MAX
};

enum class TYPE_ACTION
{
	NO_ACTION = 0,
	LIGHT_KICK,
	MEDIUM_KICK,
	HEAVY_KICK,
	LIGHT_PUNCH,
	MEDIUM_PUNCH,
	HEAVY_PUNCH,
	THROW,
	KNEES,
	HUG,
	SUMO_HEAD_BUTT,
	HUNDRED_SLAPS,
	DOUBLE_KNEE,
	MAX
};

enum class MOVEMENT_CHARACTER
{
	IDLE = 0,
	FORWARD,
	BACKWARD,
	IDLE_CROUCHING,
	MAX
};

enum class STATE_CHARACTER
{
	ON_FLOOR = 0,
	IDLE,
	TURN_LEFT,
	TURN_RIGHT,
	STANDING_TO_CROUCHING,
	CROUCHING_TO_STANDING,
	JUMPING,
	FALLING,
	VICTORY,
	SECOND_VICTORY,
	HIT,
	GUT_HIT,
	STUNNED,
	KNOCK_DOWN,
	KO,
	RECOVER,
	MAX
};

// This class controls how Honda works
class ModuleHonda : public Module
{
public:
	ModuleHonda(PLAYER_NUMBER);
	~ModuleHonda();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:
	// Scores
	int				font_score = -1;
	char			score_text[10];
	uint			score = 0;

	// Auxiliar Rect
	SDL_Rect		auxiliar;

	// Current Animation Control
	Animation*		current_animation = nullptr;
	PLAYER_NUMBER	player_num;

	// Position
	iPoint			position;

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
	Animation LightSumoHeadbutt;
	Animation MediumSumoHeadbutt;
	Animation HeavySumoHeadbutt;

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
};

#endif // !__MODULEHONDA_H__