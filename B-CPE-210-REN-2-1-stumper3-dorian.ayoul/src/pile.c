/*
** EPITECH PROJECT, 2021
** sandpile
** File description:
** Sandpile
*/

#include "my.h"
#include "sandpile.h"

static pos_t middle(pos_t max)
{
    pos_t mid = {(max.x - 1) / 2, (max.y - 1) / 2};

    return mid;
}

static int case_at(char **map, pos_t pos, char *base)
{
    char c = map[pos.y][pos.x];

    for (unsigned int i = 0; i < 4; i++) {
        if (base[i] == c) {
            return i;
        }
    }
    return 0;
}

static void chainreact(char **map, pos_t max, pos_t pos, char *base)
{
    pos.x += 1;
    if (pos.x < max.x) {
        addcase(map, max, pos, base);
    }
    pos.x -= 2;
    if (pos.x >= 0) {
        addcase(map, max, pos, base);
    }
    pos.x += 1;
    pos.y += 1;
    if (pos.y < max.y) {
        addcase(map, max, pos, base);
    }
    pos.y -= 2;
    if (pos.y >= 0) {
        addcase(map, max, pos, base);
    }
}

void addcase(char **map, pos_t max, pos_t pos, char *base)
{
    int casenum = case_at(map, pos, base);

    if (casenum == 3) {
        map[pos.y][pos.x] = base[0];
        chainreact(map, max, pos, base);
    } else {
        map[pos.y][pos.x] = base[casenum + 1];
    }
}

void sandpile(char **map, int linenum, char *base, int iterations)
{
    pos_t max = {strlen(map[0]), linenum};
    pos_t mid = middle(max);

    for (unsigned int i = 0; i < iterations; i++) {
        addcase(map, max, mid, base);
    }
    for (unsigned int j = 0; j < linenum; j++) {
        printf("%s\n", map[j]);
        free(map[j]);
    }
    free(map);
}
