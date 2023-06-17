#include "tmx/raylib-tmx.h"
#include "stdio.h"
#include "stdlib.h"
#include "physics/collision.h"


tmx_map *map_(const char* path);

Rectangle *get_objects_from_layer(tmx_map *map, char *layer_name, int object_amount);

polyline *get_lines_from_layer(tmx_map *map, char *layer_name, int object_amount);

void map_update();

void map_render(tmx_map *map);