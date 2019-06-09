#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleHonda.h"
#include "ModuleInput.h"
#include "ModulePlayersManager.h"
//#include "ModuleFonts.h"
#include "ModuleAudio.h"

#include<stdio.h>

ModuleHonda::ModuleHonda(PLAYER_NUMBER num) 
{ player_num = num; 

// idle animation (arcade sprite sheet)
idle.PushBack({ 745, 1187, 101, 94 });//101
idle.PushBack({ 782, 1004, 107, 91 });//107
idle.PushBack({ 701, 740, 115, 87 });//115
idle.PushBack({ 782, 1004, 107, 91 });//107
//idle.PushBack({ 0, 809, 101, 94 });
//idle.PushBack({ 118, 736, 59, 90 });
//idle.PushBack({ 366, 12, 60, 92 });
idle.speed = 0.13f;
idle.loop = true;

//idle crouch aniamtion
idleCrouch.PushBack({ 438,196,94,70 });
idleCrouch.speed = 0.1f;
idleCrouch.loop = true;

//crouching
crouching.PushBack({ 782, 1004, 107, 91 });//idle
crouching.PushBack({ 458, 656, 97, 84 });//crouching
crouching.PushBack({ 854, 340, 96, 76 });//crouching
crouching.PushBack({ 438, 196, 94, 70 });//idleCrouch
crouching.speed = 0.75f;

//turn
turnLeft.PushBack({ 782, 1004, 107, 91 });//idle
turnLeft.PushBack({ 589, 1095, 97, 91 });//turn
turnLeft.PushBack({ 298, 1187, 100, 92 });//idle2
turnLeft.speed = 0.75f;

crouchTurn.PushBack({ 438,196,94,70 });//idle
crouchTurn.PushBack({ 879,196,107,71 });//turn
crouchTurn.PushBack({ 644,196,101,72 });//idle2
crouchTurn.speed = 0.75f;

//standing
standing.PushBack({ 438, 196, 94, 70 });//idleCrouch
standing.PushBack({ 854, 340, 96, 76 });//crouching
standing.PushBack({ 458, 656, 97, 84 });//crouching
standing.PushBack({ 782, 1004, 107, 91 });//idle
standing.speed = 0.75f;

// walk forward animation
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
forward.loop = true;

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
backward.loop = true;

//jump 
neutralJump.PushBack({ 782, 1004, 107, 91 });//idle
neutralJump.PushBack({ 655, 1694, 77, 130 });
neutralJump.PushBack({ 410, 1281, 97, 94 });
neutralJump.PushBack({ 258, 59, 94, 65 });
neutralJump.PushBack({ 410, 1281, 97, 94 });
neutralJump.PushBack({ 655, 1694, 77, 130 });
neutralJump.PushBack({ 782, 1004, 107, 91 });//idle
neutralJump.speed = 0.13f;
neutralJump.loop = false;

forwardJump.PushBack({ 782, 1004, 107, 91 });//idle
forwardJump.PushBack({ 824, 1694, 119, 142 });
forwardJump.PushBack({ 664, 340, 108, 75 });
forwardJump.PushBack({ 155, 493, 81, 79 });
forwardJump.PushBack({ 783, 827, 109, 88 });
forwardJump.PushBack({ 0, 1281, 113, 94 });
forwardJump.PushBack({ 526, 1694, 129, 128 });
forwardJump.PushBack({ 782, 1004, 107, 91 });//idle
forwardJump.speed = 0.13f;

backwardJump.PushBack({ 782, 1004, 107, 91 });//idle
backwardJump.PushBack({ 526, 1694, 129, 128 });
backwardJump.PushBack({ 0, 1281, 113, 94 });
backwardJump.PushBack({ 783, 827, 109, 88 });
backwardJump.PushBack({ 155, 493, 81, 79 });
backwardJump.PushBack({ 664, 340, 108, 75 });
backwardJump.PushBack({ 824, 1694, 119, 142 });
backwardJump.PushBack({ 782, 1004, 107, 91 });//idle
backwardJump.speed = 0.13f;

// punch animations
lightPunch.PushBack({ 782, 1004, 107, 91 });//idle  2
lightPunch.PushBack({ 782, 1004, 107, 91 });//idle
lightPunch.PushBack({ 0, 1004, 122, 89 });//prep  2
lightPunch.PushBack({ 0, 1004, 122, 89 });//prep
lightPunch.PushBack({ 441, 574, 147, 82 });//dmg  4
lightPunch.PushBack({ 441, 574, 147, 82 });//dmg
lightPunch.PushBack({ 441, 574, 147, 82 });//dmg
lightPunch.PushBack({ 441, 574, 147, 82 });//dmg
lightPunch.PushBack({ 0, 1004, 122, 89 });//prep  2
lightPunch.PushBack({ 0, 1004, 122, 89 });//prep
lightPunch.PushBack({ 782, 1004, 107, 91 });//idle  1
lightPunch.speed = 1.0f;

mediumPunch.PushBack({ 782, 1004, 107, 91 });//idle  2
mediumPunch.PushBack({ 782, 1004, 107, 91 });//idle
mediumPunch.PushBack({ 687, 827, 96, 88 });//prep  2
mediumPunch.PushBack({ 687, 827, 96, 88 });//prep
mediumPunch.PushBack({ 753, 656, 121, 84 });//prep2  1
mediumPunch.PushBack({ 753, 656, 121, 84 });//prep2
mediumPunch.PushBack({ 294, 740, 145, 85 });//dmg  4
mediumPunch.PushBack({ 294, 740, 145, 85 });//dmg
mediumPunch.PushBack({ 294, 740, 145, 85 });//dmg
mediumPunch.PushBack({ 294, 740, 145, 85 });//dmg
mediumPunch.PushBack({ 753, 656, 121, 84 });//prep2 recover  2
mediumPunch.PushBack({ 753, 656, 121, 84 });//prep2 recover
mediumPunch.PushBack({ 687, 827, 96, 88 });//prep recover  2
mediumPunch.PushBack({ 687, 827, 96, 88 });//prep recover
mediumPunch.PushBack({ 782, 1004, 107, 91 });//idle recover  2
mediumPunch.speed = 1.0f;

heavyPunch.PushBack({ 782, 1004, 107, 91 });//idle  3
heavyPunch.PushBack({ 782, 1004, 107, 91 });//idle
heavyPunch.PushBack({ 782, 1004, 107, 91 });//idle
heavyPunch.PushBack({ 115, 1694, 104, 115 });//prep  3
heavyPunch.PushBack({ 115, 1694, 104, 115 });//prep
heavyPunch.PushBack({ 115, 1694, 104, 115 });//prep
heavyPunch.PushBack({ 301, 1694, 109, 118 });//dmg1  3
heavyPunch.PushBack({ 301, 1694, 109, 118 });//dmg1
heavyPunch.PushBack({ 301, 1694, 109, 118 });//dmg1
heavyPunch.PushBack({ 324, 1004, 161, 90 });//dmg2  4
heavyPunch.PushBack({ 324, 1004, 161, 90 });//dmg2
heavyPunch.PushBack({ 324, 1004, 161, 90 });//dmg2
heavyPunch.PushBack({ 324, 1004, 161, 90 });//dmg2
heavyPunch.PushBack({ 204, 915, 117, 88 });//recover  7
heavyPunch.PushBack({ 204, 915, 117, 88 });//recover
heavyPunch.PushBack({ 204, 915, 117, 88 });//recover
heavyPunch.PushBack({ 204, 915, 117, 88 });//recover
heavyPunch.PushBack({ 204, 915, 117, 88 });//recover
heavyPunch.PushBack({ 204, 915, 117, 88 });//recover
heavyPunch.PushBack({ 204, 915, 117, 88 });//recover
heavyPunch.PushBack({ 324, 1004, 161, 90 });//dmg2  5
heavyPunch.PushBack({ 324, 1004, 161, 90 });//dmg2
heavyPunch.PushBack({ 324, 1004, 161, 90 });//dmg2
heavyPunch.PushBack({ 324, 1004, 161, 90 });//dmg2
heavyPunch.PushBack({ 324, 1004, 161, 90 });//dmg2
heavyPunch.PushBack({ 301, 1694, 109, 118 });//dmg1  3
heavyPunch.PushBack({ 301, 1694, 109, 118 });//dmg1
heavyPunch.PushBack({ 301, 1694, 109, 118 });//dmg1
heavyPunch.PushBack({ 115, 1694, 104, 115 });//prep  2
heavyPunch.PushBack({ 115, 1694, 104, 115 });//prep  1
heavyPunch.PushBack({ 782, 1004, 107, 91 });//idle
heavyPunch.speed = 1.0f;

//kick animations

lightKick.PushBack({ 782, 1004, 107, 91 });//idle  3
lightKick.PushBack({ 782, 1004, 107, 91 });//idle
lightKick.PushBack({ 782, 1004, 107, 91 });//idle
lightKick.PushBack({ 0, 915, 102, 88 });//prep  3
lightKick.PushBack({ 0, 915, 102, 88 });//prep
lightKick.PushBack({ 0, 915, 102, 88 });//prep
lightKick.PushBack({ 122, 1004, 78, 89 });//kick  3
lightKick.PushBack({ 122, 1004, 78, 89 });//kick
lightKick.PushBack({ 122, 1004, 78, 89 });//kick
lightKick.PushBack({ 722, 493, 134, 80 });//dmg  4
lightKick.PushBack({ 722, 493, 134, 80 });//dmg
lightKick.PushBack({ 722, 493, 134, 80 });//dmg
lightKick.PushBack({ 722, 493, 134, 80 });//dmg
lightKick.PushBack({ 122, 1004, 78, 89 });//kick  3
lightKick.PushBack({ 122, 1004, 78, 89 });//kick
lightKick.PushBack({ 122, 1004, 78, 89 });//kick
lightKick.PushBack({ 0, 915, 102, 88 });//prep  3
lightKick.PushBack({ 0, 915, 102, 88 });//prep
lightKick.PushBack({ 0, 915, 102, 88 });//prep
lightKick.PushBack({ 782, 1004, 107, 91 });//idle  1
lightKick.speed = 1.0f;
lightKick.loop = true;

mediumKick.PushBack({ 782, 1004, 107, 91 });//idle  3
mediumKick.PushBack({ 782, 1004, 107, 91 });//idle
mediumKick.PushBack({ 782, 1004, 107, 91 });//idle
mediumKick.PushBack({ 0, 915, 102, 88 });//prep  3
mediumKick.PushBack({ 0, 915, 102, 88 });//prep
mediumKick.PushBack({ 0, 915, 102, 88 });//prep
mediumKick.PushBack({ 122, 1004, 78, 89 });//kick  3
mediumKick.PushBack({ 122, 1004, 78, 89 });//kick
mediumKick.PushBack({ 122, 1004, 78, 89 });//kick
mediumKick.PushBack({ 722, 493, 134, 80 });//dmg  4
mediumKick.PushBack({ 722, 493, 134, 80 });//dmg
mediumKick.PushBack({ 722, 493, 134, 80 });//dmg
mediumKick.PushBack({ 722, 493, 134, 80 });//dmg
mediumKick.PushBack({ 122, 1004, 78, 89 });//kick  5
mediumKick.PushBack({ 122, 1004, 78, 89 });//kick
mediumKick.PushBack({ 122, 1004, 78, 89 });//kick
mediumKick.PushBack({ 122, 1004, 78, 89 });//kick
mediumKick.PushBack({ 122, 1004, 78, 89 });//kick
mediumKick.PushBack({ 0, 915, 102, 88 });//prep  6
mediumKick.PushBack({ 0, 915, 102, 88 });//prep
mediumKick.PushBack({ 0, 915, 102, 88 });//prep
mediumKick.PushBack({ 0, 915, 102, 88 });//prep
mediumKick.PushBack({ 0, 915, 102, 88 });//prep
mediumKick.PushBack({ 0, 915, 102, 88 });//prep
mediumKick.PushBack({ 782, 1004, 107, 91 });//idle  1
mediumKick.speed = 1.0f;

heavyKick.PushBack({ 782, 1004, 107, 91 });//idle  3
heavyKick.PushBack({ 782, 1004, 107, 91 });//idle
heavyKick.PushBack({ 782, 1004, 107, 91 });//idle
heavyKick.PushBack({ 0, 915, 102, 88 });//prep  3
heavyKick.PushBack({ 0, 915, 102, 88 });//prep
heavyKick.PushBack({ 0, 915, 102, 88 });//prep
heavyKick.PushBack({ 122, 1004, 78, 89 });//kick  3
heavyKick.PushBack({ 122, 1004, 78, 89 });//kick
heavyKick.PushBack({ 122, 1004, 78, 89 });//kick
heavyKick.PushBack({ 722, 493, 134, 80 });//dmg  6
heavyKick.PushBack({ 722, 493, 134, 80 });//dmg
heavyKick.PushBack({ 722, 493, 134, 80 });//dmg
heavyKick.PushBack({ 722, 493, 134, 80 });//dmg
heavyKick.PushBack({ 722, 493, 134, 80 });//dmg
heavyKick.PushBack({ 722, 493, 134, 80 });//dmg
heavyKick.PushBack({ 122, 1004, 78, 89 });//kick  8
heavyKick.PushBack({ 122, 1004, 78, 89 });//kick
heavyKick.PushBack({ 122, 1004, 78, 89 });//kick
heavyKick.PushBack({ 122, 1004, 78, 89 });//kick
heavyKick.PushBack({ 122, 1004, 78, 89 });//kick
heavyKick.PushBack({ 122, 1004, 78, 89 });//kick
heavyKick.PushBack({ 122, 1004, 78, 89 });//kick
heavyKick.PushBack({ 122, 1004, 78, 89 });//kick
heavyKick.PushBack({ 0, 915, 102, 88 });//prep  10
heavyKick.PushBack({ 0, 915, 102, 88 });//prep
heavyKick.PushBack({ 0, 915, 102, 88 });//prep
heavyKick.PushBack({ 0, 915, 102, 88 });//prep
heavyKick.PushBack({ 0, 915, 102, 88 });//prep
heavyKick.PushBack({ 0, 915, 102, 88 });//prep
heavyKick.PushBack({ 0, 915, 102, 88 });//prep
heavyKick.PushBack({ 0, 915, 102, 88 });//prep
heavyKick.PushBack({ 0, 915, 102, 88 });//prep
heavyKick.PushBack({ 0, 915, 102, 88 });//prep
heavyKick.PushBack({ 782, 1004, 107, 91 });//idle  1
heavyKick.speed = 1.0f;

//close kick animations
closeLightKick.PushBack({ 782, 1004, 107, 91 });//idle  3
closeLightKick.PushBack({ 782, 1004, 107, 91 });//idle
closeLightKick.PushBack({ 782, 1004, 107, 91 });//idle
closeLightKick.PushBack({ 898, 1095, 116, 92 });//kick  3
closeLightKick.PushBack({ 898, 1095, 116, 92 });//kick
closeLightKick.PushBack({ 898, 1095, 116, 92 });//kick
closeLightKick.PushBack({ 0, 493, 155, 78 });//dmg  3
closeLightKick.PushBack({ 0, 493, 155, 78 });//dmg
closeLightKick.PushBack({ 0, 493, 155, 78 });//dmg
closeLightKick.PushBack({ 898, 1095, 116, 92 });//kick  3
closeLightKick.PushBack({ 898, 1095, 116, 92 });//kick
closeLightKick.PushBack({ 898, 1095, 116, 92 });//kick
closeLightKick.PushBack({ 782, 1004, 107, 91 });//idle  1
closeLightKick.speed = 1.0f;

closeMediumKick.PushBack({ 782, 1004, 107, 91 });//idle  3
closeMediumKick.PushBack({ 782, 1004, 107, 91 });//idle
closeMediumKick.PushBack({ 782, 1004, 107, 91 });//idle
closeMediumKick.PushBack({ 898, 1095, 116, 92 });//kick  3
closeMediumKick.PushBack({ 898, 1095, 116, 92 });//kick
closeMediumKick.PushBack({ 898, 1095, 116, 92 });//kick
closeMediumKick.PushBack({ 0, 493, 155, 78 });//dmg  5
closeMediumKick.PushBack({ 0, 493, 155, 78 });//dmg
closeMediumKick.PushBack({ 0, 493, 155, 78 });//dmg
closeMediumKick.PushBack({ 0, 493, 155, 78 });//dmg
closeMediumKick.PushBack({ 0, 493, 155, 78 });//dmg
closeMediumKick.PushBack({ 898, 1095, 116, 92 });//kick  7
closeMediumKick.PushBack({ 898, 1095, 116, 92 });//kick
closeMediumKick.PushBack({ 898, 1095, 116, 92 });//kick
closeMediumKick.PushBack({ 898, 1095, 116, 92 });//kick
closeMediumKick.PushBack({ 898, 1095, 116, 92 });//kick
closeMediumKick.PushBack({ 898, 1095, 116, 92 });//kick
closeMediumKick.PushBack({ 898, 1095, 116, 92 });//kick
closeMediumKick.PushBack({ 782, 1004, 107, 91 });//idle  1
closeMediumKick.speed = 1.0f;

closeHeavyKick.PushBack({ 782, 1004, 107, 91 });//idle  2
closeHeavyKick.PushBack({ 782, 1004, 107, 91 });//idle
closeHeavyKick.PushBack({ 0, 915, 102, 88 });//prep  2
closeHeavyKick.PushBack({ 0, 915, 102, 88 });//prep
closeHeavyKick.PushBack({ 122, 1004, 78, 89 });//kick  3
closeHeavyKick.PushBack({ 122, 1004, 78, 89 });//kick
closeHeavyKick.PushBack({ 122, 1004, 78, 89 });//kick
closeHeavyKick.PushBack({ 427, 1478, 100, 104 });//dmg1  3
closeHeavyKick.PushBack({ 427, 1478, 100, 104 });//dmg1
closeHeavyKick.PushBack({ 427, 1478, 100, 104 });//dmg1
closeHeavyKick.PushBack({ 814, 1478, 141, 105 });//dmg2  5
closeHeavyKick.PushBack({ 814, 1478, 141, 105 });//dmg2
closeHeavyKick.PushBack({ 814, 1478, 141, 105 });//dmg2
closeHeavyKick.PushBack({ 814, 1478, 141, 105 });//dmg2
closeHeavyKick.PushBack({ 814, 1478, 141, 105 });//dmg2
closeHeavyKick.PushBack({ 427, 1478, 100, 104 });//dmg1  8
closeHeavyKick.PushBack({ 427, 1478, 100, 104 });//dmg1
closeHeavyKick.PushBack({ 427, 1478, 100, 104 });//dmg1
closeHeavyKick.PushBack({ 427, 1478, 100, 104 });//dmg1
closeHeavyKick.PushBack({ 427, 1478, 100, 104 });//dmg1
closeHeavyKick.PushBack({ 427, 1478, 100, 104 });//dmg1
closeHeavyKick.PushBack({ 427, 1478, 100, 104 });//dmg1
closeHeavyKick.PushBack({ 427, 1478, 100, 104 });//dmg1
closeHeavyKick.PushBack({ 122, 1004, 78, 89 });//kick  6
closeHeavyKick.PushBack({ 122, 1004, 78, 89 });//kick
closeHeavyKick.PushBack({ 122, 1004, 78, 89 });//kick
closeHeavyKick.PushBack({ 122, 1004, 78, 89 });//kick
closeHeavyKick.PushBack({ 122, 1004, 78, 89 });//kick
closeHeavyKick.PushBack({ 122, 1004, 78, 89 });//kick
closeHeavyKick.PushBack({ 0, 915, 102, 88 });//prep  3
closeHeavyKick.PushBack({ 0, 915, 102, 88 });//prep
closeHeavyKick.PushBack({ 0, 915, 102, 88 });//prep
closeHeavyKick.PushBack({ 782, 1004, 107, 91 });//idle  1
closeHeavyKick.speed = 1.0f;

//crouching light punch animation
crouchLightPunch.PushBack({ 438, 196, 94, 70 });//idleCrouch  2
crouchLightPunch.PushBack({ 438, 196, 94, 70 });//idleCrouch
crouchLightPunch.PushBack({ 408, 126, 135, 69 });//prep  2
crouchLightPunch.PushBack({ 408, 126, 135, 69 });//prep
crouchLightPunch.PushBack({ 352, 59, 154, 66 });//dmg  8
crouchLightPunch.PushBack({ 352, 59, 154, 66 });//dmg
crouchLightPunch.PushBack({ 352, 59, 154, 66 });//dmg
crouchLightPunch.PushBack({ 352, 59, 154, 66 });//dmg
crouchLightPunch.PushBack({ 352, 59, 154, 66 });//dmg
crouchLightPunch.PushBack({ 352, 59, 154, 66 });//dmg
crouchLightPunch.PushBack({ 352, 59, 154, 66 });//dmg
crouchLightPunch.PushBack({ 352, 59, 154, 66 });//dmg
crouchLightPunch.PushBack({ 408, 126, 135, 69 });//prep  2
crouchLightPunch.PushBack({ 408, 126, 135, 69 });//prep
crouchLightPunch.PushBack({ 438, 196, 94, 70 });//idleCrouch  1
crouchLightPunch.speed = 1.0f;

//crouch medium punch
crouchMediumPunch.PushBack({ 438, 196, 94, 70 });//idleCrouch  2
crouchMediumPunch.PushBack({ 438, 196, 94, 70 });//idleCrouch
crouchMediumPunch.PushBack({ 0, 126, 99, 69 });//prep  2
crouchMediumPunch.PushBack({ 0, 126, 99, 69 });//prep
crouchMediumPunch.PushBack({ 633, 59, 128, 67 });//punch  2
crouchMediumPunch.PushBack({ 633, 59, 128, 67 });//punch
crouchMediumPunch.PushBack({ 289, 196, 149, 70 });//dmg  8
crouchMediumPunch.PushBack({ 289, 196, 149, 70 });//dmg
crouchMediumPunch.PushBack({ 289, 196, 149, 70 });//dmg
crouchMediumPunch.PushBack({ 289, 196, 149, 70 });//dmg
crouchMediumPunch.PushBack({ 289, 196, 149, 70 });//dmg
crouchMediumPunch.PushBack({ 289, 196, 149, 70 });//dmg
crouchMediumPunch.PushBack({ 289, 196, 149, 70 });//dmg
crouchMediumPunch.PushBack({ 289, 196, 149, 70 });//dmg
crouchMediumPunch.PushBack({ 633, 59, 128, 67 });//punch  6
crouchMediumPunch.PushBack({ 633, 59, 128, 67 });//punch  
crouchMediumPunch.PushBack({ 633, 59, 128, 67 });//punch  
crouchMediumPunch.PushBack({ 633, 59, 128, 67 });//punch
crouchMediumPunch.PushBack({ 633, 59, 128, 67 });//punch
crouchMediumPunch.PushBack({ 633, 59, 128, 67 });//punch
crouchMediumPunch.PushBack({ 0, 126, 99, 69 });//prep  4
crouchMediumPunch.PushBack({ 0, 126, 99, 69 });//prep  
crouchMediumPunch.PushBack({ 0, 126, 99, 69 });//prep
crouchMediumPunch.PushBack({ 0, 126, 99, 69 });//prep
crouchMediumPunch.PushBack({ 438, 196, 94, 70 });//idleCrouch  1
crouchMediumPunch.speed = 1.0f;

//crouch heavy punch

crouchHeavyPunch.PushBack({ 438, 196, 94, 70 });//idleCrouch  2
crouchHeavyPunch.PushBack({ 438, 196, 94, 70 });//idleCrouch
crouchHeavyPunch.PushBack({ 109, 340, 123, 74 });//prep  3
crouchHeavyPunch.PushBack({ 109, 340, 123, 74 });//prep
crouchHeavyPunch.PushBack({ 109, 340, 123, 74 });//prep
crouchHeavyPunch.PushBack({ 761, 59, 155, 67 });//dmg  4
crouchHeavyPunch.PushBack({ 761, 59, 155, 67 });//dmg
crouchHeavyPunch.PushBack({ 761, 59, 155, 67 });//dmg
crouchHeavyPunch.PushBack({ 761, 59, 155, 67 });//dmg
crouchHeavyPunch.PushBack({ 506, 59, 127, 66 });//recover  6
crouchHeavyPunch.PushBack({ 506, 59, 127, 66 });//recover
crouchHeavyPunch.PushBack({ 506, 59, 127, 66 });//recover
crouchHeavyPunch.PushBack({ 506, 59, 127, 66 });//recover
crouchHeavyPunch.PushBack({ 506, 59, 127, 66 });//recover
crouchHeavyPunch.PushBack({ 506, 59, 127, 66 });//recover
crouchHeavyPunch.PushBack({ 0, 267, 127, 72 });//recover2  8
crouchHeavyPunch.PushBack({ 0, 267, 127, 72 });//recover2
crouchHeavyPunch.PushBack({ 0, 267, 127, 72 });//recover2
crouchHeavyPunch.PushBack({ 0, 267, 127, 72 });//recover2
crouchHeavyPunch.PushBack({ 0, 267, 127, 72 });//recover2
crouchHeavyPunch.PushBack({ 0, 267, 127, 72 });//recover2
crouchHeavyPunch.PushBack({ 0, 267, 127, 72 });//recover2
crouchHeavyPunch.PushBack({ 0, 267, 127, 72 });//recover2
crouchHeavyPunch.PushBack({ 506, 59, 127, 66 });//recover3  6
crouchHeavyPunch.PushBack({ 506, 59, 127, 66 });//recover3
crouchHeavyPunch.PushBack({ 506, 59, 127, 66 });//recover3
crouchHeavyPunch.PushBack({ 506, 59, 127, 66 });//recover3
crouchHeavyPunch.PushBack({ 506, 59, 127, 66 });//recover3
crouchHeavyPunch.PushBack({ 506, 59, 127, 66 });//recover3
crouchHeavyPunch.PushBack({ 761, 59, 155, 67 });//recover4  4
crouchHeavyPunch.PushBack({ 761, 59, 155, 67 });//recover4
crouchHeavyPunch.PushBack({ 761, 59, 155, 67 });//recover4
crouchHeavyPunch.PushBack({ 761, 59, 155, 67 });//recover4
crouchHeavyPunch.PushBack({ 109, 340, 123, 74 });//prep  3
crouchHeavyPunch.PushBack({ 109, 340, 123, 74 });//prep
crouchHeavyPunch.PushBack({ 109, 340, 123, 74 });//prep
crouchHeavyPunch.PushBack({ 438, 196, 94, 70 });//idleCrouch  1
crouchHeavyPunch.speed = 1.0f;

//crouch light kick

crouchLightKick.PushBack({ 438, 196, 94, 70 });//idleCrouch  3
crouchLightKick.PushBack({ 438, 196, 94, 70 });//idleCrouch
crouchLightKick.PushBack({ 438, 196, 94, 70 });//idleCrouch
crouchLightKick.PushBack({ 232, 340, 108, 74 });//prep 3
crouchLightKick.PushBack({ 232, 340, 108, 74 });//prep
crouchLightKick.PushBack({ 232, 340, 108, 74 });//prep
crouchLightKick.PushBack({ 359, 267, 118, 72 });//kick 3
crouchLightKick.PushBack({ 359, 267, 118, 72 });//kick
crouchLightKick.PushBack({ 359, 267, 118, 72 });//kick
crouchLightKick.PushBack({ 626, 196, 146, 71 });//dmg  3
crouchLightKick.PushBack({ 626, 196, 146, 71 });//dmg
crouchLightKick.PushBack({ 626, 196, 146, 71 });//dmg
crouchLightKick.PushBack({ 359, 267, 118, 72 });//kick 3
crouchLightKick.PushBack({ 359, 267, 118, 72 });//kick
crouchLightKick.PushBack({ 359, 267, 118, 72 });//kick
crouchLightKick.PushBack({ 232, 340, 108, 74 });//prep 3
crouchLightKick.PushBack({ 232, 340, 108, 74 });//prep
crouchLightKick.PushBack({ 232, 340, 108, 74 });//prep
crouchLightKick.PushBack({ 438, 196, 94, 70 });//idleCrouch  1
crouchLightKick.speed = 1.0f;

//crouch medium kick
crouchMediumKick.PushBack({ 438, 196, 94, 70 });//idleCrouch  3
crouchMediumKick.PushBack({ 438, 196, 94, 70 });//idleCrouch
crouchMediumKick.PushBack({ 438, 196, 94, 70 });//idleCrouch
crouchMediumKick.PushBack({ 232, 340, 108, 74 });//prep 3
crouchMediumKick.PushBack({ 232, 340, 108, 74 });//prep
crouchMediumKick.PushBack({ 232, 340, 108, 74 });//prep
crouchMediumKick.PushBack({ 359, 267, 118, 72 });//dmg1 3
crouchMediumKick.PushBack({ 359, 267, 118, 72 });//dmg1
crouchMediumKick.PushBack({ 359, 267, 118, 72 });//dmg1
crouchMediumKick.PushBack({ 626, 196, 146, 71 });//dmg2  6
crouchMediumKick.PushBack({ 626, 196, 146, 71 });//dmg2
crouchMediumKick.PushBack({ 626, 196, 146, 71 });//dmg2
crouchMediumKick.PushBack({ 626, 196, 146, 71 });//dmg2
crouchMediumKick.PushBack({ 626, 196, 146, 71 });//dmg2
crouchMediumKick.PushBack({ 626, 196, 146, 71 });//dmg2
crouchMediumKick.PushBack({ 359, 267, 118, 72 });//kick 5
crouchMediumKick.PushBack({ 359, 267, 118, 72 });//kick
crouchMediumKick.PushBack({ 359, 267, 118, 72 });//kick
crouchMediumKick.PushBack({ 359, 267, 118, 72 });//kick
crouchMediumKick.PushBack({ 359, 267, 118, 72 });//kick
crouchMediumKick.PushBack({ 232, 340, 108, 74 });//prep 4
crouchMediumKick.PushBack({ 232, 340, 108, 74 });//prep
crouchMediumKick.PushBack({ 232, 340, 108, 74 });//prep
crouchMediumKick.PushBack({ 232, 340, 108, 74 });//prep
crouchMediumKick.PushBack({ 438, 196, 94, 70 });//idleCrouch  1
crouchMediumKick.speed = 1.0f;

// crouch heavy kick
crouchHeavyKick.PushBack({ 438, 196, 94, 70 });//idleCrouch  3
crouchHeavyKick.PushBack({ 438, 196, 94, 70 });//idleCrouch
crouchHeavyKick.PushBack({ 438, 196, 94, 70 });//idleCrouch
crouchHeavyKick.PushBack({ 0, 340, 109, 74 });//prep  4
crouchHeavyKick.PushBack({ 0, 340, 109, 74 });//prep
crouchHeavyKick.PushBack({ 0, 340, 109, 74 });//prep
crouchHeavyKick.PushBack({ 0, 340, 109, 74 });//prep
crouchHeavyKick.PushBack({ 625, 416, 140, 77 });//dmg1  6
crouchHeavyKick.PushBack({ 625, 416, 140, 77 });//dmg1
crouchHeavyKick.PushBack({ 625, 416, 140, 77 });//dmg1
crouchHeavyKick.PushBack({ 625, 416, 140, 77 });//dmg1
crouchHeavyKick.PushBack({ 625, 416, 140, 77 });//dmg1
crouchHeavyKick.PushBack({ 625, 416, 140, 77 });//dmg1
crouchHeavyKick.PushBack({ 772, 340, 82, 75 });//spin  4
crouchHeavyKick.PushBack({ 772, 340, 82, 75 });//spin
crouchHeavyKick.PushBack({ 772, 340, 82, 75 });//spin
crouchHeavyKick.PushBack({ 772, 340, 82, 75 });//spin
crouchHeavyKick.PushBack({ 299, 126, 109, 69 });//dmg2  8
crouchHeavyKick.PushBack({ 299, 126, 109, 69 });//dmg2
crouchHeavyKick.PushBack({ 299, 126, 109, 69 });//dmg2
crouchHeavyKick.PushBack({ 299, 126, 109, 69 });//dmg2
crouchHeavyKick.PushBack({ 299, 126, 109, 69 });//dmg2
crouchHeavyKick.PushBack({ 299, 126, 109, 69 });//dmg2
crouchHeavyKick.PushBack({ 299, 126, 109, 69 });//dmg2
crouchHeavyKick.PushBack({ 299, 126, 109, 69 });//dmg2
crouchHeavyKick.PushBack({ 895, 267, 93, 73 });//recover 6
crouchHeavyKick.PushBack({ 895, 267, 93, 73 });//recover
crouchHeavyKick.PushBack({ 895, 267, 93, 73 });//recover
crouchHeavyKick.PushBack({ 895, 267, 93, 73 });//recover
crouchHeavyKick.PushBack({ 895, 267, 93, 73 });//recover
crouchHeavyKick.PushBack({ 895, 267, 93, 73 });//recover
crouchHeavyKick.PushBack({ 438, 196, 94, 70 });//idleCrouch  1
crouchHeavyKick.speed = 1.0f;

//jump attacks
jumpLightPunch.PushBack({ 655, 1694, 77, 130 });//jumping  3
jumpLightPunch.PushBack({ 655, 1694, 77, 130 });//jumping
jumpLightPunch.PushBack({ 655, 1694, 77, 130 });//jumping
jumpLightPunch.PushBack({ 410, 1694, 116, 123 });//prep  4
jumpLightPunch.PushBack({ 410, 1694, 116, 123 });//prep
jumpLightPunch.PushBack({ 410, 1694, 116, 123 });//prep
jumpLightPunch.PushBack({ 410, 1694, 116, 123 });//prep
jumpLightPunch.PushBack({ 0, 1694, 115, 114 });//punch  4
jumpLightPunch.PushBack({ 0, 1694, 115, 114 });//punch
jumpLightPunch.PushBack({ 0, 1694, 115, 114 });//punch
jumpLightPunch.PushBack({ 0, 1694, 115, 114 });//punch
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg  30
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 173, 1478, 147, 101 });//dmg
jumpLightPunch.PushBack({ 316, 1583, 106, 105 });//recover, until ground
jumpLightPunch.speed = 0.1f;

