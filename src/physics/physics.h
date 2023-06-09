#pragma once
#include "raylib/raylib.h"
#include "../entities/ecs.h"


void add_physics_component(entity *en, Vector2 max_velocity, Vector2 acceleration, float mass);
void move_right(entity *en);
void move_left(entity *en);
void move_up(entity *en);
void move_down(entity *en);
void stop(entity *en);
void jump(entity *en);
void update_physics_component(entity *en);

