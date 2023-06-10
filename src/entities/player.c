#include "player.h"

bool is_flipped;
enum entity_state player_states;


Rectangle left_animation[3] = {{0, 33, 20, 31},
                               {20, 33, 20, 31},
                               {40, 33, 20, 31}};

Rectangle idle_animation[1] = {0, 0, 17, 32};

entity player;

void player_()
{

    add_position_component(&player, 300, 500);
    add_health_component(&player, 100);
    add_size_component(&player, 41, 50);
    add_physics_component(&player, (Vector2){200, 100}, (Vector2) {10, 10}, 4);
    add_animation_component(&player, player_texture());
    add_collision_component(&player);
}


void player_update()
{

    if (IsKeyDown(KEY_A))
    {
        move_left(&player);
        player_states = RUN;
        is_flipped = true;    
    }
    else if (IsKeyDown(KEY_D))
    {
        move_right(&player);
        player_states = RUN;
        is_flipped = false;
    }
    else if (IsKeyDown(KEY_W))
    {
        move_up(&player);
        player_states = JUMP;        
    }
    else if (IsKeyDown(KEY_S))
    {
        move_down(&player);
        player_states = FALLING;      
    } 
    else {
        player_states = IDLE;
        stop(&player);
    }



    switch (player_states)
    {
    case RUN:
        update_animation(&player, 3, 0.1, left_animation);
        break;
    case JUMP:
        update_animation(&player, 1, 0.1, idle_animation);
        break;
    case FALLING:
        update_animation(&player, 1, 0.1, idle_animation);
        break;
    case IDLE:
        update_animation(&player, 1, 0.1, idle_animation);
        break;

    default:
        break;
    }
    
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