jumpMediumPunch.PushBack({ 655, 1694, 77, 130 });//jumping  3
jumpMediumPunch.PushBack({ 655, 1694, 77, 130 });//jumping
jumpMediumPunch.PushBack({ 655, 1694, 77, 130 });//jumping
jumpMediumPunch.PushBack({ 410, 1694, 116, 123 });//prep  4
jumpMediumPunch.PushBack({ 410, 1694, 116, 123 });//prep
jumpMediumPunch.PushBack({ 410, 1694, 116, 123 });//prep
jumpMediumPunch.PushBack({ 410, 1694, 116, 123 });//prep
jumpMediumPunch.PushBack({ 0, 1694, 115, 114 });//dmg1  4
jumpMediumPunch.PushBack({ 0, 1694, 115, 114 });//dmg1
jumpMediumPunch.PushBack({ 0, 1694, 115, 114 });//dmg1
jumpMediumPunch.PushBack({ 0, 1694, 115, 114 });//dmg1
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//dmg2  12
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//dmg2
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//dmg2
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//dmg2
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//dmg2
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//dmg2
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//dmg2
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//dmg2
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//dmg2
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//dmg2
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//dmg2
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//dmg2
jumpMediumPunch.PushBack({ 316, 1583, 106, 105 });//recover  8
jumpMediumPunch.PushBack({ 316, 1583, 106, 105 });//recover
jumpMediumPunch.PushBack({ 316, 1583, 106, 105 });//recover
jumpMediumPunch.PushBack({ 316, 1583, 106, 105 });//recover
jumpMediumPunch.PushBack({ 316, 1583, 106, 105 });//recover
jumpMediumPunch.PushBack({ 316, 1583, 106, 105 });//recover
jumpMediumPunch.PushBack({ 316, 1583, 106, 105 });//recover
jumpMediumPunch.PushBack({ 316, 1583, 106, 105 });//recover
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//recover  4
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//recover
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//recover
jumpMediumPunch.PushBack({ 173, 1478, 147, 101 });//recover
jumpMediumPunch.PushBack({ 0, 1694, 115, 114 });//recover  4
jumpMediumPunch.PushBack({ 0, 1694, 115, 114 });//recover
jumpMediumPunch.PushBack({ 0, 1694, 115, 114 });//recover
jumpMediumPunch.PushBack({ 0, 1694, 115, 114 });//recover
jumpMediumPunch.PushBack({ 410, 1694, 116, 123 });//prep, until ground
jumpMediumPunch.speed = 0.1f;

