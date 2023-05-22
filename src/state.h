#pragma once

/*
    @author Navin
    State handler
*/

void splash_screen();

void state();

//switches the states passing the enum for which state to swap too
// @param state
void switch_state(int state);

// the enum that holds all the possible game states
typedef enum state { 
    STATE_SPLASH, 
    STATE_MENU, 
    STATE_GAME, 
    STATE_PAUSE, 
};


// returns the state of which the game is in at the moment
enum state get_state();


