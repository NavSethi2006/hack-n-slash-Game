#pragma once
#include "../entities/ecs.h"
#include "raylib/raylib.h"
#include <stdbool.h>
#include <math.h>

bool is_entity_hit(entity *temp_1, entity *temp_2);

bool is_entity_collides_map(entity *en, Rectangle hitbox);

void update_entity_collision(entity *en, float collision_time);
// bool is_tile_hit(entity *temp_1, Tile tile);