jumpHeavyPunch.PushBack({ 655, 1694, 77, 130 });//jumping  3
jumpHeavyPunch.PushBack({ 655, 1694, 77, 130 });//jumping
jumpHeavyPunch.PushBack({ 655, 1694, 77, 130 });//jumping
jumpHeavyPunch.PushBack({ 398, 1187, 90, 92 });//prep  4
jumpHeavyPunch.PushBack({ 398, 1187, 90, 92 });//prep
jumpHeavyPunch.PushBack({ 398, 1187, 90, 92 });//prep
jumpHeavyPunch.PushBack({ 398, 1187, 90, 92 });//prep
jumpHeavyPunch.PushBack({ 705, 1281, 139, 95 });//dmg  6
jumpHeavyPunch.PushBack({ 705, 1281, 139, 95 });//dmg
jumpHeavyPunch.PushBack({ 705, 1281, 139, 95 });//dmg
jumpHeavyPunch.PushBack({ 705, 1281, 139, 95 });//dmg
jumpHeavyPunch.PushBack({ 705, 1281, 139, 95 });//dmg
jumpHeavyPunch.PushBack({ 705, 1281, 139, 95 });//dmg
jumpHeavyPunch.PushBack({ 384, 1378, 132, 99 });//recover  8
jumpHeavyPunch.PushBack({ 384, 1378, 132, 99 });//recover
jumpHeavyPunch.PushBack({ 384, 1378, 132, 99 });//recover
jumpHeavyPunch.PushBack({ 384, 1378, 132, 99 });//recover
jumpHeavyPunch.PushBack({ 384, 1378, 132, 99 });//recover
jumpHeavyPunch.PushBack({ 384, 1378, 132, 99 });//recover
jumpHeavyPunch.PushBack({ 384, 1378, 132, 99 });//recover
jumpHeavyPunch.PushBack({ 384, 1378, 132, 99 });//recover
jumpHeavyPunch.PushBack({ 705, 1281, 139, 95 });//recover  4
jumpHeavyPunch.PushBack({ 705, 1281, 139, 95 });//recover
jumpHeavyPunch.PushBack({ 705, 1281, 139, 95 });//recover
jumpHeavyPunch.PushBack({ 705, 1281, 139, 95 });//recover
jumpHeavyPunch.PushBack({ 398, 1187, 90, 92 });//recover  4
jumpHeavyPunch.PushBack({ 398, 1187, 90, 92 });//recover
jumpHeavyPunch.PushBack({ 398, 1187, 90, 92 });//recover
jumpHeavyPunch.PushBack({ 398, 1187, 90, 92 });//recover
jumpHeavyPunch.PushBack({ 655, 1694, 77, 130 });//jumping, until ground
jumpHeavyPunch.speed = 1.0f;

