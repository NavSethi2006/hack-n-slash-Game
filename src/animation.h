#pragma once
#include "entities/ecs.h"

void set_direction(entity* en,bool dir);

void add_animation_component(entity *en, Texture2D tex);
void update_animation(entity *en, int frame_count, float switch_time, Rectangle frames[]);
void render_animation(entity *en, int number_of_animations);
