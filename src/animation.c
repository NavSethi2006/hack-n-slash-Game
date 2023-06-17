#include "animation.h"



void set_direction(entity *en, bool dir)
{
    en->direction = dir;
}

void add_animation_component(entity *en, Texture2D tex, int max_frames_in_one_animation)
{
    en->components.animation_component = malloc(sizeof(animation_c));  
    en->components.animation_component->frames = malloc(sizeof(Rectangle) * max_frames_in_one_animation);  
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

Rectangle dest_rect = {0,0,0,0};

void update_hitbox_on_animation(entity *en) {
    en->components.collision_component->hitbox = (Rectangle){en->components.animation_component->frames[current_frame].x,
                                                            en->components.animation_component->frames[current_frame].y,
                                                             dest_rect.width,
                                                             dest_rect.height};
}


void render(entity *en, int scale)
{

    dest_rect.x = en->components.position_component->x * 2;
    dest_rect.y = en->components.position_component->y * 2;
    dest_rect.width = en->components.animation_component->frames[current_frame].width * scale;
    dest_rect.height = en->components.animation_component->frames[current_frame].height * scale;

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

