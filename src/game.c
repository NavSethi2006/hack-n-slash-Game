#include "game.h"

tmx_map *map;
Rectangle *rects;

void game_()
{
    map = map_("/home/navin/programming/hack-n-slash-Game/src/assets/map/map1.tmx");

    rects = get_objects_from_layer(map, "normal_collision", 1);

    player_();
}

void game_update()
{
    player_update();

    map_update();

    if(is_entity_collides_map(get_player(), rects[0])) {
      
    } else {
      
    }

    
}

void game_render()
{
    BeginDrawing();

    player_render();

    map_render(map);

    DrawRectangleLinesEx(rects[0],2,(Color) {255,0,0,255});

    ClearBackground(BLACK);

    EndDrawing();
}