jumpLightKick.PushBack({ 204, 126, 95, 69 });//prep  3
jumpLightKick.PushBack({ 204, 126, 95, 69 });//prep
jumpLightKick.PushBack({ 204, 126, 95, 69 });//prep
jumpLightKick.PushBack({ 416, 416, 103, 76 });//kick  4
jumpLightKick.PushBack({ 416, 416, 103, 76 });//kick
jumpLightKick.PushBack({ 416, 416, 103, 76 });//kick
jumpLightKick.PushBack({ 416, 416, 103, 76 });//kick
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg  30
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpLightKick.PushBack({ 204, 126, 103, 76 });//kick  4
jumpLightKick.PushBack({ 204, 126, 103, 76 });//kick
jumpLightKick.PushBack({ 204, 126, 103, 76 });//kick
jumpLightKick.PushBack({ 204, 126, 103, 76 });//kick
jumpLightKick.PushBack({ 204, 126, 95, 69 });//prep, until ground
jumpLightKick.speed = 1.0f;

jumpMediumKick.PushBack({ 204, 126, 95, 69 });//prep  3
jumpMediumKick.PushBack({ 204, 126, 95, 69 });//prep
jumpMediumKick.PushBack({ 204, 126, 95, 69 });//prep
jumpMediumKick.PushBack({ 416, 416, 103, 76 });//kick  4
jumpMediumKick.PushBack({ 416, 416, 103, 76 });//kick
jumpMediumKick.PushBack({ 416, 416, 103, 76 });//kick
jumpMediumKick.PushBack({ 416, 416, 103, 76 });//kick
jumpMediumKick.PushBack({ 479, 493, 148, 80 });//dmg  12
jumpMediumKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpMediumKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpMediumKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpMediumKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpMediumKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpMediumKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpMediumKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpMediumKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpMediumKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpMediumKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpMediumKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpMediumKick.PushBack({ 204, 126, 103, 76 });//recover  4
jumpMediumKick.PushBack({ 204, 126, 103, 76 });//recover
jumpMediumKick.PushBack({ 204, 126, 103, 76 });//recover
jumpMediumKick.PushBack({ 204, 126, 103, 76 });//recover
jumpMediumKick.PushBack({ 204, 126, 95, 69 });//recover  4
jumpMediumKick.PushBack({ 204, 126, 95, 69 });//recover
jumpMediumKick.PushBack({ 204, 126, 95, 69 });//recover
jumpMediumKick.PushBack({ 204, 126, 95, 69 });//recover
jumpMediumKick.PushBack({ 258, 59, 94, 65 });//jumping  4
jumpMediumKick.PushBack({ 258, 59, 94, 65 });//jumping
jumpMediumKick.PushBack({ 258, 59, 94, 65 });//jumping
jumpMediumKick.PushBack({ 258, 59, 94, 65 });//jumping
jumpMediumKick.PushBack({ 410, 1281, 97, 94 });//falling  4
jumpMediumKick.PushBack({ 410, 1281, 97, 94 });//falling
jumpMediumKick.PushBack({ 410, 1281, 97, 94 });//falling
jumpMediumKick.PushBack({ 410, 1281, 97, 94 });//falling
jumpMediumKick.PushBack({ 655, 1694, 77, 130 });//jumping, until ground
jumpMediumKick.speed = 1.0f;

