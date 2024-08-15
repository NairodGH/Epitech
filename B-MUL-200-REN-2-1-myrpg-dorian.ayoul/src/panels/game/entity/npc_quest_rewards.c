/*
** EPITECH PROJECT, 2021
** give quest rewards
** File description:
** Give quest rewards
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void give_quest_rewards(game_t *game, entity_t *entity)
{
    reward_t *reward;

    if (!entity || !entity->quest || !game->player)
        return;
    if (!entity->quest->rewards)
        return;
    list_foreach(entity->quest->rewards, node) {
        reward = (reward_t *) node->value;
        if (reward->type == REWARD_XP)
            add_player_xp(game, reward->value);
        if (reward->type == REWARD_ITEM)
            give_item(game, reward->item_id, reward->item_count);
    }
}