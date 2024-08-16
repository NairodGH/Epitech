/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "includes.h"

static tp_t *init_tp(char **first_floor, char **second_floor)
{
    tp_t *tp = malloc(sizeof(tp_t) * 1);

    if (!tp)
        return NULL;
    tp->pos_stairs[0] = find_spawn_pos('S', first_floor);
    tp->pos_stairs[1] = find_spawn_pos('S', second_floor);
    tp->pos_toilet[0] = find_spawn_pos('W', first_floor);
    tp->pos_toilet[1] = find_spawn_pos('W', second_floor);
    tp->is_open[0] = true;
    tp->is_open[1] = true;
    return tp;
}

static void init_obs_split(baby_t *baby)
{
    microwave_t *microwave = malloc(sizeof(microwave_t) * 1);
    oven_t *oven = malloc(sizeof(oven_t) * 1);
    vacuum_t *vacuum = malloc(sizeof(vacuum_t) * 1);

    microwave->time = 3;
    microwave->is_open = true;
    microwave->interaction = false;
    vacuum->already_use = false;
    vacuum->time = 0;
    oven->interaction = false;
    oven->is_open = true;
    oven->is_burning = false;
    oven->time = 3;
    oven->time_burn = 1;
    baby->floor = 0;
    baby->hp = 100;
    baby->oven = oven;
    baby->vacuum = vacuum;
    baby->microwave = microwave;
}

static void init_obs(baby_t *baby)
{
    frigde_t *frigde = malloc(sizeof(frigde_t) * 1);
    bathtub_t *bathtub = malloc(sizeof(bathtub_t) * 1);

    frigde->is_open = true;
    frigde->interaction = false;
    frigde->time = 0;
    bathtub->is_full[0] = false;
    bathtub->is_full[1] = false;
    bathtub->time = 4;
    bathtub->interaction = false;
    baby->fridge = frigde;
    baby->bathtub = bathtub;
    init_obs_split(baby);
    baby->speed = 0.08;
}

static void init_kidiot_split(kidiot_t *kidiot, baby_t *baby, mom_t *mom, int t)
{
    cactus_t *cactus = init_cactus(kidiot);
    electric_t *electric = init_elec(kidiot);

    kidiot->game_time = t;
    baby->cactus = cactus;
    baby->electric = electric;
    kidiot->baby = baby;
    kidiot->mom = mom;
    kidiot->use = LoadSound("ressources/use.mp3");
    kidiot->textures[0] = LoadTexture("ressources/maggie.png");
    kidiot->textures[1] = LoadTexture("ressources/marge.png");
    kidiot->textures[2] = LoadTexture("ressources/misc.png");
    kidiot->textures[3] = LoadTexture("ressources/electricity.png");
}

kidiot_t *init_kidiot(char **first_floor, char **second_floor, int time)
{
    kidiot_t *kidiot = malloc(sizeof(kidiot_t) * 1);
    baby_t *baby = malloc(sizeof(baby_t) * 1);
    mom_t *mom = malloc(sizeof(mom_t) * 1);

    if (!kidiot || !baby || !mom)
        return NULL;
    init_obs(baby);
    mom->floor = 0;
    mom->speed = 0.08;
    kidiot->first_floor = first_floor;
    kidiot->second_floor = second_floor;
    baby->pos = find_spawn_pos('b', kidiot->first_floor);
    mom->pos = find_spawn_pos('m', kidiot->first_floor);
    baby->temp_pos = baby->pos;
    mom->temp_pos = mom->pos;
    kidiot->tp = init_tp(kidiot->first_floor, kidiot->second_floor);
    if (!kidiot->tp)
        return NULL;
    init_kidiot_split(kidiot, baby, mom, time);
    return kidiot;
}
