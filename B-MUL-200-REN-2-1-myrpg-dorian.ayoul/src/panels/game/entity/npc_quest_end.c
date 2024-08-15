/*
** EPITECH PROJECT, 2021
** Init NPC quest
** File description:
** init npc quest
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

bool already_finished_quest(game_t *game, int id)
{
    char *quests;

    if (game == NULL || game->player == NULL)
        return (false);
    quests = game->player->quests;
    if (!quests)
        return (false);
    for (unsigned int itr = 0; quests[itr]; ++itr) {
        if (quests[itr] == ',')
            continue;
        if (quests[itr] - '0' == id)
            return (true);
    }
    return (false);
}

PRIVATE char *update_quest_list(game_t *game, int id)
{
    char *ach = game->player->quests;
    char *new;
    int itr;
    int len;

    if (!ach)
        return (NULL);
    len = nstrlen(ach) + 3;
    new = ncalloc(len, sizeof(char));
    if (!new)
        return (NULL);
    for (itr = 0; ach[itr]; ++itr)
        new[itr] = ach[itr];
    new[itr++] = id + '0';
    new[itr++] = ',';
    new[itr] = '\0';
    return (new);
}

PRIVATE void save_quest(game_t *game, entity_t *entity)
{
    int id = 0;

    if (game == NULL || entity == NULL)
        return;
    id = entity->id;
    game->player->quests = update_quest_list(game, id);
}

void handle_quest_end(game_t *game, entity_t *entity)
{
    if (game == NULL || entity == NULL)
        return;
    if (already_finished_quest(game, entity->id))
        return;
    save_quest(game, entity);
    finish_achievement(game, entity->id, QUEST_NPC);
    give_quest_rewards(game, entity);
    game->player->quest_id = 0;
}