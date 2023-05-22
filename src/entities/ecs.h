#pragma once
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "raylib/raylib.h"

typedef struct position_c {
    float x;
    float y;
} position_c;

typedef struct size_c {
    float width;
    float height;
} size_c;

typedef struct health_c {
    float current_health;
    float max_health;
} health_c;

typedef struct stats_c {

} stats_c;

typedef struct gravity_c {
    
} gravity_c;

typedef struct ai_c {

} ai_c;

typedef struct collision_c {
    Rectangle AABB; 
} collision_c;

typedef struct animation_c {
    Texture2D tex;
    float switch_time;
    bool flag;
    int framecount;
    Rectangle *frames;
} animation_c;

typedef struct components_t {
    position_c *position_compenent;
    health_c   *health_component;
    stats_c    *stats_component;
    gravity_c  *gravity_component;
    ai_c       *ai_component;
    collision_c *collision_component;
    size_c       *size_component;
    animation_c  *animation_component;
} components_t;

typedef struct entity {
    uint8_t ID;
    char* name;
    bool direction;
    components_t components;
} entity;

/////       POSITION STUFF      /////

void add_position_component(entity *en, int x, int y);

/////       HEALTH STUFF        /////

void add_health_component(entity *en, float max_health);

/////       SIZE STUFF          /////

void add_size_component(entity *en, float width, float height);

/////       ANIMATION STUFF     /////


