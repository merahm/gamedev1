#ifndef GAME_HASHSTR_USEFUL_H
#define GAME_HASHSTR_USEFUL_H

static unsigned int hashStr(const char *str)
{
    unsigned int hash = 5381;
    int c;
    while ((c = (unsigned char)*str++)) {
        hash = hash * 33 + c;
    }
    return hash;
}

#endif