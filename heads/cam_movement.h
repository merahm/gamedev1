#ifndef GAME_MOVEMENT_H
#define GAME_MOVEMENT_H
#include <raylib.h>
#include "camera.h"
#include "player_position.h"
#include "window.h"

void camMvPlyr (void) {
    camera.target.x = playerPosition.x - windowWidth / 2;
    camera.target.y = playerPosition.y - windowHeight / 2;
}

#endif