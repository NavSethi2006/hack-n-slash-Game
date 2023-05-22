#include "map.h"

tmx_map *map;

void map_() {
    map = LoadTMX("/home/navin/programming/hack-n-slash-Game/src/assets/map/map1.tmx");
}

void map_update() {
    tmx_layer layer;
    
}

void map_render() {
    DrawTMX(map, 300, 300, RAYWHITE);
}