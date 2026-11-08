#include "heads/camera.h"
#include "heads/window.h"
#include "heads/debug_grid.h"
#include "heads/cam_movement.h"
#include "heads/player_position.h"

int main(void) {
    InitWindow(windowWidth, windowHeight, windowTitle);
    while (!WindowShouldClose()) {
        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(RAYWHITE);
        drawGrid();
        cam_movement_player();
        player_movement();
        DrawCircle(playerPosition.x, playerPosition.y, 20.0f, BLACK);
        EndMode2D();
        EndDrawing();
    }
    return 0;
}
