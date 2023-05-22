
/*
    @author Navin
    Main file for launching program
*/

#include <stdio.h>
#include <stdlib.h>
#include "window.h"
#include "state.h"
#include "game.h"
#include "menu.h"
#include "asset.h"

int main()
{

    window_();

    load_assets();

    game_();

// Makes it eaiser to switch state anywhere in the program

    while (!WindowShouldClose())
    {
        switch(get_state()) {
            case STATE_SPLASH:
                switch_state(STATE_GAME);
                break;
            case STATE_MENU:
                menu_update();
                menu_render();
                break;
            case STATE_GAME:
                game_update();
                game_render();
                break;
            case STATE_PAUSE:
                break;
        }
        

    }

    unload_assets();

    CloseWindow();

    return 0;
}
