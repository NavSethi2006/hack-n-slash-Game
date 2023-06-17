#include "game.h"

tmx_map *map;
Rectangle *rects;

void game_()
{
    map = map_("/home/navin/programming/hack-n-slash-Game/src/assets/map/map1.tmx");

    rects = get_objects_from_layer(map, "normal_collision", 5);

    player_();
}

void game_update()
{
    player_update();

    map_update();
/*
    if(is_entity_collides_map(get_player(), rects[0])) {
        get_player()->components.physics_component->velocity.y = 0;
        get_player()->components.physics_component->can_jump = true;
    } else {
        get_player()->components.physics_component->can_jump = false;
    }
    */

   for(int i = 0; i < 5; i++) {
        if(collide_top(get_player(), rects[i])) {
            get_player()->components.physics_component->velocity.y = 0;
            get_player()->components.physics_component->can_jump = true;
        }
        printf("bruh\n");
//    if(collide_bottom(get_player(), rects[i])){
//         get_player()->components.physics_component->velocity.y = 0;
//     }
   }
     
    // if(collide_left(get_player(), rects)) {
    //     get_player()->components.physics_component->velocity.x = 0;
    // }
    // if(collide_right(get_player(), rects)){
    //     get_player()->components.physics_component->velocity.x = 0;
    // }

   

    
}

void game_render()
{
    BeginDrawing();

    player_render();

    map_render(map);

    DrawRectangleLinesEx(rects[0],2,(Color) {255,0,0,255});
    DrawRectangleLinesEx(rects[1],2,(Color) {255,0,0,255});
    DrawRectangleLinesEx(rects[2],2,(Color) {255,0,0,255});
    DrawRectangleLinesEx(rects[3],2,(Color) {255,0,0,255});
    DrawRectangleLinesEx(rects[4],2,(Color) {255,0,0,255});

    ClearBackground(BLACK);

    EndDrawing();
}
