/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "includes.h"

static void split_check_death(kidiot_t *player, char **map)
{
    if (player->baby->oven->is_burning && player->baby->oven->time_burn < 0) {
        player->baby->hp -= 5;
        player->baby->oven->time_burn = 1;
    }
    if (map[(int)player->baby->pos.x][(int)player->baby->pos.y] == 'F'
        && player->keys[4] == 1)
        player->baby->fridge->interaction = true;
    if (map[(int)player->baby->pos.x][(int)player->baby->pos.y] == 'F' &&
        player->baby->fridge->time <= 0 && player->baby->fridge->is_open
        && player->baby->fridge->interaction) {
        player->baby->hp -= 20;
        player->baby->fridge->time = 5;
    }
}

static bool check_death(kidiot_t *player)
{
    char **map = player->baby->floor == 0
        ? player->first_floor : player->second_floor;

    if (player->baby->bathtub->time <= 0) {
        player->baby->hp = 0;
        return true;
    }
    split_check_death(player, map);
    if (player->baby->hp <= 0)
        return true;
    return false;
}

static bool split_is_obstacle(char obs, kidiot_t *play, bool baby)
{
    if (obs == 'S') {
        if (baby) {
            if (play->baby->floor == 0)
                play->baby->pos = play->tp->pos_stairs[1];
            else
                play->baby->pos = play->tp->pos_stairs[0];
            play->baby->floor ==
                0 ? (play->baby->floor = 1) : (play->baby->floor = 0);
        }
        else {
            if (play->mom->floor == 0)
                play->mom->pos = play->tp->pos_stairs[1];
            else
                play->mom->pos = play->tp->pos_stairs[0];
            play->mom->floor ==
                0 ? (play->mom->floor = 1) : (play->mom->floor = 0);
        }
        return true;
    }
    return false;
}

bool is_obstacle(char obs, kidiot_t *play, bool baby)
{
    if (obs == '#' || obs == 'T' || obs == 'Z' || obs == '+')
        return true;
    if (obs == 'W' && baby) {
        if (play->baby->floor == 0 && play->tp->is_open[0])
            play->baby->pos = play->tp->pos_toilet[1];
        else if (play->baby->floor == 1 && play->tp->is_open[1])
            play->baby->pos = play->tp->pos_toilet[0];
        else
            return false;
        play->baby->floor ==
            0 ? (play->baby->floor = 1) : (play->baby->floor = 0);
        return true;
    }
    return split_is_obstacle(obs, play, baby);
}

bool game_loop(kidiot_t *play, int keys[])
{
    move_players_baby(play, keys);
    move_players_mom(play, keys);
    if (check_death(play))
        return true;
    return false;
}