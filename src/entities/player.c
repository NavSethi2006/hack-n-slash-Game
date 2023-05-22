#include "player.h"

// MAKE ANIMATION COMPONENT AN ARRAY then go on from there

bool is_flipped;

bool walk_animation, idle_ani;

Rectangle left_animation[3] = {{0, 33, 20, 31},
                              {20, 33, 20, 31},
                              {40, 33, 20, 31}};
                              
Rectangle idle_animation[1] = {0, 0, 17, 32};

entity player;


void player_()
{

    allocate_mem_animation(&player, 2);

    allocate_mem_frames(&player, 3, 0);
    allocate_mem_frames(&player, 1, 1);

    add_position_component(&player, 300, 300);
    add_health_component(&player, 100);
    add_size_component(&player, 41, 50);
    
    add_animation_component(&player, player_texture(), left_animation, 3, 0.1, 0);
    add_animation_component(&player, player_texture(), idle_animation, 1, 0.1, 1);

}

void player_update()
{

    if (IsKeyDown(KEY_A))
    {
        player.components.position_compenent->x -= 2.0f;
        is_flipped = true;
        walk_animation = true;
        idle_ani = false; 
        update_animation(&player,0);

    }
    if (IsKeyDown(KEY_D))
    {
        player.components.position_compenent->x += 2.0f;
        is_flipped = false;
        walk_animation = true;
        idle_ani = false; 
        update_animation(&player,0);

    }
    if (IsKeyDown(KEY_W))
    {
        player.components.position_compenent->y -= 2.0f;
        walk_animation = false;
        idle_ani = true; 
        update_animation(&player, 1);
    }
    if (IsKeyDown(KEY_S))
    {
        player.components.position_compenent->y += 2.0f;
        walk_animation = false;
        idle_ani = true; 
        update_animation(&player, 1);
    }


    update_flag(&player, walk_animation, 0);
    update_flag(&player, idle_ani, 1);

    set_direction(&player, is_flipped);
    

}

void player_render()
{
    render_animation(&player, 1);



}

entity get_player()
{
    return player;
}
