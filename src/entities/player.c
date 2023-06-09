#include "player.h"

bool is_flipped;
bool walk_animation, idle_ani;
enum entity_state player_states;


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

    add_position_component(&player, 300, 500);
    add_health_component(&player, 100);
    add_size_component(&player, 41, 50);
    add_physics_component(&player, (Vector2){200, 100}, (Vector2) {10, 10}, 4);
    add_animation_component(&player, player_texture(), left_animation, 3, 0.1, 0);
    add_animation_component(&player, player_texture(), idle_animation, 1, 0.1, 1);

    add_collision_component(&player);
}


void player_update()
{

    if (IsKeyDown(KEY_A))
    {
        move_left(&player);
        player_states = RUN;
        is_flipped = true;
        // walk_animation = true;
        // idle_ani = false;
        
    }
    else if (IsKeyDown(KEY_D))
    {
        move_right(&player);
        player_states = RUN;
        is_flipped = false;
        // walk_animation = true;
        // idle_ani = false;
    }
    else if (IsKeyDown(KEY_W))
    {
        move_up(&player);
        player_states = JUMP;
        // idle_ani = true;
        // walk_animation = false;
        
    }
    else if (IsKeyDown(KEY_S))
    {
        move_down(&player);
        player_states = FALLING;
        // idle_ani = true;
        // walk_animation = false;
        
    } 
    else {
        player_states = idle_ani;
        stop(&player);
    }



    switch (player_states)
    {
    case RUN:
        update_animation(&player, 0);
        walk_animation = true;
        break;
    case JUMP:
        update_animation(&player, 1);
        idle_ani = true;
        break;
    case FALLING:
        update_animation(&player, 1);
        idle_ani = true;
        break;
    case IDLE:
        update_animation(&player, 1);
        idle_ani = true;
        break;

    default:
        break;
    }
    

    update_flag(&player, walk_animation, 0);
    update_flag(&player, idle_ani, 1);
    update_collision_component(&player);
    update_physics_component(&player);
    set_direction(&player, is_flipped);



}

void player_render()
{
    render_animation(&player, 1);

    DrawRectangleLinesEx(player.components.collision_component->hitbox, 2, (Color){255, 0, 0, 255});
}

entity *get_player()
{
    return &player;
}
