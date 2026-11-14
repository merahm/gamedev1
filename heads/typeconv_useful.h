#ifndef GAME_CLITERAL_USEFUL_H
#define GAME_CLITERAL_USEFUL_H
#include <raylib.h>

static inline Vector2 vec(float x, float y) {
    return (Vector2){x,y};
}

static inline Rectangle rect(float x, float y, float w, float h) {
    return (Rectangle){x,y,w,h};
}

static inline Color clr(float r, float g, float b, float a) {
    return (Color){r,g,b,a};
}

#endif