#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
//#include "ModuleFonts.h"
#include "ModulePlayer2.h"
#include "ModuleAudio.h"

#include<stdio.h>

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	// idle animation (arcade sprite sheet)
	idle.PushBack({ 745, 1187, 101, 94 });//101
	idle.PushBack({ 782, 1004, 107, 91 });//107
	idle.PushBack({ 701, 740, 115, 87 });//115
	idle.PushBack({ 782, 1004, 107, 91 });//107
	//idle.PushBack({ 0, 809, 101, 94 });
	//idle.PushBack({ 118, 736, 59, 90 });
	//idle.PushBack({ 366, 12, 60, 92 });
	idle.speed = 0.13f;

	//idle crouch aniamtion
	idleCrouch.PushBack({ 532,196,94,70 });
	idleCrouch.speed = 0.1f;

	// walk forward animation (arcade sprite sheet)
	//forward.PushBack({ 637, 915, 124, 89 });
	forward.PushBack({ 0, 1187, 99, 92 });
	forward.PushBack({ 585, 1004, 100, 90 });
	forward.PushBack({ 224, 827, 100, 88 });
	forward.PushBack({ 485, 1004, 100, 90 });
	forward.PushBack({ 199, 1187, 99, 92 });
	forward.PushBack({ 375, 1095, 107, 91 });
	forward.PushBack({ 80, 1095, 108, 91 });
	//forward.PushBack({ 637, 915, 124, 89 });
	forward.speed = 0.13f;

	// walk backwards animation
	//backward.PushBack({ 454, 624, 124, 89 });
	//backward.PushBack({ 637, 915, 124, 89 });
	backward.PushBack({ 80, 1095, 108, 91 });
	backward.PushBack({ 375, 1095, 107, 91 });
	backward.PushBack({ 199, 1187, 99, 92 });
	backward.PushBack({ 485, 1004, 100, 90 });
	backward.PushBack({ 224, 827, 100, 88 });
	backward.PushBack({ 585, 1004, 100, 90 });
	backward.PushBack({ 0, 1187, 99, 92 });
	backward.speed = 0.13f;

	// punch animation
	lightPunch.PushBack({ 782, 1004, 107, 91 });//idle
	lightPunch.PushBack({ 782, 1004, 107, 91 });//idle
	lightPunch.PushBack({ 0, 1004, 122, 89 });//prep
	lightPunch.PushBack({ 0, 1004, 122, 89 });//prep
	lightPunch.PushBack({ 441, 574, 147, 82 });//dmg
	lightPunch.PushBack({ 441, 574, 147, 82 });//dmg
	lightPunch.PushBack({ 0, 1004, 122, 89 });//prep
	lightPunch.PushBack({ 0, 1004, 122, 89 });//prep
	lightPunch.PushBack({ 782, 1004, 107, 91 });//idle
	lightPunch.speed = 0.35f;

	//crouching punch animation
	crouchPunch.PushBack({ 390,111,69,61 });//prep
	crouchPunch.PushBack({ 390,111,69,61 });//prep
	crouchPunch.PushBack({ 459,111,95,61 });//hit
	crouchPunch.PushBack({ 459,111,95,61 });//hit
	crouchPunch.PushBack({ 459,111,95,61 });//hit
	crouchPunch.PushBack({ 459,111,95,61 });//hit
	crouchPunch.PushBack({ 390,111,69,61 });//recover
	crouchPunch.PushBack({ 390,111,69,61 });//recover
	crouchPunch.PushBack({ 390,111,69,61 });//recover
	crouchPunch.PushBack({ 390,111,69,61 });//recover
	crouchPunch.PushBack({ 66,111,61,61 });//idle
	crouchPunch.speed = 0.1f;

	//air punch
	jumpPunch.PushBack({ 906,174,52,69 });//prep
	jumpPunch.PushBack({ 906,174,52,69 });//prep
	jumpPunch.PushBack({ 486,243,81,71 });//hit, repeat until ground
	jumpPunch.speed = 0.1f;

	//air kick
	jumpKick.PushBack({ 871,243, 59,76 });//prep
	jumpKick.PushBack({ 871,243, 59,76 });//prep
	jumpKick.PushBack({ 757, 243,55,73 });//prep2
	jumpKick.PushBack({ 757, 243,55,73 });//prep2
	jumpKick.PushBack({ 757, 243,55,73 });//prep2
	jumpKick.PushBack({ 772, 174,77,67 });//hit, repeat until ground
	jumpKick.speed = 0.1f;

	// kick animation
	kick.PushBack({ 131, 827, 64, 91 });//idle
	kick.PushBack({ 131, 827, 64, 91 });//idle
	kick.PushBack({ 131, 827, 64, 91 });//idle
	kick.PushBack({ 358, 827, 66, 92 });
	kick.PushBack({ 358, 827, 66, 92 });
	kick.PushBack({ 358, 827, 66, 92 });
	kick.PushBack({ 747, 919, 114, 93 });
	kick.PushBack({ 747, 919, 114, 93 });
	kick.PushBack({ 747, 919, 114, 93 });
	kick.PushBack({ 747, 919, 114, 93 });
	kick.PushBack({ 747, 919, 114, 93 });
	kick.PushBack({ 747, 919, 114, 93 });
	kick.PushBack({ 747, 919, 114, 93 });
	kick.PushBack({ 747, 919, 114, 93 });
	kick.PushBack({ 358, 827, 66, 92 });
	kick.PushBack({ 358, 827, 66, 92 });
	kick.PushBack({ 358, 827, 66, 92 });
	kick.PushBack({ 358, 827, 66, 92 });
	kick.PushBack({ 131, 827, 64, 91 });//idle
	kick.speed = 1.0f;

	//crouching kick animation
	crouchKick.PushBack({ 447,174,70,64 });//prep
	crouchKick.PushBack({ 447,174,70,64 });//prep
	crouchKick.PushBack({ 335,174,112,64 });//hit
	crouchKick.PushBack({ 335,174,112,64 });//hit
	crouchKick.PushBack({ 335,174,112,64 });//hit
	crouchKick.PushBack({ 335,174,112,64 });//hit
	crouchKick.PushBack({ 447,174,70,64 });//prep
	crouchKick.PushBack({ 447,174,70,64 });//prep
	crouchKick.PushBack({ 447,174,70,64 });//prep
	crouchKick.PushBack({ 447,174,70,64 });//prep
	crouchKick.PushBack({ 66,111,61,61 });//idle
	crouchKick.speed = 0.1f;

	// neutral jump animation
	jump.PushBack({ 844, 1108, 56, 104 });
	jump.PushBack({ 542, 646, 50, 89 });
	jump.PushBack({ 827, 319, 54, 77 });
	jump.PushBack({ 315, 243, 48, 70 });
	jump.PushBack({ 592, 646, 48, 89 });
	jump.PushBack({ 252, 1212, 55, 109 });
	jump.speed = 0.1f;

	//forward jump animation
	forwardJump.PushBack({ 789, 1108, 55, 103 });
	forwardJump.PushBack({ 883, 396, 61, 78 });
	forwardJump.PushBack({ 387, 0, 104, 42 });
	forwardJump.PushBack({ 208, 474, 53, 82 });
	forwardJump.PushBack({ 610, 0, 122, 44 });
	forwardJump.PushBack({ 396, 558, 71, 87 });
	forwardJump.PushBack({ 197, 1212, 55, 109 });
	forwardJump.speed = 0.15f;

	//backwards jump animation
	backwardsJump.PushBack({ 197, 1212, 55, 109 });
	backwardsJump.PushBack({ 396, 558, 71, 87 });
	backwardsJump.PushBack({ 610, 0, 122, 44 });
	backwardsJump.PushBack({ 208, 474, 53, 82 });
	backwardsJump.PushBack({ 387, 0, 104, 42 });
	backwardsJump.PushBack({ 883, 396, 61, 78 });
	backwardsJump.PushBack({ 789, 1108, 55, 103 });
	backwardsJump.speed = 0.15f;

	//crouch animation
	crouching.PushBack({ 811,474,53,83 });
	crouching.PushBack({ 74,243,57,69 });
	crouching.PushBack({ 66,111,61,61 });
	crouching.speed = 0.1f;

	//stand up animation
	standing.PushBack({ 66,11,61,61 });
	standing.PushBack({ 74,243,57,69 });
	standing.PushBack({ 811,474,53,83 });
	standing.speed = 0.1f;

	//shoryuken animation
	/*shoryuken.PushBack({ 511, 560, 71, 87 });
	shoryuken.PushBack({ 511, 560, 71, 87 });
	shoryuken.PushBack({ 511, 560, 71, 87 });
	shoryuken.PushBack({ 511, 560, 71, 87 });
	shoryuken.PushBack({ 511, 560, 71, 87 });
	shoryuken.PushBack({ 511, 560, 71, 87 });
	shoryuken.speed = 0.1f;*/

	//hadoken animation
	/*hadokenRyu.PushBack({ 321,736,74,90 });
	hadokenRyu.PushBack({ 864,474,85, 84 });
	hadokenRyu.PushBack({ 314,474,90,83 });
	hadokenRyu.PushBack({ 190,396,106,77 });
	hadokenRyu.PushBack({ 190,396,106,77 });
	hadokenRyu.speed = 0.2f;*/

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	/*kickfx = App->audio->LoadEffect("../Game/Assets/Audio/Voice&SFX/GeneralAttacks/Hit Short.wav");
	punchfx = App->audio->LoadEffect("../Game/Assets/Audio/Voice&SFX/GeneralAttacks/Kick.wav");*/
	hadokenfx = App->audio->LoadEffect("../Game/Assets/Audio/Voice&SFX/Ryu/Hadouken.wav");

	coll_head = App->collision->AddCollider({ position.x + 26,position.y,20,20 }, COLLIDER_PLAYER_BODY, this);
	coll_body = App->collision->AddCollider({ position.x,position.y + 20,35,55 }, COLLIDER_PLAYER_BODY, this);
	coll_legs = App->collision->AddCollider({ position.x,position.y,52,30 }, COLLIDER_PLAYER_BODY, this);
	coll_attack = App->collision->AddCollider({ -100,20,28,20 }, COLLIDER_ATTACK, this);

	graphics = App->textures->Load("../Game/Assets/Images/Characters/hondaSprite.png");
	return ret;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	App->audio->UnloadSoundEffects(hadokenfx);
	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	if (coll_attack != nullptr && current_animation == &idle)coll_attack->rect.x = -1000;

	if (Bpunch)
	{
		current_animation = &lightPunch;
		if (current_animation->Finished())
		{
			current_animation->Reset();
			Bpunch = false;

		}
	}
	else if (Bkick)
	{
		current_animation = &kick;
		if (current_animation->Finished())
		{
			current_animation->Reset();
			Bkick = false;
		}
	}
	/*else if (backJumpPunch)
	{
	current_animation = &jumpPunch;
	if (current_animation->Finished())
	{
	current_animation->Reset();
	backJumpPunch = false;

	}
	}
	else if (backJumpKick)
	{
	current_animation = &jumpKick;
	if (current_animation->Finished())
	{
	current_animation->Reset();
	backJumpKick = false;
	}
	}*/
	else if (BcrouchPunch)
	{
		current_animation = &crouchPunch;
		if (current_animation->Finished())
		{
			current_animation->Reset();
			BcrouchPunch = false;

		}
	}
	else if (BcrouchKick)
	{
		current_animation = &crouchKick;
		if (current_animation->Finished())
		{
			current_animation->Reset();
			BcrouchKick = false;
		}
	}
	/*else if (Bhadoken)
	{
		current_animation = &hadokenRyu;
		if (current_animation->Finished())
		{
			current_animation->Reset();
			Bhadoken = false;
		}
	}*/
	else if (Bjump)
	{
		current_animation = &jump;
		if (current_animation->Finished())
		{
			current_animation->Reset();
			Bjump = false;
		}
	}
	else if (BforwardJump)
	{
		current_animation = &forwardJump;
		if (current_animation->Finished())
		{
			current_animation->Reset();
			BforwardJump = false;
		}
	}
	else if (BbackJump)
	{
		current_animation = &backwardsJump;
		if (current_animation->Finished())
		{
			current_animation->Reset();
			BbackJump = false;
		}
	}
	else
	{
		current_animation = &idle;
		int speed = 1;

		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT && position.x + 60 < App->render->limit.x + App->render->limit.w)
		{
			if (App->player2->position.x <= position.x)current_animation = &backward;
			if (App->player2->position.x > position.x)current_animation = &forward;
			position.x += speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT && position.x > App->render->limit.x + 1)
		{
			if (App->player2->position.x <= position.x)current_animation = &forward;
			if (App->player2->position.x > position.x)current_animation = &backward;
			position.x -= speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_W] == 1)
		{
			Bjump = true;
		}
		if (App->input->keyboard[SDL_SCANCODE_3] == 1)
		{
			BforwardJump = true;
		}
		if (App->input->keyboard[SDL_SCANCODE_2] == 1)
		{
			BbackJump = true;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_Y] == KEY_DOWN)
	{
		Bpunch = true;
	}
	if (App->input->keyboard[SDL_SCANCODE_U] == KEY_DOWN)
	{
		Bkick = true;
	}
	if (App->input->keyboard[SDL_SCANCODE_I] == KEY_DOWN)
	{
		Bhadoken = true;
		App->audio->PlaySoundEffect(hadokenfx);
		//App->particles->AddParticle(App->particles->hadokenParticle, position.x, position.y, COLLIDER_ATTACK, 4);
	}
	/*if (App->input->keyboard[SDL_SCANCODE_KP_1] == KEY_DOWN)
	{
	backJumpKick = true;
	}
	if (App->input->keyboard[SDL_SCANCODE_KP_2] == KEY_DOWN)
	{
	backJumpPunch = true;
	}*/
	if (App->input->keyboard[SDL_SCANCODE_K] == KEY_DOWN)
	{
		BcrouchKick = true;
	}
	if (App->input->keyboard[SDL_SCANCODE_L] == KEY_DOWN)
	{
		BcrouchPunch = true;
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	SetCharacterAndPaint(r);

	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1->callback == App->player2&&c1->type == COLLIDER_ATTACK || c2->callback == App->player2&&c2->type == COLLIDER_ATTACK)
		life -= 0.15F;
}

