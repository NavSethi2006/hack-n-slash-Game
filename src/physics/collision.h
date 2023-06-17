#pragma once
#include "../entities/ecs.h"
#include "raylib/raylib.h"
#include <stdbool.h>
#include <math.h>

bool is_entity_hit(entity *temp_1, entity *temp_2);
bool is_entity_collides_map(entity *en, Rectangle hitbox);
bool collide_top_line(entity *en, Rectangle hitbox);
bool collide_bottom_line(entity *en, Rectangle hitbox);
bool collide_side_line(entity *en, Rectangle hitbox);
bool collide_left(entity *en, Rectangle hitbox);
bool collide_right(entity *en, Rectangle hitbox);


typedef struct polyline {
    Vector2 pos;
    double** points;
} polyline;