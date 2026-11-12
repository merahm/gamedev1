#ifndef GAME_DEBUG_TEXT_H
#define GAME_DEBUG_TEXT_H
#include "player_position.h"

static inline void dDebugInfo (void) {
    DrawFPS(playerPosition.x, playerPosition.y);
    DrawText(TextFormat("X:%d,Y:%d", playerPosition.x, playerPosition.y), playerPosition.x, playerPosition.y, 20, BLUE);
}

#endif