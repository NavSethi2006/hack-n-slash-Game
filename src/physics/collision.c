#include "collision.h"

bool is_entity_hit(entity *temp_1, entity *temp_2)
{
    if (CheckCollisionRecs(temp_1->components.collision_component->hitbox,
                           temp_2->components.collision_component->hitbox))
    {
        return true;
    }
}

bool is_entity_collides_map(entity *en, Rectangle hitbox)
{
    if((en->components.collision_component->hitbox.x <= (hitbox.x + hitbox.width) && 
        (en->components.collision_component->hitbox.x + en->components.collision_component->hitbox.width) >= hitbox.x) &&
        (en->components.collision_component->hitbox.y <= (hitbox.y + hitbox.height) && 
        (en->components.collision_component->hitbox.y + en->components.collision_component->hitbox.height) >= hitbox.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}
