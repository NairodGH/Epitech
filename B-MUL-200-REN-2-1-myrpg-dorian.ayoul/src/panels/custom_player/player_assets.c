/*
** EPITECH PROJECT, 2021
** player assets
** File description:
** different type of player
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <envdata.h>
#include <rpg/rpg.h>
#include <SFML/Audio.h>

const size_t player_assets_count = 12;

const sfIntRect player_rect = {0, 0, 30, 36};

const playerasset_t player_assets[] = {
        {1, (sfVector2f){0, 0}},
        {2, (sfVector2f){98, 0}},
        {3, (sfVector2f){193, 0}},
        {4, (sfVector2f){288, 0}},
        {5, (sfVector2f){385, 0}},
        {6, (sfVector2f){482, 0}},
        {7, (sfVector2f){0, 145}},
        {8, (sfVector2f){98, 145}},
        {9, (sfVector2f){193, 145}},
        {10, (sfVector2f){288, 145}},
        {11, (sfVector2f){385, 145}},
        {12, (sfVector2f){482, 145}},
};

playerasset_t *get_player_assets(void)
{
    return ((playerasset_t *) player_assets);
}

sfVector2f get_player_basepos(int player_id)
{
    for (size_t itr = 0; itr < player_assets_count; ++itr) {
        if (player_assets[itr].id == player_id)
            return (player_assets[itr].basepos);
    }
    return ((sfVector2f) {0, 0});
}

sfVector2f get_player_pos(int player_id, int movement, int foot)
{
    sfVector2f base_pos = get_player_basepos(player_id);

    if (foot == -1)
        base_pos.x += 32;
    if (foot == 0)
        base_pos.x += 64;
    if (movement == 1)
        base_pos.y += 72;
    if (movement == 2)
        base_pos.y += 36 * 3;
    if (movement == 3)
        base_pos.y += 36;
    return (base_pos);
}