jumpHeavyKick.PushBack({ 204, 126, 95, 69 });//prep  2
jumpHeavyKick.PushBack({ 204, 126, 95, 69 });//prep
jumpHeavyKick.PushBack({ 416, 416, 103, 76 });//kick  4
jumpHeavyKick.PushBack({ 416, 416, 103, 76 });//kick
jumpHeavyKick.PushBack({ 416, 416, 103, 76 });//kick
jumpHeavyKick.PushBack({ 416, 416, 103, 76 });//kick
jumpHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg  6
jumpHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpHeavyKick.PushBack({ 204, 126, 103, 76 });//recover  4
jumpHeavyKick.PushBack({ 204, 126, 103, 76 });//recover
jumpHeavyKick.PushBack({ 204, 126, 103, 76 });//recover
jumpHeavyKick.PushBack({ 204, 126, 103, 76 });//recover
jumpHeavyKick.PushBack({ 204, 126, 95, 69 });//recover  4
jumpHeavyKick.PushBack({ 204, 126, 95, 69 });//recover
jumpHeavyKick.PushBack({ 204, 126, 95, 69 });//recover
jumpHeavyKick.PushBack({ 204, 126, 95, 69 });//recover
jumpHeavyKick.PushBack({ 258, 59, 94, 65 });//jumping  4
jumpHeavyKick.PushBack({ 258, 59, 94, 65 });//jumping
jumpHeavyKick.PushBack({ 258, 59, 94, 65 });//jumping
jumpHeavyKick.PushBack({ 258, 59, 94, 65 });//jumping
jumpHeavyKick.PushBack({ 410, 1281, 97, 94 });//falling  4
jumpHeavyKick.PushBack({ 410, 1281, 97, 94 });//falling
jumpHeavyKick.PushBack({ 410, 1281, 97, 94 });//falling
jumpHeavyKick.PushBack({ 410, 1281, 97, 94 });//falling
jumpHeavyKick.PushBack({ 655, 1694, 77, 130 });//jumping, until ground
jumpHeavyKick.speed = 1.0f;

jumpDiagonalLightKick.PushBack({ 547, 1583, 125, 108 });//falling  3
jumpDiagonalLightKick.PushBack({ 547, 1583, 125, 108 });//falling
jumpDiagonalLightKick.PushBack({ 547, 1583, 125, 108 });//falling
jumpDiagonalLightKick.PushBack({ 243, 267, 116, 72 });//prep  4
jumpDiagonalLightKick.PushBack({ 243, 267, 116, 72 });//prep
jumpDiagonalLightKick.PushBack({ 243, 267, 116, 72 });//prep
jumpDiagonalLightKick.PushBack({ 243, 267, 116, 72 });//prep
jumpDiagonalLightKick.PushBack({ 678, 0, 98, 56 });//dmg, until ground
jumpDiagonalLightKick.speed = 1.0f;

jumpDiagonalMediumKick.PushBack({ 208, 416, 112, 76 });//prep  3
jumpDiagonalMediumKick.PushBack({ 208, 416, 112, 76 });//prep
jumpDiagonalMediumKick.PushBack({ 208, 416, 112, 76 });//prep
jumpDiagonalMediumKick.PushBack({ 129, 59, 129, 64 });//prep2  4
jumpDiagonalMediumKick.PushBack({ 129, 59, 129, 64 });//prep2
jumpDiagonalMediumKick.PushBack({ 129, 59, 129, 64 });//prep2
jumpDiagonalMediumKick.PushBack({ 129, 59, 129, 64 });//prep2
jumpDiagonalMediumKick.PushBack({ 740, 267, 155, 73 });//dmg, until ground
jumpDiagonalMediumKick.speed = 1.0f;

jumpDiagonalHeavyKick.PushBack({ 204, 126, 95, 69 });//prep  3
jumpDiagonalHeavyKick.PushBack({ 204, 126, 95, 69 });//prep
jumpDiagonalHeavyKick.PushBack({ 204, 126, 95, 69 });//prep
jumpDiagonalHeavyKick.PushBack({ 204, 126, 103, 76 });//kick  4
jumpDiagonalHeavyKick.PushBack({ 204, 126, 103, 76 });//kick
jumpDiagonalHeavyKick.PushBack({ 204, 126, 103, 76 });//kick
jumpDiagonalHeavyKick.PushBack({ 204, 126, 103, 76 });//kick
jumpDiagonalHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg  12
jumpDiagonalHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpDiagonalHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpDiagonalHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpDiagonalHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpDiagonalHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpDiagonalHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpDiagonalHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpDiagonalHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpDiagonalHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpDiagonalHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpDiagonalHeavyKick.PushBack({ 479, 493, 148, 80 });//dmg
jumpDiagonalHeavyKick.PushBack({ 204, 126, 103, 76 });//recover  4
jumpDiagonalHeavyKick.PushBack({ 204, 126, 103, 76 });//recover
jumpDiagonalHeavyKick.PushBack({ 204, 126, 103, 76 });//recover
jumpDiagonalHeavyKick.PushBack({ 204, 126, 103, 76 });//recover
jumpDiagonalHeavyKick.PushBack({ 204, 126, 95, 69 });//recover  4
jumpDiagonalHeavyKick.PushBack({ 204, 126, 95, 69 });//recover
jumpDiagonalHeavyKick.PushBack({ 204, 126, 95, 69 });//recover
jumpDiagonalHeavyKick.PushBack({ 204, 126, 95, 69 });//recover
jumpDiagonalHeavyKick.PushBack({ 258, 59, 94, 65 });//jumping  4
jumpDiagonalHeavyKick.PushBack({ 258, 59, 94, 65 });//jumping
jumpDiagonalHeavyKick.PushBack({ 258, 59, 94, 65 });//jumping
jumpDiagonalHeavyKick.PushBack({ 258, 59, 94, 65 });//jumping
jumpDiagonalHeavyKick.PushBack({ 410, 1281, 97, 94 });//falling  4
jumpDiagonalHeavyKick.PushBack({ 410, 1281, 97, 94 });//falling
jumpDiagonalHeavyKick.PushBack({ 410, 1281, 97, 94 });//falling
jumpDiagonalHeavyKick.PushBack({ 410, 1281, 97, 94 });//falling
jumpDiagonalHeavyKick.PushBack({ 655, 1694, 77, 130 });//jumping, until ground
jumpDiagonalHeavyKick.speed = 1.0f;

