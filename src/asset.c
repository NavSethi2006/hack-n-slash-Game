#include "asset.h"

Texture2D player_tex;

void load_assets() {
    player_tex = LoadTexture("/home/navin/programming/hack-n-slash-Game/src/assets/characters/player/player.png");
    
}

Texture2D player_texture() {
    return player_tex;
}

void unload_assets() {
    UnloadTexture(player_tex);
}