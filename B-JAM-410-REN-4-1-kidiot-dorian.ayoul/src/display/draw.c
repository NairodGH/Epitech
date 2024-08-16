/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "includes.h"

static void draw_entity(kidiot_t *kidiot, int wd, int height, bool floor)
{
    char **map = (floor == false ? kidiot->first_floor : kidiot->second_floor);
    Vector2 size = {wd / strlen(map[0]) / 2,
        height / get_map_size(map)};
    Vector2 baby = {kidiot->baby->pos.y * (wd / strlen(map[0]) / 2),
        kidiot->baby->pos.x * (height / get_map_size(map))};
    Vector2 mom = {kidiot->mom->pos.y * (wd / strlen(map[0]) / 2),
        kidiot->mom->pos.x * (height / get_map_size(map))};

    if (kidiot->baby->floor == 1) {
        baby.x += wd / 2;
        draw_baby(kidiot, (Rectangle){baby.x, baby.y, size.x, size.y});
    }
    if (kidiot->mom->floor == 1 && kidiot->baby->vacuum->time <= 0) {
        mom.x += wd / 2;
        draw_mom(kidiot, (Rectangle){mom.x, mom.y, size.x, size.y});
    }
}

static void spl_draw_second(kidiot_t *kidiot, int wd, int height, Vector2 size)
{
    Vector2 pos = {(wd / 2), 0};

    for (size_t x = 0; kidiot->second_floor[x] != NULL; x++) {
        for (size_t y = 0; kidiot->second_floor[x][y] != '\0'; y++) {
            draw_misc(kidiot, kidiot->second_floor[x][y],
            (Rectangle){pos.x, pos.y, size.x, size.y},
            (pos_t){(Vector2){x, y}, 1});
            pos.x += wd / strlen(kidiot->second_floor[x]) / 2;
        }
        pos.x = (wd / 2);
        pos.y += height / get_map_size(kidiot->second_floor);
    }
    draw_entity(kidiot, wd, height, true);
}

void draw_second_map(kidiot_t *kidiot, int wd, int height)
{
    Vector2 pos = {(wd / 2), 0};
    Vector2 size =
        {wd / strlen(kidiot->second_floor[0]) / 2,
        height / get_map_size(kidiot->second_floor)};

    for (size_t x = 0; kidiot->second_floor[x] != NULL; x++) {
        for (size_t y = 0; kidiot->second_floor[x][y] != '\0'; y++) {
            DrawTexturePro(kidiot->textures[2], (Rectangle){877, 0, 73, 58},
            (Rectangle){pos.x, pos.y, size.x, size.y},
            (Vector2){0, 0}, 0, RAYWHITE);
            pos.x += wd / strlen(kidiot->second_floor[x]) / 2;
        }
        pos.x = (wd / 2);
        pos.y += height / get_map_size(kidiot->second_floor);
    }
    spl_draw_second(kidiot, wd, height, size);
}

void split_draw_map(kidiot_t *kidiot, int height, int wd, Vector2 size)
{
    Vector2 pos = {0, 0};
    Vector2 baby = {kidiot->baby->pos.y *
        (wd / strlen(kidiot->first_floor[0]) / 2),
        kidiot->baby->pos.x * (height / get_map_size(kidiot->first_floor))};

    for (size_t x = 0; kidiot->first_floor[x] != NULL; x++) {
        for (size_t y = 0; kidiot->first_floor[x][y] != '\0'; y++) {
            draw_misc(kidiot, kidiot->first_floor[x][y],
            (Rectangle){pos.x, pos.y, size.x, size.y},
            (pos_t){(Vector2){x, y}, 0});
            pos.x += wd / strlen(kidiot->first_floor[x]) / 2;
        }
        pos.x = 0;
        pos.y += height / get_map_size(kidiot->first_floor);
    }
    draw_second_map(kidiot, wd, height);
    if (kidiot->baby->floor == 0)
        draw_baby(kidiot, (Rectangle){baby.x, baby.y, size.x, size.y});
}

void draw_map(kidiot_t *kidiot, int height, int wd)
{
    Vector2 pos = {0, 0};
    Vector2 size = {wd / strlen(kidiot->first_floor[0]) / 2,
        height / get_map_size(kidiot->first_floor)};
    Vector2 mom = {kidiot->mom->pos.y *
        (wd / strlen(kidiot->first_floor[0]) / 2),
        kidiot->mom->pos.x * (height / get_map_size(kidiot->first_floor))};
    
    for (size_t x = 0; kidiot->first_floor[x] != NULL; x++) {
        for (size_t y = 0; kidiot->first_floor[x][y] != '\0'; y++) {
            DrawTexturePro(kidiot->textures[2], (Rectangle){877, 0, 73, 58},
            (Rectangle){pos.x, pos.y, size.x, size.y},
            (Vector2){0, 0}, 0, RAYWHITE);
            pos.x += wd / strlen(kidiot->first_floor[x]) / 2;
        }
        pos.x = 0;
        pos.y += height / get_map_size(kidiot->first_floor);
    }
    split_draw_map(kidiot, height, wd, size);
    if (kidiot->mom->floor == 0 && kidiot->baby->vacuum->time <= 0)
        draw_mom(kidiot, (Rectangle){mom.x, mom.y, size.x, size.y});
}