//double knee
DoubleKnee.PushBack({ 782, 1004, 107, 91 });//idle  3
DoubleKnee.PushBack({ 782, 1004, 107, 91 });//idle
DoubleKnee.PushBack({ 782, 1004, 107, 91 });//idle
DoubleKnee.PushBack({ 0, 915, 102, 88 });//prep  3
DoubleKnee.PushBack({ 0, 915, 102, 88 });//prep
DoubleKnee.PushBack({ 0, 915, 102, 88 });//prep
DoubleKnee.PushBack({ 122, 1004, 78, 89 });//kick  3
DoubleKnee.PushBack({ 122, 1004, 78, 89 });//kick
DoubleKnee.PushBack({ 122, 1004, 78, 89 });//kick
DoubleKnee.PushBack({ 731, 1478, 83, 104 });//dmg1  3
DoubleKnee.PushBack({ 731, 1478, 83, 104 });//dmg1
DoubleKnee.PushBack({ 731, 1478, 83, 104 });//dmg1
DoubleKnee.PushBack({ 208, 1583, 108, 105 });//dmg2  3
DoubleKnee.PushBack({ 208, 1583, 108, 105 });//dmg2
DoubleKnee.PushBack({ 208, 1583, 108, 105 });//dmg2
DoubleKnee.PushBack({ 731, 1478, 83, 104 });//recover  2
DoubleKnee.PushBack({ 731, 1478, 83, 104 });//recover
DoubleKnee.PushBack({ 122, 1004, 78, 89 });//recover  2
DoubleKnee.PushBack({ 122, 1004, 78, 89 });//recover
DoubleKnee.PushBack({ 0, 915, 102, 88 });//recover  2
DoubleKnee.PushBack({ 0, 915, 102, 88 });//recover
DoubleKnee.PushBack({ 782, 1004, 107, 91 });//recover  1
DoubleKnee.speed = 1.0f;

//sumo headbutt				frame count				light/medium/heavy
/*SumoHeadbutt.PushBack({ 782, 1004, 107, 91 });//idle  3/1/0
SumoHeadbutt.PushBack({ 516, 1378, 98, 99 });//		  4/3/1
SumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//		  6/4/4
SumoHeadbutt.PushBack({ 634, 1478, 97, 104 });//	  3/2/1
SumoHeadbutt.PushBack({ 424, 915, 101, 88 });//dmg	  3/2/1
SumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg		  22/53/63
SumoHeadbutt.PushBack({ 448, 340, 108, 75 });//		  4/4/4
SumoHeadbutt.PushBack({ 398, 493, 81, 79 });//		  4/4/4
SumoHeadbutt.PushBack({ 578, 827, 109, 88 });//		  4/4/4
SumoHeadbutt.PushBack({ 0, 196, 94, 70 });//		  8/8/8
SumoHeadbutt.PushBack({ 0, 416, 96, 76 });//		  2/2/2
SumoHeadbutt.PushBack({ 361, 656, 97, 84 });//		  2/2/2
SumoHeadbutt.PushBack({ 604, 1281, 101, 94 });//	  1/1/1
SumoHeadbutt.speed = 1.0f;*/

