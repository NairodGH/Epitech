/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load player
*/

#include <rpg/rpg.h>
#include <envdata.h>

PRIVATE void init_player_tempkeys(player_t *player)
{
    if (player == NULL)
        return;
    player->last_view = 0;
    player->last_view_id = 0;
    player->tmp_movement_count = 0;
    player->last_movement = sfClock_create();
    player->last_pos_change = sfClock_create();
    player->last_save = sfClock_create();
    player->movement_soundclock = sfClock_create();
    player->regen_clock = sfClock_create();
}

player_t *init_player(save_t *save)
{
    player_t *player = ncalloc(1, sizeof(player_t));

    if (player == NULL)
        return (NULL);
    player->save_name = nstrdup(save->name);
    player->health = save->health;
    player->xp = save->xp;
    player->level = save->level;
    player->food_level = save->food_level;
    player->pos_x = save->pos_x;
    player->pos_y = save->pos_y;
    player->inventory = save->inventory;
    player->skills = save->skills;
    player->ingame_time = save->ingame_time;
    player->achievements = save->achievements;
    player->quests = save->quests;
    player->pickitems = save->pickitems;
    init_player_tempkeys(player);
    return (player);
}