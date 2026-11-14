#include <stdlib.h>
#include "heads/camera.h"
#include "heads/window.h"
#include "heads/debug_grid.h"
#include "heads/cam_movement.h"
#include "heads/player_position.h"
#include "heads/texture_useful.h"
#include "heads/texture_autoload.h"
#include "heads/debug_text.h"
#include "heads/texture_animate.h"

int main(void) {
    InitWindow(windowWidth, windowHeight, windowTitle);
    char* paramschr[3] = {"../sprites/box-1-3264.png", "../sprites/box-2-3264.png", "../sprites/box-3-3264.png"};
    float* dtracker = malloc(sizeof(float));
    DrawAnimationParameters params = dAniParam(
        paramschr,
        3,
        0.5f,
        dtracker,
        true
    );
    while (!WindowShouldClose()) {
        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(RAYWHITE);
        dGrid();
        camMvPlyr();
        plyrMv();
        dAni(params, playerPosition, 0.0f, 1.0f, WHITE);
        dDebugInfo();
        EndMode2D();
        EndDrawing();
    }
    return 0;
}
