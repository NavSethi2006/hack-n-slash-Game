#include "animation.h"

void set_direction(entity *en, bool dir)
{
    en->direction = dir;
}

void add_animation_component(entity *en, Texture2D tex)
{
    en->components.animation_component = malloc(sizeof(animation_c));    
    en->components.animation_component->tex = tex;
}
int current_frame;
float total_time;

void update_animation(entity *en, int frame_count, float switch_time, Rectangle frames[])
{

    for(int i = 0; i <= frame_count; i++) {
        en->components.animation_component->frames[i] = frames[i];
    }

    total_time += GetFrameTime();
    if (total_time >= switch_time)
    {
        total_time -= switch_time;
        current_frame++;
    }
    if (current_frame >= frame_count)
    {
        current_frame = 0;
    }
    
}

void render_animation(entity *en, int size_of_animation)
{

    Rectangle dest_rect = {en->components.position_component->x * 2,
                           en->components.position_component->y * 2,
                           en->components.size_component->width,
                           en->components.size_component->height};
    
    if (en->direction)
    {

    DrawTexturePro(en->components.animation_component->tex,
        (Rectangle){en->components.animation_component->frames[current_frame].x,
                    en->components.animation_component->frames[current_frame].y,
                    -en->components.animation_component->frames[current_frame].width,
                    en->components.animation_component->frames[current_frame].height},
                    dest_rect,
        (Vector2){en->components.position_component->x,
                en->components.position_component->y},
                0, RAYWHITE);
    }
    else
    {
        DrawTexturePro(en->components.animation_component->tex,
            (Rectangle){en->components.animation_component->frames[current_frame].x,
                        en->components.animation_component->frames[current_frame].y,
                        en->components.animation_component->frames[current_frame].width,
                        en->components.animation_component->frames[current_frame].height},
                        dest_rect,
                        (Vector2){en->components.position_component->x,
                                en->components.position_component->y},
                         0, RAYWHITE);
    }
}

