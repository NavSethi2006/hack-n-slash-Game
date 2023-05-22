#include "menu.h"


void menu_() {

}

void menu_update() {
    printf("in menu\n");
    if(IsKeyPressed(KEY_SPACE)) {
        switch_state(STATE_GAME);
    }
}

void menu_render() {
    BeginDrawing();


    EndDrawing();
    
}