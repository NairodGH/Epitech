/*
** EPITECH PROJECT, 2022
** move_players.c
** File description:
** move_players
*/

#include "includes.h"

static void split_check_speed(Vector2 *pos, int keys[], float speed, int i)
{
    if (keys[2 + i] == 1)
        pos->x -= speed;
    else if (keys[3 + i] == 1)
        pos->x += speed;
}

static bool check_speed(kidiot_t *play, int keys[], bool baby)
{
    Vector2 *pos = (baby ? &play->baby->temp_pos : &play->mom->temp_pos);
    float speed = (baby ? play->baby->speed : play->mom->speed);
    int save_y = pos->y;
    int save_x = pos->x;
    int i = (baby ? 0 : 5);

    if (keys[0 + i] == 1)
        pos->y += speed;
    else if (keys[1 + i] == 1)
        pos->y -= speed;
    else
        split_check_speed(pos, keys, speed, i);
    if (save_y != (int)pos->y || save_x != (int)pos->x) {
        return true;
    }
    return false;
}

void move_players_baby(kidiot_t *play, int keys[])
{
    char **map = NULL;

    if (!check_speed(play, keys, true))
        return;
    map = play->baby->floor == 0 ? play->first_floor : play->second_floor;
    if (keys[0] == 1 && !(is_obstacle
        (map[(int)play->baby->pos.x][(int)(play->baby->pos.y + 1)], play, 1)))
        play->baby->pos.y += 1;
    else if (keys[1] == 1 && !(is_obstacle
        (map[(int)play->baby->pos.x][(int)(play->baby->pos.y - 1)], play, 1)))
        play->baby->pos.y -= 1;
    else if (keys[2] == 1 && !(is_obstacle
        (map[(int)(play->baby->pos.x - 1)][(int)play->baby->pos.y], play, 1)))
        play->baby->pos.x -= 1;
    else if (keys[3] == 1 && !(is_obstacle
        (map[(int)(play->baby->pos.x + 1)][(int)play->baby->pos.y], play, 1)))
        play->baby->pos.x += 1;
}

void move_players_mom(kidiot_t *play, int keys[])
{
    char **map = NULL;

    if (play->baby->vacuum->time > 0 || !check_speed(play, keys, false))
        return;
    map = ((play->mom->floor == 0) ? play->first_floor : play->second_floor);
    if (keys[5] == 1 && !(is_obstacle
        (map[(int)play->mom->pos.x][(int)play->mom->pos.y + 1], play, false)))
        play->mom->pos.y += 1;
    else if (keys[6] == 1 && !(is_obstacle
        (map[(int)play->mom->pos.x][(int)play->mom->pos.y - 1], play, false)))
        play->mom->pos.y -= 1;
    else if (keys[7] == 1 && !(is_obstacle
        (map[(int)play->mom->pos.x - 1][(int)play->mom->pos.y], play, false)))
        play->mom->pos.x -= 1;
    else if (keys[8] == 1 && !(is_obstacle
        (map[(int)play->mom->pos.x + 1][(int)play->mom->pos.y], play, false)))
        play->mom->pos.x += 1;
}