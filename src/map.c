#include "map.h"

tmx_map *map_(const char *path)
{
    tmx_map *map;
    map = LoadTMX(path);
    return map;
}

//fix this function

Rectangle *get_objects_from_layer(tmx_map *map, char *layer_name, int object_amount)
{
    Rectangle *obj = malloc(object_amount * sizeof(Rectangle));
    
    tmx_layer *layer = tmx_find_layer_by_name(map, layer_name);
    tmx_object *head = layer->content.objgr->head;

    for(int i = 0; i < object_amount; i++) {
        obj[i].x = head->x;
        obj[i].y = head->y;
        obj[i].width = head->width;
        obj[i].height = head->height;

        head = head->next;
    }
    return obj;
}

void map_update()
{
}

void map_render(tmx_map *map)
{
    DrawTMX(map, 0, 0, RAYWHITE);
}