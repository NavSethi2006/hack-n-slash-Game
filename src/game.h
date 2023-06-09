/*
    @author Navin
    Everything to do with the game itself
*/


#pragma once

#include "raylib/raylib.h"
#include <stdio.h>
#include "state.h"
#include "asset.h"
#include "string.h"
#include "entities/ecs.h"
#include "entities/player.h"
#include "map.h"
#include "physics/collision.h"

void game_();
void game_update();
void game_render();