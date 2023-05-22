#include "entities/ecs.h"

void set_direction(entity* en,bool dir);
void update_flag(entity* en, bool flag, int which_animation);
void allocate_mem_animation(entity *en, int size);
void allocate_mem_frames(entity *en, int size, int which_array);
void add_animation_component(entity *en, Texture2D tex, Rectangle *frames, int framecount, float switch_time, int which_array);
void update_animation(entity *en,int which_array);
void render_animation(entity *en, int number_of_animations);