#ifndef GAME_TEXTURE_AUTOLOAD_H
#define GAME_TEXTURE_AUTOLOAD_H
#include <raylib.h>
#include <string.h>
#include "hashstr_useful.h"

#include "raylib.h"
#include <string.h>   // strcmp, strncpy, memset, strlen
#include <stdbool.h>  // bool

#define TABLE_SIZE   256   // must be a power of two
#define MAX_PATH_LEN 256

// Every slot is in one of three states.
// SLOT_EMPTY must be 0 so the zero-initialized static table starts all empty.
typedef enum {
    SLOT_EMPTY = 0,   // never used: a lookup can stop here, the path isn't in the table
    SLOT_USED,        // holds a loaded texture
    SLOT_DELETED      // tombstone: used to hold a texture, keep probing past it
} SlotState;

typedef struct {
    SlotState state;
    char      path[MAX_PATH_LEN];
    Texture2D tex;
} Slot;

static Slot table[TABLE_SIZE];

// Looks for `path` in the table. Returns its slot, or NULL if it isn't loaded.
// Used by both GetTexture and RemoveTexture, so the probing logic lives in one place.
static Slot *FindSlot(const char *path)
{
    unsigned int index = hashStr(path) & (TABLE_SIZE - 1);

    for (int i = 0; i < TABLE_SIZE; i++) {
        Slot *slot = &table[index];

        // A truly empty slot ends the search: if the path were stored,
        // it would have been placed at or before this point in the chain.
        if (slot->state == SLOT_EMPTY) return NULL;

        // Only USED slots can match. DELETED slots are skipped, but we keep going,
        // because the entry we want might be stored further along the chain.
        if (slot->state == SLOT_USED && strcmp(slot->path, path) == 0) return slot;

        index = (index + 1) & (TABLE_SIZE - 1);
    }

    return NULL;  // went all the way around the table without finding it
}

// Returns the texture for `path`, loading it first if it isn't loaded yet.
Texture2D GetTexture(const char *path)
{
    if (strlen(path) >= MAX_PATH_LEN) {
        TraceLog(LOG_ERROR, "Texture path too long: %s", path);
        return (Texture2D){0};
    }

    // Already loaded? Return it.
    Slot *found = FindSlot(path);
    if (found) return found->tex;

    // Not loaded. FindSlot just confirmed the path isn't in the table, so we can
    // safely put it in the first slot along its probe chain that isn't in use.
    // That is either a never-used slot or a tombstone, so deleted slots get reused.
    unsigned int index = hashStr(path) & (TABLE_SIZE - 1);

    for (int i = 0; i < TABLE_SIZE; i++) {
        Slot *slot = &table[index];

        if (slot->state != SLOT_USED) {
            slot->tex   = LoadTexture(path);
            slot->state = SLOT_USED;
            strncpy(slot->path, path, MAX_PATH_LEN - 1);
            slot->path[MAX_PATH_LEN - 1] = '\0';
            return slot->tex;
        }

        index = (index + 1) & (TABLE_SIZE - 1);
    }

    TraceLog(LOG_ERROR, "Texture cache full, can't load %s", path);
    return (Texture2D){0};
}

// Unloads one texture and frees its slot. Returns true if it was loaded.
bool RemoveTexture(const char *path)
{
    Slot *slot = FindSlot(path);
    if (!slot) return false;          // wasn't loaded, nothing to do

    UnloadTexture(slot->tex);         // free the GPU memory
    slot->state = SLOT_DELETED;       // tombstone, NOT empty, so other probe chains stay intact
    slot->path[0] = '\0';
    slot->tex = (Texture2D){0};
    return true;
}

void DrawImageCached(const char *path, Vector2 pos, float rotation, float scale, Color tint)
{
    DrawTextureEx(GetTexture(path), pos, rotation, scale, tint);
}

// Unloads everything and resets the whole table, tombstones included.
void UnloadAllTextures(void)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].state == SLOT_USED) UnloadTexture(table[i].tex);
    }
    memset(table, 0, sizeof(table));  // every slot back to SLOT_EMPTY (0)
}
#endif