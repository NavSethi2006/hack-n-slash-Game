/*
    @author Navin
    Everything to do with the player
*/


#pragma once
#include "raylib/raylib.h"
#include "../animation.h"
#include "ecs.h"
#include "../asset.h"
#include "../state.h"

// finalize player and component system then work on physics engine



void player_();

void player_update();

void player_render();

entity get_player();
