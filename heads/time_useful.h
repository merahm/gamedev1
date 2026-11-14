#ifndef GAME_COUNTDOWN_H
#define GAME_COUNTDOWN_H
#include <raylib.h>

static inline float cdown (float cdtrack) {
    return cdtrack - GetFrameTime();
}

static inline float cntr (float ctrack) {
    return ctrack + GetFrameTime();
}

#endif