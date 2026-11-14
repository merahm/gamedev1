#ifndef GAME_TEXTURE_ANIMATE_H
#define GAME_TEXTURE_ANIMATE_H
#include "texture_autoload.h"
#include "time_useful.h"
#include <math.h>
#include "typeconv_useful.h"

void dAni(DrawAnimationParameters dAniPrm, Vector2 pos, float rotation, float scale, Color tint)
{
    if (!dAniPrm.dtracker || !dAniPrm.paths || dAniPrm.num_paths == 0 || dAniPrm.duration <= 0.0f) return;
    *dAniPrm.dtracker = cntr(*dAniPrm.dtracker);
    float total = dAniPrm.duration * (float)dAniPrm.num_paths;   // length of the whole animation
    if (dAniPrm.loop) {
        // fmodf wraps the timer but keeps the leftover time, so the loop doesn't drift
        *dAniPrm.dtracker = fmodf(*dAniPrm.dtracker, total);
    } else if (*dAniPrm.dtracker >= total) {
        // stop on the last frame
        *dAniPrm.dtracker = total;
    }
    size_t currentTexture = (size_t)floorf(*dAniPrm.dtracker / dAniPrm.duration);
    if (currentTexture >= dAniPrm.num_paths) currentTexture = dAniPrm.num_paths - 1;  // covers dtracker == total
    DrawImageCached(dAniPrm.paths[currentTexture], pos, rotation, scale, tint);
}

#endif