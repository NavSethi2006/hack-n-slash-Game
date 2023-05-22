#include "game.h"



void game_()
{
    map_();
    player_();
}

void game_update()
{
    player_update();
    

}

void game_render()
{
    BeginDrawing();

    player_render();
 
    map_render();

    ClearBackground(BLACK);

    EndDrawing();
}
