#ifndef GAME_CAMERA_H
#define GAME_CAMERA_H
#include <raylib.h>

Camera2D camera = (Camera2D) {
    .offset = (Vector2) {0.0f, 0.0f},
    .target = (Vector2) {0.0f, 0.0f},
    .rotation = 0.0f,
    .zoom = 1.0f
};
const float cameraSpeed = 200.0f;

#endif
