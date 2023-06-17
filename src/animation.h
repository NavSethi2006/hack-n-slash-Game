#pragma once
#include "entities/ecs.h"

void set_direction(entity* en,bool dir);

void add_animation_component(entity *en, Texture2D tex, int max_frames_in_one_animation);
void update_animation(entity *en, int frame_count, float switch_time, Rectangle frames[]);
void update_hitbox_on_animation(entity *en);
void render(entity *en, int scale);
