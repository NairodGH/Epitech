/*
** EPITECH PROJECT, 2022
** gest_clock.c
** File description:
** gest_clock
*/

#include "includes.h"

static void check_microwave(kidiot_t *play, char **map, float time)
{
    if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'M'
        && play->keys[4] == 1)
        play->baby->microwave->interaction = true;
    if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'M'
        && play->baby->microwave->is_open && play->baby->microwave->time <= 0) {
        play->baby->speed = 0.13;
        play->baby->microwave->is_open = false;
    }
    else if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'M' &&
        play->baby->microwave->is_open && play->baby->microwave->interaction) {
        DrawRectangle(GetScreenWidth() / 5, GetScreenHeight() / 100,
        play->baby->microwave->time * (GetScreenWidth() / 100),
        GetScreenHeight() / 25, LIGHTGRAY);
        play->baby->microwave->time -= time;
    } else {
        play->baby->microwave->time = 3;
        play->baby->microwave->interaction = false;
    }
}

static void check_oven(kidiot_t *play, char **map, float time)
{
    if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'O'
        && play->keys[4] == 1)
        play->baby->oven->interaction = true;
    if (play->baby->oven->is_burning == true)
        play->baby->oven->time_burn -= time;
    if (play->baby->oven->time <= 0) {
        play->baby->oven->is_burning = true;
        play->baby->oven->time = 3;
        play->baby->oven->is_open = false;
    } else if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'O'
        && play->baby->oven->is_open && play->baby->oven->interaction) {
        DrawRectangle(GetScreenWidth() / 5, GetScreenHeight() / 100,
        play->baby->oven->time * (GetScreenWidth() / 100),
        GetScreenHeight() / 25, DARKGRAY);
        play->baby->oven->time -= time;
    } else {
        play->baby->oven->time = 3;
        play->baby->oven->interaction = false;
    }
    check_microwave(play, map, time);
}

static void check_mom_rescue_split(char **map, kidiot_t *play, int keys[])
{
    if (map[(int)play->mom->pos.x][(int)play->mom->pos.y] == 'B'
        && keys[9] == 1 && play->mom->floor == play->baby->floor)
        play->baby->bathtub->is_full[play->baby->floor] = false;
    if (map[(int)play->mom->pos.x][(int)play->mom->pos.y] == 'F'
        && keys[9] == 1)
        play->baby->fridge->is_open = false;
    if (map[(int)play->mom->pos.x][(int)play->mom->pos.y] == 'O'
        && keys[9] == 1)
        play->baby->oven->is_open = false;
    if (map[(int)play->mom->pos.x][(int)play->mom->pos.y] == 'M'
        && keys[9] == 1)
        play->baby->microwave->is_open = false;
    if (map[(int)play->mom->pos.x][(int)play->mom->pos.y] == 'C'
        && keys[9] == 1)
        find_rescue_cactus(play, (int)play->mom->pos.x, (int)play->mom->pos.y);
    if (map[(int)play->mom->pos.x][(int)play->mom->pos.y] == 'E'
        && keys[9] == 1)
        find_rescue_elec(play, (int)play->mom->pos.x, (int)play->mom->pos.y);
}

static void check_mom_rescue(kidiot_t *play, int keys[])
{
    char **map = play->mom->floor == 0 ?
        play->first_floor : play->second_floor;

    if ((int)play->mom->pos.x == (int)play->baby->pos.x && keys[9] == 1
        && (int)play->mom->pos.y == (int)play->baby->pos.y
        && play->baby->floor == play->mom->floor) {
        play->baby->oven->is_burning = false;
        play->baby->speed = 0.08;
    }
    check_mom_rescue_split(map, play, keys);
    if ((int)play->mom->pos.x == play->tp->pos_toilet[0].x &&
        (int)play->mom->pos.y == play->tp->pos_toilet[0].y && keys[9] == 1)
        play->tp->is_open[0] = false;
    if ((int)play->mom->pos.x == play->tp->pos_toilet[1].x &&
        (int)play->mom->pos.y == play->tp->pos_toilet[1].y && keys[9] == 1)
        play->tp->is_open[1] = false;
}

void gest_clock(kidiot_t *play, int keys[])
{
    char **map = play->baby->floor == 0 ?
        play->first_floor : play->second_floor;
    float time = GetFrameTime();

    play->game_time -= time;
    check_mom_rescue(play, keys);
    if (play->baby->fridge->time > 0)
        play->baby->fridge->time -= time;
    else
        play->baby->fridge->time = 0;
    if (map[(int)play->baby->pos.x][(int)play->baby->pos.y] == 'E')
        find_elec(play, (int)play->baby->pos.x, (int)play->baby->pos.y, time);
    else {
        for (size_t i = 0; play->baby->electric[i].floor != -1; i++)
            play->baby->electric[i].time = 5;
    }
    gest_clock_split(map, play, keys, time);
    check_oven(play, map, time);
}