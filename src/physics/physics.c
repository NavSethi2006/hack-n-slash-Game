#include "physics.h"


void add_physics_component(entity *en, Vector2 max_velocity, Vector2 acceleration, float mass)
{
  en->components.physics_component = malloc(sizeof(physics_c));
  en->components.physics_component->max_velocity = max_velocity;
  en->components.physics_component->acceleration = acceleration;
  en->components.physics_component->mass = mass;
  en->components.physics_component->velocity.x = 0;
  en->components.physics_component->velocity.y = 0;
}

void update_physics_component(entity *en)
{
  en->components.position_component->x += en->components.physics_component->velocity.x * GetFrameTime();
  en->components.position_component->y += en->components.physics_component->velocity.y * GetFrameTime();
}

void move_right(entity *en)
{
  if (en->components.physics_component->velocity.x <= en->components.physics_component->max_velocity.x)
    en->components.physics_component->velocity.x += en->components.physics_component->acceleration.x;
  
}

void move_left(entity *en)
{
  if (en->components.physics_component->velocity.x >= -en->components.physics_component->max_velocity.x)
    en->components.physics_component->velocity.x -= en->components.physics_component->acceleration.x;
}

void move_up(entity *en)
{
}

void move_down(entity *en)
{
  if (en->components.physics_component->velocity.y >= en->components.physics_component->max_velocity.y)
    en->components.physics_component->velocity.y += en->components.physics_component->acceleration.y;
}

void stop(entity *en)
{

  if (en->components.physics_component->velocity.x > 0)
    en->components.physics_component->velocity.x -= en->components.physics_component->acceleration.x;
  if (en->components.physics_component->velocity.x < 0)
    en->components.physics_component->velocity.x += en->components.physics_component->acceleration.x;
}

void jump(entity *en)
{
  if (en->components.physics_component->can_jump)
  {
    en->components.physics_component->velocity.y -= en->components.physics_component->max_velocity.y;
    en->components.physics_component->can_jump = false;
  }
}

void add_gravity(entity *en, float mass, float speed_of_fall)
{
    en->components.physics_component->velocity.y += mass + speed_of_fall;
}