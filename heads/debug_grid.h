#ifndef GAME_DEBUG_GRID_H
#define GAME_DEBUG_GRID_H
#include <raylib.h>
#include <math.h>
#include "window.h"

const int debug_gridSpacing = 32;

void drawGrid (void) {
    Vector2 corners[4] = {
        GetScreenToWorld2D((Vector2){ 0,           0            }, camera),
        GetScreenToWorld2D((Vector2){ windowWidth, 0            }, camera),
        GetScreenToWorld2D((Vector2){ windowWidth, windowHeight }, camera),
        GetScreenToWorld2D((Vector2){ 0,           windowHeight }, camera),
    };

    float minX = corners[0].x, maxX = corners[0].x;
    float minY = corners[0].y, maxY = corners[0].y;
    for (int i = 1; i < 4; i++) {
        if (corners[i].x < minX) minX = corners[i].x;
        if (corners[i].x > maxX) maxX = corners[i].x;
        if (corners[i].y < minY) minY = corners[i].y;
        if (corners[i].y > maxY) maxY = corners[i].y;
    }

    float spacing = (float)debug_gridSpacing;
    float thick = 1.0f / camera.zoom;   // keeps lines 1 pixel wide on screen

    // Horizontal lines at every multiple of spacing
    int r0 = (int)floorf(minY / spacing), r1 = (int)ceilf(maxY / spacing);
    for (int r = r0; r <= r1; r++) {
        float y = r * spacing;
        DrawLineEx((Vector2){ minX, y }, (Vector2){ maxX, y }, thick, RED);
    }

    // Slanted lines: every point on one satisfies x + y = k * spacing
    int k0 = (int)floorf((minX + minY) / spacing);
    int k1 = (int)ceilf((maxX + maxY) / spacing);
    for (int k = k0; k <= k1; k++) {
        float s = k * spacing;
        DrawLineEx((Vector2){ s - maxY, maxY },   // bottom of the visible area
                   (Vector2){ s - minY, minY },   // top, shifted right by the same amount
                   thick, RED);
    }
}

#endif
