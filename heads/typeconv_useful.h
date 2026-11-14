#ifndef GAME_CLITERAL_USEFUL_H
#define GAME_CLITERAL_USEFUL_H
#include <raylib.h>

typedef struct {
    char** paths;
    size_t num_paths;
    float duration;
    float* dtracker;
    bool loop;
} DrawAnimationParameters;

static inline Vector2 vec(float x, float y) {
    return (Vector2){x,y};
}

static inline Rectangle rect(float x, float y, float w, float h) {
    return (Rectangle){x,y,w,h};
}

static inline Color clr(float r, float g, float b, float a) {
    return (Color){r,g,b,a};
}

static inline DrawAnimationParameters dAniParam (char** paths, size_t num_paths, float duration, float* dtracker, bool loop) {
    return (DrawAnimationParameters){paths,num_paths,duration,dtracker,loop};
}

#endif