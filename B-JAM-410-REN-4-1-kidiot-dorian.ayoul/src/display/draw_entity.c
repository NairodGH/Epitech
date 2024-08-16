/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "includes.h"

static void draw_baby_split(kidiot_t *kidiot, Rectangle dest)
{
    Vector2 orig = {0, 0};

    if (kidiot->keys[3])
        return DrawTexturePro(kidiot->textures[0],
        (Rectangle){16, 16 + (int)(GetTime() * 10) % 3 * 87, 61, 80},
            dest, orig, 0, RAYWHITE);
    if (kidiot->keys[4])
        return DrawTexturePro(kidiot->textures[0],
        (Rectangle){13, 286 + (int)(GetTime() * 10) % 3 * 86, 85, 79},
            dest, orig, 0, RAYWHITE);
    DrawTexturePro(kidiot->textures[0], (Rectangle){16, 103, 61, 80},
        dest, orig, 0, RAYWHITE);
}

void draw_baby(kidiot_t *kidiot, Rectangle dest)
{
    Vector2 orig = {0, 0};

    if (kidiot->keys[0])
        return DrawTexturePro(kidiot->textures[0],
        (Rectangle){800, 8 + (int)(GetTime() * 10) % 3 * 87, 61, 78},
            dest, orig, 0, RAYWHITE);
    if (kidiot->keys[1])
        return DrawTexturePro(kidiot->textures[0],
        (Rectangle){283, 17 + (int)(GetTime() * 10) % 3 * 87, 61, 78},
            dest, orig, 0, RAYWHITE);
    if (kidiot->keys[2])
        return DrawTexturePro(kidiot->textures[0],
        (Rectangle){548, 17 + (int)(GetTime() * 10) % 3 * 87, 61, 80},
            dest, orig, 0, RAYWHITE);
    draw_baby_split(kidiot, dest);
}

static void draw_mom_split(kidiot_t *kidiot, Rectangle dest)
{
    Vector2 orig = {0, 0};

    if (kidiot->keys[8])
        return DrawTexturePro(kidiot->textures[1],
        (Rectangle){29, 9 + (int)(GetTime() * 10) % 3 * 124, 43, 116},
            dest, orig, 0, RAYWHITE);
    if (kidiot->keys[9])
        return DrawTexturePro(kidiot->textures[1],
        (Rectangle){5, 392 + (int)(GetTime() * 10) % 3 * 124, 98, 116},
            dest, orig, 0, RAYWHITE);
    DrawTexturePro(kidiot->textures[1], (Rectangle){29, 133, 43, 116},
        dest, orig, 0, RAYWHITE);
}

void draw_mom(kidiot_t *kidiot, Rectangle dest)
{
    Vector2 orig = {0, 0};

    if (kidiot->keys[5])
        return DrawTexturePro(kidiot->textures[1],
        (Rectangle){880, 10 + (int)(GetTime() * 10) % 3 * 124, 52, 116},
            dest, orig, 0, RAYWHITE);
    if (kidiot->keys[6])
        return DrawTexturePro(kidiot->textures[1],
        (Rectangle){306, 10 + (int)(GetTime() * 10) % 3 * 124, 52, 116},
            dest, orig, 0, RAYWHITE);
    if (kidiot->keys[7])
        return DrawTexturePro(kidiot->textures[1],
        (Rectangle){600, 9 + (int)(GetTime() * 10) % 3 * 124, 40, 116},
            dest, orig, 0, RAYWHITE);
    draw_mom_split(kidiot, dest);
}