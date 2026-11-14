#ifndef GAME_PLAYER_POSITION_H
#define GAME_PLAYER_POSITION_H
#include <raylib.h>
#include <raymath.h>

Vector2 playerPosition = { 0.0f, 0.0f };
float playerSpeed = 100.0f;

void plyrMv(void) {
    float h = IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT);
    float v = IsKeyDown(KEY_DOWN)  - IsKeyDown(KEY_UP);

    Vector2 dir = { h - v, v };      // Left/Right stay horizontal, Up/Down slide along a 45° diagonal
    dir = Vector2Normalize(dir);     // constant speed, (0,0) if no input

    float step = playerSpeed * GetFrameTime();
    playerPosition.x += dir.x * step;
    playerPosition.y += dir.y * step;
}

#endif
