/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** parse_pos
*/

#include <rpg/rpg.h>
#include <file_utils.h>
#include <dirent.h>
#include <errno.h>

PRIVATE enum reward_type get_reward_type(char *raw_type)
{
    if (raw_type == NULL)
        return (UNKNOWN_REWARD);
    if (!nstrcmp(raw_type, "XP"))
        return (REWARD_XP);
    if (!nstrcmp(raw_type, "ITEM"))
        return (REWARD_ITEM);
    return (UNKNOWN_REWARD);
}

PRIVATE reward_t *parse_quest_reward(char *xml)
{
    char *raw_type = NULL;
    reward_t *reward;

    if (xml == NULL)
        return (NULL);
    reward = ncalloc(1, sizeof(reward_t));
    if (!reward)
        return (NULL);
    raw_type = xml_get_attribute(xml, "type");
    if (!raw_type)
        return (NULL);
    reward->value = natoi(xml_get_attribute(xml, "value"));
    reward->item_id = natoi(xml_get_attribute(xml, "item-id"));
    reward->item_count = natoi(xml_get_attribute(xml, "item-count"));
    reward->type = get_reward_type(raw_type);
    return (reward);
}

list_t *parse_quest_rewards(char *xml)
{
    list_t *list;
    char **rewards;

    if (xml == NULL)
        return (NULL);
    list = list_create();
    rewards = xml_get_balises(xml, "reward");
    if (rewards == NULL || list == NULL)
        return (NULL);
    for (unsigned int itr = 1; rewards[0] && rewards[itr]; ++itr) {
        list_add(list, parse_quest_reward(rewards[itr]));
    }
    return (list);
}