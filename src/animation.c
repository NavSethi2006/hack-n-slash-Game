#include "animation.h"

void set_direction(entity *en, bool dir)
{
    en->direction = dir;
}

void allocate_mem_animation(entity *en, int size)
{
    en->components.animation_component = (animation_c *)malloc(size * sizeof(animation_c));
}

void allocate_mem_frames(entity *en, int size, int which_array) {
    en->components.animation_component[which_array].frames = (Rectangle *)malloc(size * sizeof(Rectangle));
}


void add_animation_component(entity *en, Texture2D tex, Rectangle *frames, int framecount, float switch_time, int which_array)
{
    en->components.animation_component[which_array].tex = tex;
    
    for (int i = 0; i < framecount; i++)
    {
        en->components.animation_component[which_array].frames[i] = frames[i];
    }

    
    en->components.animation_component[which_array].framecount = framecount;
    en->components.animation_component[which_array].switch_time = switch_time;
     
}
int current_frame;
float total_time;

void update_flag(entity* en, bool flag, int which_animation) {
    en->components.animation_component[which_animation].flag = flag;
}

void update_animation(entity *en, int which_array)
{
    if(en->components.animation_component[which_array].flag) {
        total_time += GetFrameTime();
        if (total_time >= en->components.animation_component[which_array].switch_time)
        {
            total_time -= en->components.animation_component[which_array].switch_time;
            current_frame++;
        }
    }
    if (current_frame >= en->components.animation_component[which_array].framecount)
    {
        current_frame = 0;
    }
}

void render_animation(entity *en, int size_of_animation)
{

    Rectangle dest_rect = {en->components.position_compenent->x * 2,
                           en->components.position_compenent->y * 2,
                           en->components.size_component->width,
                           en->components.size_component->height};
    

    

    for (int i = 0; i <= size_of_animation; i++) {
        if(en->components.animation_component[i].flag) {
            if (en->direction)
            {
                
                DrawTexturePro(en->components.animation_component[i].tex,
                            (Rectangle){en->components.animation_component[i].frames[current_frame].x,
                                        en->components.animation_component[i].frames[current_frame].y,
                                        -en->components.animation_component[i].frames[current_frame].width,
                                        en->components.animation_component[i].frames[current_frame].height},
                            dest_rect,
                            (Vector2){en->components.position_compenent->x,
                                        en->components.position_compenent->y},
                            0, RAYWHITE);
            }
            else
            {
                DrawTexturePro(en->components.animation_component[i].tex,
                            (Rectangle){en->components.animation_component[i].frames[current_frame].x,
                                        en->components.animation_component[i].frames[current_frame].y,
                                        en->components.animation_component[i].frames[current_frame].width,
                                        en->components.animation_component[i].frames[current_frame].height},
                            dest_rect,
                            (Vector2){en->components.position_compenent->x,
                                        en->components.position_compenent->y},
                            0, RAYWHITE);
            }
        }
    }
}