LightSumoHeadbutt.PushBack({ 782, 1004, 107, 91 });//idle  3
LightSumoHeadbutt.PushBack({ 782, 1004, 107, 91 });//idle
LightSumoHeadbutt.PushBack({ 782, 1004, 107, 91 });//idle
LightSumoHeadbutt.PushBack({ 516, 1378, 98, 99 });//  4
LightSumoHeadbutt.PushBack({ 516, 1378, 98, 99 });//
LightSumoHeadbutt.PushBack({ 516, 1378, 98, 99 });//
LightSumoHeadbutt.PushBack({ 516, 1378, 98, 99 });//
LightSumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//  6
LightSumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//
LightSumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//
LightSumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//
LightSumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//
LightSumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//
LightSumoHeadbutt.PushBack({ 634, 1478, 97, 104 });//  3
LightSumoHeadbutt.PushBack({ 634, 1478, 97, 104 });//
LightSumoHeadbutt.PushBack({ 634, 1478, 97, 104 });//
LightSumoHeadbutt.PushBack({ 424, 915, 101, 88 });//dmg  3
LightSumoHeadbutt.PushBack({ 424, 915, 101, 88 });//dmg
LightSumoHeadbutt.PushBack({ 424, 915, 101, 88 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg  22
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
LightSumoHeadbutt.PushBack({ 448, 340, 108, 75 });//  4
LightSumoHeadbutt.PushBack({ 448, 340, 108, 75 });//
LightSumoHeadbutt.PushBack({ 448, 340, 108, 75 });//
LightSumoHeadbutt.PushBack({ 448, 340, 108, 75 });//
LightSumoHeadbutt.PushBack({ 398, 493, 81, 79 });//  4
LightSumoHeadbutt.PushBack({ 398, 493, 81, 79 });//
LightSumoHeadbutt.PushBack({ 398, 493, 81, 79 });//
LightSumoHeadbutt.PushBack({ 398, 493, 81, 79 });//
LightSumoHeadbutt.PushBack({ 578, 827, 109, 88 });//  4	  
LightSumoHeadbutt.PushBack({ 578, 827, 109, 88 });
LightSumoHeadbutt.PushBack({ 578, 827, 109, 88 });
LightSumoHeadbutt.PushBack({ 578, 827, 109, 88 });
LightSumoHeadbutt.PushBack({ 0, 196, 94, 70 });//  8
LightSumoHeadbutt.PushBack({ 0, 196, 94, 70 });
LightSumoHeadbutt.PushBack({ 0, 196, 94, 70 });
LightSumoHeadbutt.PushBack({ 0, 196, 94, 70 });
LightSumoHeadbutt.PushBack({ 0, 196, 94, 70 });
LightSumoHeadbutt.PushBack({ 0, 196, 94, 70 });
LightSumoHeadbutt.PushBack({ 0, 196, 94, 70 });
LightSumoHeadbutt.PushBack({ 0, 196, 94, 70 });
LightSumoHeadbutt.PushBack({ 0, 416, 96, 76 });//  2
LightSumoHeadbutt.PushBack({ 0, 416, 96, 76 });//
LightSumoHeadbutt.PushBack({ 361, 656, 97, 84 });//  2
LightSumoHeadbutt.PushBack({ 361, 656, 97, 84 });//
LightSumoHeadbutt.PushBack({ 604, 1281, 101, 94 });//  1
LightSumoHeadbutt.speed = 1.0f;

MediumSumoHeadbutt.PushBack({ 782, 1004, 107, 91 });// 1
MediumSumoHeadbutt.PushBack({ 516, 1378, 98, 99 });//  3
MediumSumoHeadbutt.PushBack({ 516, 1378, 98, 99 });//
MediumSumoHeadbutt.PushBack({ 516, 1378, 98, 99 });//
MediumSumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//  4
MediumSumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//
MediumSumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//
MediumSumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//
MediumSumoHeadbutt.PushBack({ 634, 1478, 97, 104 });//  2
MediumSumoHeadbutt.PushBack({ 634, 1478, 97, 104 });//
MediumSumoHeadbutt.PushBack({ 424, 915, 101, 88 });//dmg  2
MediumSumoHeadbutt.PushBack({ 424, 915, 101, 88 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg  53
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
MediumSumoHeadbutt.PushBack({ 448, 340, 108, 75 });//  4
MediumSumoHeadbutt.PushBack({ 448, 340, 108, 75 });//
MediumSumoHeadbutt.PushBack({ 448, 340, 108, 75 });//
MediumSumoHeadbutt.PushBack({ 448, 340, 108, 75 });//
MediumSumoHeadbutt.PushBack({ 398, 493, 81, 79 });//  4
MediumSumoHeadbutt.PushBack({ 398, 493, 81, 79 });//
MediumSumoHeadbutt.PushBack({ 398, 493, 81, 79 });//
MediumSumoHeadbutt.PushBack({ 398, 493, 81, 79 });//
MediumSumoHeadbutt.PushBack({ 578, 827, 109, 88 });//  4
MediumSumoHeadbutt.PushBack({ 578, 827, 109, 88 });//
MediumSumoHeadbutt.PushBack({ 578, 827, 109, 88 });//
MediumSumoHeadbutt.PushBack({ 578, 827, 109, 88 });//
MediumSumoHeadbutt.PushBack({ 0, 196, 94, 70 });//  8
MediumSumoHeadbutt.PushBack({ 0, 196, 94, 70 });//
MediumSumoHeadbutt.PushBack({ 0, 196, 94, 70 });//
MediumSumoHeadbutt.PushBack({ 0, 196, 94, 70 });//
MediumSumoHeadbutt.PushBack({ 0, 416, 96, 76 });//  2
MediumSumoHeadbutt.PushBack({ 0, 416, 96, 76 });//
MediumSumoHeadbutt.PushBack({ 361, 656, 97, 84 });//  2
MediumSumoHeadbutt.PushBack({ 361, 656, 97, 84 });//
MediumSumoHeadbutt.PushBack({ 604, 1281, 101, 94 });//  1
MediumSumoHeadbutt.speed = 1.0f;

//HeavySumoHeadbutt.PushBack({ 782, 1004, 107, 91 });//idle  0
HeavySumoHeadbutt.PushBack({ 516, 1378, 98, 99 });//  1
HeavySumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//  4
HeavySumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//  
HeavySumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//  
HeavySumoHeadbutt.PushBack({ 0, 1583, 104, 105 });//  
HeavySumoHeadbutt.PushBack({ 634, 1478, 97, 104 });//  1
HeavySumoHeadbutt.PushBack({ 424, 915, 101, 88 });//dmg  1
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg  63
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 0, 0, 135, 41 });//dmg
HeavySumoHeadbutt.PushBack({ 448, 340, 108, 75 });//  4
HeavySumoHeadbutt.PushBack({ 448, 340, 108, 75 });//
HeavySumoHeadbutt.PushBack({ 448, 340, 108, 75 });//
HeavySumoHeadbutt.PushBack({ 448, 340, 108, 75 });//
HeavySumoHeadbutt.PushBack({ 398, 493, 81, 79 });//  4
HeavySumoHeadbutt.PushBack({ 398, 493, 81, 79 });//
HeavySumoHeadbutt.PushBack({ 398, 493, 81, 79 });//
HeavySumoHeadbutt.PushBack({ 398, 493, 81, 79 });//
HeavySumoHeadbutt.PushBack({ 578, 827, 109, 88 });//  4
HeavySumoHeadbutt.PushBack({ 578, 827, 109, 88 });//
HeavySumoHeadbutt.PushBack({ 578, 827, 109, 88 });//
HeavySumoHeadbutt.PushBack({ 578, 827, 109, 88 });//
HeavySumoHeadbutt.PushBack({ 0, 196, 94, 70 });//  8
HeavySumoHeadbutt.PushBack({ 0, 196, 94, 70 });//
HeavySumoHeadbutt.PushBack({ 0, 196, 94, 70 });//
HeavySumoHeadbutt.PushBack({ 0, 196, 94, 70 });//
HeavySumoHeadbutt.PushBack({ 0, 416, 96, 76 });//  2
HeavySumoHeadbutt.PushBack({ 0, 416, 96, 76 });//
HeavySumoHeadbutt.PushBack({ 361, 656, 97, 84 });//  2
HeavySumoHeadbutt.PushBack({ 361, 656, 97, 84 });//
HeavySumoHeadbutt.PushBack({ 604, 1281, 101, 94 });//  1
HeavySumoHeadbutt.speed = 1.0f;

//hundred slaps									frame count light/medium/heavy
/*HundredSlaps.PushBack({ 588, 574, 181, 82 });//		  4/2/1
HundredSlaps.PushBack({ 844, 1281, 140, 97 });//	  4/2/1
HundredSlaps.PushBack({ 769, 574, 168, 82 });//		  4/2/1
HundredSlaps.PushBack({ 129, 656, 150, 82 });//		  4/2/1
HundredSlaps.PushBack({ 96, 1378, 178, 97 });//		  4/2/1
HundredSlaps.PushBack({ 0, 656, 129, 82 });//		  4/2/1
HundredSlaps.speed = 1.0f;*/

LightHundredSlaps.PushBack({ 588, 574, 181, 82 });//  4
LightHundredSlaps.PushBack({ 588, 574, 181, 82 });//
LightHundredSlaps.PushBack({ 588, 574, 181, 82 });//
LightHundredSlaps.PushBack({ 588, 574, 181, 82 });//
LightHundredSlaps.PushBack({ 844, 1281, 140, 97 });//  4
LightHundredSlaps.PushBack({ 844, 1281, 140, 97 });//
LightHundredSlaps.PushBack({ 844, 1281, 140, 97 });//
LightHundredSlaps.PushBack({ 844, 1281, 140, 97 });//
LightHundredSlaps.PushBack({ 769, 574, 168, 82 });//  4	
LightHundredSlaps.PushBack({ 769, 574, 168, 82 });//
LightHundredSlaps.PushBack({ 769, 574, 168, 82 });//
LightHundredSlaps.PushBack({ 769, 574, 168, 82 });//
LightHundredSlaps.PushBack({ 129, 656, 150, 82 });//  4
LightHundredSlaps.PushBack({ 129, 656, 150, 82 });//
LightHundredSlaps.PushBack({ 129, 656, 150, 82 });//
LightHundredSlaps.PushBack({ 129, 656, 150, 82 });//
LightHundredSlaps.PushBack({ 96, 1378, 178, 97 });//  4	
LightHundredSlaps.PushBack({ 96, 1378, 178, 97 });//
LightHundredSlaps.PushBack({ 96, 1378, 178, 97 });//
LightHundredSlaps.PushBack({ 96, 1378, 178, 97 });//
LightHundredSlaps.PushBack({ 0, 656, 129, 82 });//  4
LightHundredSlaps.PushBack({ 0, 656, 129, 82 });//
LightHundredSlaps.PushBack({ 0, 656, 129, 82 });//
LightHundredSlaps.PushBack({ 0, 656, 129, 82 });//
LightHundredSlaps.speed = 1.0f;

MediumHundredSlaps.PushBack({ 588, 574, 181, 82 });//  2
MediumHundredSlaps.PushBack({ 588, 574, 181, 82 });//
MediumHundredSlaps.PushBack({ 844, 1281, 140, 97 });//  2
MediumHundredSlaps.PushBack({ 844, 1281, 140, 97 });//
MediumHundredSlaps.PushBack({ 769, 574, 168, 82 });//  2	
MediumHundredSlaps.PushBack({ 769, 574, 168, 82 });//
MediumHundredSlaps.PushBack({ 129, 656, 150, 82 });//  2
MediumHundredSlaps.PushBack({ 129, 656, 150, 82 });//
MediumHundredSlaps.PushBack({ 96, 1378, 178, 97 });//  2	
MediumHundredSlaps.PushBack({ 96, 1378, 178, 97 });//
MediumHundredSlaps.PushBack({ 0, 656, 129, 82 });//  2
MediumHundredSlaps.PushBack({ 0, 656, 129, 82 });//
MediumHundredSlaps.speed = 1.0f;

HeavyHundredSlaps.PushBack({ 588, 574, 181, 82 });//  1
HeavyHundredSlaps.PushBack({ 844, 1281, 140, 97 });//  1
HeavyHundredSlaps.PushBack({ 769, 574, 168, 82 });//  1
HeavyHundredSlaps.PushBack({ 129, 656, 150, 82 });//  1
HeavyHundredSlaps.PushBack({ 96, 1378, 178, 97 });//  1
HeavyHundredSlaps.PushBack({ 0, 656, 129, 82 });//  1
HeavyHundredSlaps.speed = 1.0f;

//throws
hug.PushBack({ 881, 1583, 101, 111 });//grab
hug.PushBack({ 219, 1694, 88, 117 });//dmg
hug.speed = 0.13f;

knees.PushBack({ 881, 1583, 101, 111 });//grab
knees.PushBack({ 320, 1478, 107, 102 });//knee
knees.PushBack({ 527, 1478, 107, 104 });//dmg
knees.speed = 0.13f;

throwing.PushBack({ 881, 1583, 101, 111 });//grab
throwing.PushBack({ 274, 1378, 110, 99 });//
throwing.PushBack({ 669, 1187, 76, 93 });//
throwing.PushBack({ 686, 1095, 95, 91 });//
throwing.PushBack({ 765, 416, 105, 77 });//
throwing.speed = 0.13f;

//hurt
Hit.PushBack({ 0, 1378, 96, 97 });
Hit.PushBack({ 214, 1281, 83, 94 });
Hit.PushBack({ 0, 1095, 80, 91 });
Hit.PushBack({ 214, 1281, 83, 94 });
Hit.PushBack({ 0, 1378, 96, 97 });
Hit.speed = 0.2f;

GutHit.PushBack({ 586, 740, 115, 86 });
GutHit.PushBack({ 477, 267, 108, 73 });
GutHit.PushBack({ 652, 656, 101, 84 });
GutHit.PushBack({ 477, 267, 108, 73 });
GutHit.PushBack({ 586, 740, 115, 86 });
GutHit.speed = 0.2f;

crouchHit.PushBack({ 856, 493, 96, 81 });
crouchHit.PushBack({ 870, 416, 108, 77 });
crouchHit.PushBack({ 856, 493, 96, 81 });
crouchHit.speed = 0.2f;

stunned.PushBack({ 883, 1378, 106, 100 });
stunned.PushBack({ 70, 1478, 103, 100 });
stunned.PushBack({ 571, 1187, 98, 93 });
stunned.PushBack({ 70, 1478, 103, 100 });
stunned.PushBack({ 883, 1378, 106, 100 });
stunned.PushBack({ 70, 1478, 103, 100 });
stunned.PushBack({ 571, 1187, 98, 93 });
stunned.PushBack({ 70, 1478, 103, 100 });
stunned.PushBack({ 883, 1378, 106, 100 });
stunned.speed = 0.1f;

knockdown.PushBack({ 781, 1095, 117, 92 });
knockdown.PushBack({ 321, 915, 103, 88 });
knockdown.PushBack({ 525, 915, 112, 88 });
knockdown.PushBack({ 430, 0, 150, 56 });
knockdown.speed = 0.1f;

KO.PushBack({ 781, 1095, 117, 92 });
KO.PushBack({ 321, 915, 103, 88 });
KO.PushBack({ 525, 915, 112, 88 });
KO.PushBack({ 430, 0, 150, 56 });
KO.PushBack({ 525, 915, 112, 88 });
KO.PushBack({ 430, 0, 150, 56 });
KO.speed = 0.05f;

recover.PushBack({ 430, 0, 150, 56 });
recover.PushBack({ 525, 915, 112, 88 });
recover.PushBack({ 236, 493, 81, 79 });
recover.PushBack({ 340, 340, 108, 75 });
recover.PushBack({ 782, 1004, 107, 91 });//idle
recover.speed = 0.13f;

//victory
victory.PushBack({ 816, 740, 100, 87 });
victory.PushBack({ 712, 1378, 101, 100 });
victory.PushBack({ 732, 1694, 92, 136 });
victory.speed = 0.13f;

victory2.PushBack({ 782, 1004, 107, 91 });
victory2.PushBack({ 0, 1004, 122, 89 });
victory2.PushBack({ 0, 574, 147, 82 });
victory2.PushBack({ 147, 574, 147, 82 });
victory2.PushBack({ 0, 740, 147, 85 });
victory2.PushBack({ 147, 740, 147, 85 });
victory2.PushBack({ 439, 740, 147, 85 });
victory2.speed = 0.13f;

block.PushBack({ 614,1378,98,99 });
block.PushBack({ 104,1583,104,105 });//blocking
block.speed = 0.13f;

crouchblock.PushBack({ 519,416,106,77 });
crouchblock.PushBack({ 627,493,95,80 });//blocking
block.speed = 0.13f;

}

ModuleHonda::~ModuleHonda() {};

bool ModuleHonda::Start()
{
	if(player_num == PLAYER_NUMBER::NUMBER_ONE)position.x = 100;
	else position.x = 200;
	position.y = 212;
	auxPosition = position;
	flip = false;
	action = NO_ACTION;
	movement = IDLE;
	state = ON_FLOOR;
	current_animation = &idle;
	return true;
}

bool ModuleHonda::CleanUp()
{
	if (coll_body != nullptr)coll_body->to_delete = true;
	return true;
}

update_status ModuleHonda::Update()
{
	if ((position.y > 212) && state == JUMPING)
	{
		state = ON_FLOOR;
		movement = IDLE;
		action = NO_ACTION;
		vspeed = 0;
		neutralJump.Reset();
		forwardJump.Reset();
		backwardJump.Reset();
		jumpLightKick.Reset();
		jumpMediumKick.Reset();
		jumpHeavyKick.Reset();
		jumpLightPunch.Reset();
		jumpMediumPunch.Reset();
		jumpHeavyPunch.Reset();
		jumpDiagonalLightKick.Reset();
		jumpDiagonalMediumKick.Reset();
		jumpDiagonalHeavyKick.Reset();
		position.y = 212;
	}
	if (flip && movement == BACKWARD)movement = FORWARD;
	else if (flip && movement == FORWARD)movement = BACKWARD;
	
	switch (state)
	{
	case ON_FLOOR:
		if ((movement == IDLE && action == NO_ACTION))current_animation = &idle;
		if (movement == IDLE)
		{
			if (current_animation->Finished())
			{
				current_animation->Reset();
				action = NO_ACTION;
			}
			if (action == LIGHT_KICK)current_animation = &lightKick;
			else if (action == MEDIUM_KICK)current_animation = &mediumKick;
			else if (action == HEAVY_KICK)current_animation = &heavyKick;
			if (action == LIGHT_PUNCH)current_animation = &lightPunch;
			else if (action == MEDIUM_PUNCH)current_animation = &mediumPunch;
			else if (action == HEAVY_PUNCH)current_animation = &heavyPunch;
		}
		if (movement == TURN_LEFT)
		{
			current_animation = &turnLeft;
			if (current_animation->Finished())
			{
				movement = BACKWARD;
				current_animation->Reset();
			}
		}
		if (movement == TURN_RIGHT)
		{
			current_animation = &turnRight;
			if (current_animation->Finished())
			{
				movement = BACKWARD;
				current_animation->Reset();
			}
		}
		if (movement == BACKWARD)
		{
			if ((position.x > App->render->limit.x + 64) && !flip)position.x -= 1;
			else if(position.x < (App->render->limit.x + App->render->limit.w - auxiliar.w/2) && flip)position.x += 1;
			current_animation = &backward;
			if (current_animation->Finished())
			{
				movement = IDLE;
			}
		}
		if (movement == FORWARD)
		{
			if (position.x < (App->render->limit.x + App->render->limit.w - auxiliar.w) && !flip)position.x += 1;
			else if (position.x > App->render->limit.x + 64 && flip)position.x -= 1;
			current_animation = &forward;
			if (current_animation->Finished())
			{
				movement = IDLE;
			}
			if (action = KNEES)current_animation = &knees;
			else if (action = THROW)current_animation = &throwing;
			else if (action = HUG)current_animation = &hug;
			if (action = LIGHT_SUMO_HEAD_BUTT)current_animation = &LightSumoHeadbutt;
			else if (action = MEDIUM_SUMO_HEAD_BUTT)current_animation = &MediumSumoHeadbutt;
			else if (action = HEAVY_SUMO_HEAD_BUTT)current_animation = &HeavySumoHeadbutt;
		}
		break;
	case STANDING_TO_CROUCHING:
		if (movement == IDLE && action == NO_ACTION)current_animation = &crouching;
		if (current_animation->Finished())
		{
			state=CROUCHING;
			current_animation->Reset();
		}
		break;
	case CROUCHING:
		if (movement == IDLE && action == NO_ACTION)current_animation = &idleCrouch;
		if (movement == IDLE)
		{
			if (current_animation->Finished())
			{
				current_animation->Reset();
				action = NO_ACTION;
			}
			if (action == LIGHT_KICK)current_animation = &crouchLightKick;
			else if (action == MEDIUM_KICK)current_animation = &crouchMediumKick;
			else if (action == HEAVY_KICK)current_animation = &crouchHeavyKick;
			else if (action == LIGHT_PUNCH)current_animation = &crouchLightPunch;
			else if (action == MEDIUM_PUNCH)current_animation = &crouchMediumPunch;
			else if (action == HEAVY_PUNCH)current_animation = &crouchHeavyPunch;
		}
		break;
	case CROUCHING_TO_STANDING:
		if (movement == IDLE && action == NO_ACTION)current_animation = &standing;
		if (current_animation->Finished())
		{
			state = ON_FLOOR;
			current_animation->Reset();
		}
		break;
	case JUMPING:
		vspeed += acceleration;
		position.y += vspeed;
		if (movement == FORWARD)
		{
			if (position.x < (App->render->limit.x + App->render->limit.w - auxiliar.w) && !flip)position.x += 2;
			else if (position.x > App->render->limit.x + 64 && flip)position.x -= 2;
			current_animation = &forwardJump;
			if (action == LIGHT_KICK)current_animation = &jumpDiagonalLightKick;
			else if (action == MEDIUM_KICK)current_animation = &jumpDiagonalMediumKick;
			else if (action == HEAVY_KICK)current_animation = &jumpDiagonalHeavyKick;
			if (action == LIGHT_PUNCH)current_animation = &jumpLightPunch;
			else if (action == MEDIUM_PUNCH)current_animation = &jumpMediumPunch;
			else if (action == HEAVY_PUNCH)current_animation = &jumpHeavyPunch;
		}
		if (movement == BACKWARD)
		{
			if ((position.x > App->render->limit.x + 64) && !flip)position.x -= 2;
			else if (position.x < (App->render->limit.x + App->render->limit.w - auxiliar.w / 2) && flip)position.x += 2;
			current_animation = &neutralJump;
		}
		if (movement == IDLE && action == NO_ACTION)current_animation = &neutralJump;
		else if (movement == IDLE && action == LIGHT_KICK)current_animation = &jumpLightKick;
		else if (movement == IDLE && action == MEDIUM_KICK)current_animation = &jumpMediumKick;
		else if (movement == IDLE && action == HEAVY_KICK)current_animation = &jumpHeavyKick;
		else if (movement == IDLE && action == LIGHT_PUNCH)current_animation = &jumpLightPunch;
		else if (movement == IDLE && action == MEDIUM_PUNCH)current_animation = &jumpMediumPunch;
		else if (movement == IDLE && action == HEAVY_PUNCH)current_animation = &jumpHeavyPunch;
		break;
	case VICTORY:
		current_animation = &victory;
		break;
	case SECOND_VICTORY:
		current_animation = &victory2;
		break;
	case STUNNED:
		current_animation = &stunned;
		break;
	case KNOCK_DOWN:
		current_animation = &knockdown;
		break;
	case STATE_CHARACTER::KNOCK_OUT:
		current_animation = &KO;
		break;
	case RECOVER:
		current_animation = &recover;
		break;
	default:
		break;
	}

	auxiliar = current_animation->GetCurrentFrame();

	if(flip)auxPosition.x = position.x - (auxiliar.w - auxiliar.w/2);
	else auxPosition.x = position.x - auxiliar.w / 2;

	if(position.y <= 212)App->render->Blit(App->manager->graphics, auxPosition.x, position.y - auxiliar.h, &auxiliar, 1.0F, true, flip);
	return update_status::UPDATE_CONTINUE;
}

void ModuleHonda::OnCollision(Collider * c1, Collider * c2)
{
}
