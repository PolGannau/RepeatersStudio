#include "ModuleAudio.h"
#include "Application.h"
#include "../SDL_Mixer/include/SDL_mixer.h"
#pragma comment ( lib, "../SDL_mixer/libx86/SDL2_mixer.lib")



ModuleAudio::ModuleAudio()
{
	for (uint i = 0; i < MAX_MUSIC; ++i)
		songs[i] = nullptr;

	for (uint i = 0; i < MAX_FX; ++i)
		sound_effects[i] = nullptr;

}

ModuleAudio::~ModuleAudio() {}

bool ModuleAudio::Init()
{
	bool ret = true;

	LOG("Init Audio Module .........");

	if (Mix_Init(MIX_INIT_OGG) < 0)
	{
		LOG("Audio Module can't be initialized: %s/n", Mix_GetError());
		ret = false;
	}
	else
	{
		if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
		{
			LOG("Audio Module can't open: %s/n", Mix_GetError());
			ret = false;
		}
	}
	return ret;
}

bool ModuleAudio::CleanUp()
{
	LOG("Cleaning Audio Module ............")

		for (uint i = 0; i < MAX_MUSIC; ++i)
		{
			if (songs[i] != nullptr)
			{
				Mix_FreeMusic(songs[i]);
				songs[i] = nullptr;
				break;
			}
		}

	for (uint i = 0; i < MAX_FX; ++i)
	{
		if (sound_effects[i] != nullptr)
		{
			Mix_FreeChunk(sound_effects[i]);
			sound_effects[i] = nullptr;
			break;
		}
	}

	Mix_CloseAudio();
	Mix_Quit();

	return true;
}

void ModuleAudio::PlayMusic(Mix_Music * music_to_play, int repetitions)
{
	Mix_PlayMusic(music_to_play, repetitions);
	Mix_VolumeMusic(MIX_MAX_VOLUME / 3);
}

void ModuleAudio::PlaySoundEffect(Mix_Chunk * effect_to_play)
{
	Mix_PlayChannel(-1, effect_to_play, 0);
}

Mix_Music * const ModuleAudio::LoadMusic(const char * path)
{
	Mix_Music* music = nullptr;

	music = Mix_LoadMUS(path);

	if (music == nullptr)
	{
		LOG("couldn't load song with path: %s. Error: %s", path, Mix_GetError());
	}

	else
	{
		for (int last = 0; last < MAX_MUSIC; ++last)
		{
			if (songs[last] == nullptr)
			{
				songs[last] = music;
				break;
			}
		}
	}

	return music;
}

Mix_Chunk * const ModuleAudio::LoadEffect(const char * path)
{
	Mix_Chunk* effect = nullptr;

	effect = Mix_LoadWAV(path);

	if (effect == nullptr)
	{
		LOG("Could not load sound effect with path: %s. Error: %s", path, Mix_GetError());
	}

	else
	{
		for (int last = 0; last < MAX_FX; ++last)
		{
			if (sound_effects[last] == nullptr)
			{
				sound_effects[last] = effect;
				break;
			}
		}
	}
	return effect;
}

void ModuleAudio::UnloadMusic(Mix_Music * music)
{
	for (uint i = 0; i < MAX_MUSIC; ++i)
	{
		if (songs[i] == music)
		{
			Mix_FreeMusic(music);
			songs[i] = nullptr;
			break;
		}
	}
}

void ModuleAudio::UnloadSoundEffects(Mix_Chunk * effect)
{
	for (uint i = 0; i < MAX_FX; ++i)
	{
		if (sound_effects[i] == effect)
		{
			Mix_FreeChunk(effect);
			sound_effects[i] = nullptr;
			break;
		}
	}
}
