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
    if ((en->components.collision_component->hitbox.x <= (hitbox.x + hitbox.width) &&
         (en->components.collision_component->hitbox.x + en->components.collision_component->hitbox.width) >= hitbox.x) &&
        (en->components.collision_component->hitbox.y <= (hitbox.y + hitbox.height) &&
         (en->components.collision_component->hitbox.y + en->components.collision_component->hitbox.height) >= hitbox.y - 10))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool collision(entity *en, Rectangle hitbox) {

    return ((en->components.collision_component->hitbox.x <= (hitbox.x + hitbox.width) &&
             (en->components.collision_component->hitbox.x + en->components.collision_component->hitbox.width) >= hitbox.x) &&
            (en->components.collision_component->hitbox.y <= (hitbox.y + hitbox.height) &&
             (en->components.collision_component->hitbox.y + en->components.collision_component->hitbox.height) >= hitbox.y - 5));

}

bool collide_top_line(entity *en, Rectangle hitbox)
{
    
}
bool collide_bottom_line(entity *en, Rectangle hitbox) {

}
bool collide_side_line(entity *en, Rectangle hitbox) 
{

}
bool collide_bottom(entity *en, Rectangle hitbox)
{
    return en->components.collision_component->hitbox.y <=
           (hitbox.y + hitbox.height);
}
bool collide_left(entity *en, Rectangle hitbox)
{
    return en->components.collision_component->hitbox.x <=
           (hitbox.x + hitbox.width);
}
bool collide_right(entity *en, Rectangle hitbox)
{
    return en->components.collision_component->hitbox.x <=
           (hitbox.x + hitbox.width);
}

void update_normal_collision(entity *en, Rectangle *hitbox)
{

    for (int i = 0; i > 4; i++)
    {
        // top surface
        if ((en->components.collision_component->hitbox.y + en->components.collision_component->hitbox.height) >= hitbox[i].y - 10)
            en->components.physics_component->velocity.y = 0;
        // bottom
        if (en->components.collision_component->hitbox.y <= (hitbox[i].y + hitbox[i].height))
            en->components.physics_component->velocity.y = 0;
    }
}