void ModulePlayer::SetCharacterAndPaint(SDL_Rect r)
{
	if (App->player2->position.x <= position.x)
	{
		App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0F, true, true);
		if (current_animation == &idle)
		{
			coll_head->rect.x = position.x + 14;
			coll_head->rect.y = position.y - r.h;
			coll_body->rect.x = position.x + 17;
			coll_body->rect.y = position.y - r.h + 5;
			coll_body->rect.h = 55;
			coll_legs->rect.x = position.x + 6;
			coll_legs->rect.y = position.y - r.h + 60;
		}
		else if (current_animation == &forward)
		{
			coll_head->rect.x = position.x + 26;
			coll_head->rect.y = position.y - r.h;
			coll_body->rect.x = position.x + 10;
			coll_body->rect.y = position.y - r.h + 5;
			coll_body->rect.h = 55;
			coll_legs->rect.x = position.x + 8;
			coll_legs->rect.y = position.y - r.h + 60;
		}
		else if (current_animation == &backward)
		{
			coll_head->rect.x = position.x + 26;
			coll_head->rect.y = position.y - r.h;
			coll_body->rect.x = position.x + 10;
			coll_body->rect.y = position.y - r.h + 5;
			coll_body->rect.h = 55;
			coll_legs->rect.x = position.x;
			coll_legs->rect.y = position.y - r.h + 60;
		}
		else if (current_animation == &kick)
		{
			coll_head->rect.x = position.x + 84;
			coll_head->rect.y = position.y - r.h + 2;
			coll_body->rect.x = position.x + 56;
			coll_body->rect.y = position.y - r.h + 20;
			coll_body->rect.h = 75;
			coll_legs->rect.x = position.x + 30;
			coll_legs->rect.y = position.y - r.h + 10;
			coll_attack->rect.x = position.x - 4;
			coll_attack->rect.y = position.y - r.h + 2;
		}
		else if (current_animation = &jump)
		{
			coll_head->rect.x = position.x + 14;
			coll_head->rect.y = position.y - r.h + 8;
			coll_body->rect.x = position.x + 10;
			coll_body->rect.y = position.y - r.h + 20;
			coll_body->rect.h = 55;
			coll_legs->rect.x = position.x + 16;
			coll_legs->rect.y = position.y - r.h + 60;
		}
	}
	else if (App->player2->position.x > position.x)
	{
		App->render->Blit(graphics, position.x, position.y - r.h, &r);

		if (current_animation == &idle)
		{
			coll_head->rect.x = position.x + 26;
			coll_head->rect.y = position.y - r.h;
			coll_body->rect.x = position.x + 5;
			coll_body->rect.y = position.y - r.h + 5;
			coll_body->rect.h = 55;
			coll_legs->rect.x = position.x;
			coll_legs->rect.y = position.y - r.h + 60;
		}
		else if (current_animation == &forward)
		{
			coll_head->rect.x = position.x + 26;
			coll_head->rect.y = position.y - r.h;
			coll_body->rect.x = position.x + 10;
			coll_body->rect.y = position.y - r.h + 5;
			coll_body->rect.h = 55;
			coll_legs->rect.x = position.x - 4;
			coll_legs->rect.y = position.y - r.h + 60;
		}
		else if (current_animation == &backward)
		{
			coll_head->rect.x = position.x + 17;
			coll_head->rect.y = position.y - r.h;
			coll_body->rect.x = position.x + 10;
			coll_body->rect.y = position.y - r.h + 5;
			coll_body->rect.h = 55;
			coll_legs->rect.x = position.x;
			coll_legs->rect.y = position.y - r.h + 60;
		}
		else if (current_animation == &kick)
		{
			coll_head->rect.x = position.x + 14;
			coll_head->rect.y = position.y - r.h + 2;
			coll_body->rect.x = position.x + 24;
			coll_body->rect.y = position.y - r.h + 20;
			coll_body->rect.h = 75;
			coll_legs->rect.x = position.x + 32;
			coll_legs->rect.y = position.y - r.h + 10;
			coll_attack->rect.x = position.x + 86;
			coll_attack->rect.y = position.y - r.h + 2;
		}
		else if (current_animation = &jump)
		{
			coll_head->rect.x = position.x + 17;
			coll_head->rect.y = position.y - r.h + 8;
			coll_body->rect.x = position.x + 10;
			coll_body->rect.y = position.y - r.h + 20;
			coll_body->rect.h = 55;
			coll_legs->rect.x = position.x - 10;
			coll_legs->rect.y = position.y - r.h + 60;
		}
	}
}