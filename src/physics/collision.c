#include "collision.h"

bool is_entity_hit(entity *temp_1, entity *temp_2) {
    if(CheckCollisionRecs(temp_1->components.collision_component->AABB, 
                          temp_2->components.collision_component->AABB)) {
        return true;
        
    }
}