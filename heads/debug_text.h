#ifndef GAME_DEBUG_TEXT_H
#define GAME_DEBUG_TEXT_H
#include "player_position.h"
#include "camera.h"
#include "debug_var.h"

static inline void dDebugInfo (void) {
    Vector2 topleft = GetScreenToWorld2D((Vector2){0.0f, 0.0f}, camera);
    DrawText(
        TextFormat("D:%d\nX:%.2f,Y:%.2f\nF:%d", debugMode, playerPosition.x, playerPosition.y, GetFPS()),
        topleft.x, topleft.y, 30, BLACK);
}

#endif