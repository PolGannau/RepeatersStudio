#ifndef __MODULEAUDIO_H__
#define __MODULEAUDIO_H__

#include "Module.h"
#include "Globals.h"
#include "../SDL_Mixer/include/SDL_mixer.h"

#define MAX_MUSIC 25
#define MAX_FX 25

class ModuleAudio :public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();

	bool CleanUp();

	void PlayMusic(Mix_Music* music_to_play, int repetitions = -1);
	void PlaySoundEffect(Mix_Chunk* effect_to_play);

	Mix_Music* const LoadMusic(const char* path);
	Mix_Chunk* const LoadEffect(const char* path);

	void UnloadMusic(Mix_Music* music);
	void UnloadSoundEffects(Mix_Chunk* effect);
public:

	Mix_Music * songs[MAX_MUSIC];

	Mix_Chunk* sound_effects[MAX_FX];
};

#endif // !__MODULEAUDIO_H__
