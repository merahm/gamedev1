#ifndef GAME_MOVEMENT_H
#define GAME_MOVEMENT_H
#include <raylib.h>
#include "camera.h"
#include <raymath.h>

void movement (void) {
    float h = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
    float v = IsKeyDown(KEY_DOWN)  - IsKeyDown(KEY_UP);

    Vector2 dir = { h - v, v };      // Left/Right stay horizontal, Up/Down slide along a 45° diagonal
    dir = Vector2Normalize(dir);     // constant speed, (0,0) if no input

    float step = cameraSpeed * GetFrameTime();
    camera.target.x += dir.x * step;
    camera.target.y += dir.y * step;
}

#endif