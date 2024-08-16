/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "includes.h"

void find_rescue_elec(kidiot_t *kidiot, int x, int y)
{
    size_t i = 0;

    while (kidiot->baby->electric[i].floor != -1) {
        if ((int)kidiot->baby->electric[i].pos.x == y &&
            (int)kidiot->baby->electric[i].pos.y == x &&
            kidiot->mom->floor == kidiot->baby->electric[i].floor) {
            break;
        }
        i++;
    }
    if (kidiot->baby->electric[i].floor == -1)
        return;
    kidiot->baby->electric[i].is_fixed = true;
}

void find_elec(kidiot_t *kidiot, int x, int y, float time)
{
    size_t i = 0;

    for (i = 0; kidiot->baby->electric[i].floor != -1; i++) {
        if ((int)kidiot->baby->electric[i].pos.x == y &&
            (int)kidiot->baby->electric[i].pos.y == x &&
            kidiot->baby->floor == kidiot->baby->electric[i].floor) {
            break;
        }
    }
    if (kidiot->baby->electric[i].floor == -1
        || kidiot->baby->electric[i].is_fixed)
        return;
    kidiot->baby->electric[i].time -= time;
    DrawRectangle(GetScreenWidth() / 5, GetScreenHeight() / 100, kidiot->baby->
    electric[i].time * (GetScreenWidth() / 100), GetScreenHeight() / 25,YELLOW);
    if (kidiot->baby->electric[i].time < 0)
        kidiot->baby->hp -= 100;
}

void find_rescue_cactus(kidiot_t *kidiot, int x, int y)
{
    size_t i = 0;

    while (kidiot->baby->cactus[i].floor != -1) {
        if ((int)kidiot->baby->cactus[i].pos.x == y &&
            (int)kidiot->baby->cactus[i].pos.y == x &&
            kidiot->mom->floor == kidiot->baby->cactus[i].floor)
            break;
        i++;
    }
    if (kidiot->baby->cactus[i].floor == -1)
        return;
    kidiot->baby->cactus[i].is_cut = true;
}

void find_cactus(kidiot_t *kidiot, int x, int y, float time)
{
    size_t i = 0;

    while (kidiot->baby->cactus[i].floor != -1) {
        if ((int)kidiot->baby->cactus[i].pos.x == y &&
            (int)kidiot->baby->cactus[i].pos.y == x &&
            kidiot->baby->floor == kidiot->baby->cactus[i].floor)
            break;
        i++;
    }
    if (kidiot->baby->cactus[i].floor == -1 || kidiot->baby->cactus[i].is_cut)
        return;
    if (kidiot->baby->cactus[i].time <= 0 && kidiot->keys[4] == 1) {
        kidiot->baby->hp -= 10;
         kidiot->baby->cactus[i].time = 2;
    }
    kidiot->baby->cactus[i].time -= time;
}
