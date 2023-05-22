#include "ecs.h"

void add_position_component(entity *en, int x, int y)
{
    en->components.position_compenent = malloc(sizeof(position_c));
    en->components.position_compenent->x = x;
    en->components.position_compenent->y = y;
}

void add_health_component(entity *en, float max_health)
{
    en->components.health_component = malloc(sizeof(health_c));
    en->components.health_component->max_health = max_health;
}

void add_size_component(entity *en, float width, float height)
{
    en->components.size_component = malloc(sizeof(size_c));
    en->components.size_component->width = width;
    en->components.size_component->height = height;
}


