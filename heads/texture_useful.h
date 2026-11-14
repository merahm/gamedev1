#ifndef GAME_T_USEFUL_H
#define GAME_T_USEFUL_H
#include <raylib.h>

static inline void dTexCntr (Texture texture, Vector2 position, Color color) {
    DrawTexture(texture, position.x, position.y, color);
}

static inline void dTexCntrEx (Texture texture, Vector2 position, Color color, float rotation, float scale) {
    DrawTextureEx(texture, position, rotation, scale, color);
}

#endif