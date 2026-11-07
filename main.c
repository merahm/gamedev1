#include "heads/camera.h"
#include "heads/window.h"
#include "heads/debug_grid.h"
#include "heads/movement.h"

int main(void) {
    InitWindow(windowWidth, windowHeight, windowTitle);
    while (!WindowShouldClose()) {
        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(RAYWHITE);
        drawGrid();
        movement();
        EndMode2D();
        EndDrawing();
    }
    return 0;
}
