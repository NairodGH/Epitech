/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init save
*/

#include <rpg/rpg.h>

PRIVATE void init_default_save_keys(save_t *save)
{
    if (!save)
        return;
    save->quest_id = 0;
    save->last_view_id = 0;
    save->achievements = ",";
    save->quests = ",";
    save->ingame_time = 0;
    save->pickitems = list_create();
    save->inventory = list_create();
    save->skills = list_create();
    save->last_movement = sfClock_create();
}

save_t *init_default_save(char *name)
{
    save_t *save = ncalloc(1, sizeof(save_t));

    if (save == NULL)
        return (NULL);
    save->name = name;
    save->health = 100;
    save->xp = 0;
    save->level = 1;
    save->food_level = 100;
    save->pos_x = 288;
    save->pos_y = 381;
    save->last_view = 0;
    init_default_save_keys(save);
    return (save);
}