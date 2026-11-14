#include "heads/camera.h"
#include "heads/window.h"
#include "heads/debug_grid.h"
#include "heads/cam_movement.h"
#include "heads/player_position.h"
#include "heads/texture_useful.h"
#include "heads/texture_autoload.h"
#include "heads/debug_text.h"

int main(void) {
    InitWindow(windowWidth, windowHeight, windowTitle);
    while (!WindowShouldClose()) {
        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(RAYWHITE);
        drawGrid();
        cam_movement_player();
        player_movement();
        DrawImageCached("../sprites/box-1-3264.png", playerPosition, 0.0f, 1.0f, WHITE);
        dDebugInfo();
        EndMode2D();
        EndDrawing();
    }
    return 0;
}
