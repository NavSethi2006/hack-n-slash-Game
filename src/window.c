#include "window.h"

void window_() {
    InitWindow(1600, 800, "Game");

    SetTargetFPS(60);
    
    if(!IsWindowReady()) {
        printf("ERROR : WINDOW CANT GET READY");
        exit(1);
    } 

}

void window_update(){

}

void window_options() {


}