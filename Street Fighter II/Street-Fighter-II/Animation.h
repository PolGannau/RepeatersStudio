#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "../SDL/include/SDL_rect.h"
#define MAX_FRAMES 100

struct CollidersPosition
{
	SDL_Rect head;
	SDL_Rect body;
	SDL_Rect legs;
	SDL_Rect attack;
};

class Animation
{
public:
	bool loop = false;
	float speed = 1.0f;
	SDL_Rect frames[MAX_FRAMES];
	CollidersPosition framenumber[MAX_FRAMES];

private:
	float current_frame = 0.0f;
	float current_colliders = 0.0f;
	int last_frame = 0;
	int last_collider = 0;
	int coll_loops = 0;
	int loops = 0;

public:

	Animation()
	{}

	Animation(const Animation& anim) : loop(anim.loop), speed(anim.speed), last_frame(anim.last_frame)
	{
		SDL_memcpy(&frames, anim.frames, sizeof(frames));
	}

	void PushBack(const SDL_Rect& rect)
	{
		frames[last_frame++] = rect;
	}

	void CollPushBack(const SDL_Rect& head,const SDL_Rect& body, const SDL_Rect& legs, const SDL_Rect& attack)
	{
		framenumber[last_collider].head = head;
		framenumber[last_collider].body = body;
		framenumber[last_collider].legs = legs;
		framenumber[last_collider++].attack = attack;
	}

	SDL_Rect& GetCurrentFrame()
	{
		current_frame += speed;
		if (current_frame >= last_frame)
		{
			current_frame = (loop) ? 0.0f : last_frame - 1;
			loops++;
		}

		return frames[(int)current_frame];
	}

	CollidersPosition& GetCurrentColliders()
	{
		current_colliders += speed;
		if (current_colliders >= last_collider)
		{
			current_colliders = (loop) ? 0.0f : last_collider - 1;
			coll_loops++;
		}
		return framenumber[(int)current_colliders];
	}

	bool Finished() const
	{
		return loops > 0;
	}

	void Reset()
	{
		coll_loops = 0;
		loops = 0;
		current_colliders = 0.0f;
		current_frame = 0.0f;
	}
};

#endif
