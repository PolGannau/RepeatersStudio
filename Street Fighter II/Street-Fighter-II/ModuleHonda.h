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

enum TYPE_ACTION
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
	LIGHT_SUMO_HEAD_BUTT,
	MEDIUM_SUMO_HEAD_BUTT,
	HEAVY_SUMO_HEAD_BUTT,
	LIGHT_HUNDRED_SLAPS,
	MEDIUM_HUNDRED_SLAPS,
	HEAVY_HUNDRED_SLAPS,
	DOUBLE_KNEE,
	BLOCK
};

enum MOVEMENT_CHARACTER
{
	NO_MOVE = 0,
	IDLE,
	FORWARD,
	BACKWARD,
	HIT,
	GUT_HIT,
	TURN_LEFT,
	TURN_RIGHT
};

enum STATE_CHARACTER
{
	ON_FLOOR = 0,
	STANDING_TO_CROUCHING,
	CROUCHING,
	CROUCHING_TO_STANDING,
	JUMPING,
	VICTORY,
	SECOND_VICTORY,
	STUNNED,
	KNOCK_DOWN,
	KNOCK_OUT,
	RECOVER
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
	//Sound Effects
	Mix_Chunk* lightpunch_sfx;
	Mix_Chunk* mediumpunch_sfx;
	Mix_Chunk* heavypunch_sfx;
	Mix_Chunk* lightkick_sfx;
	Mix_Chunk* mediumkick_sfx;
	Mix_Chunk* heavykick_sfx;
	Mix_Chunk* special_sfx;
	Mix_Chunk* block_sfx;
	Mix_Chunk* laugh_sfx;
	Mix_Chunk* nonhit_sfx;
	
	// Scores
	int				font_score = -1;
	char			score_text[10];
	uint			score = 0;

	// Jumping Variables
	float			vspeed;
	float			acceleration = 0.8F;
	float			VerticalSpeed = -12.0F;

	//hp
	int hp = 100;

	// Close Attacks Control Varaible
	uint			CloseDistance = 40;
	uint			Players_Distance;

	// Auxiliar Rect
	SDL_Rect		auxiliar;

	// Logic Variables
	TYPE_ACTION				action;
	MOVEMENT_CHARACTER		movement;
	STATE_CHARACTER			state;

	// Current Animation Control
	Animation*		current_animation = nullptr;
	bool			flip;
	PLAYER_NUMBER	player_num;

	// Round and Game Win Control
	bool round_won = false;
	bool game_won = false;
	
	// Position
	iPoint			position;

	// Auxiliar Position
	iPoint			auxPosition;

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

	Animation block;
	Animation crouchblock;
	/// END HONDA ANIMATIONS
};

#endif // !__MODULEHONDA_H__