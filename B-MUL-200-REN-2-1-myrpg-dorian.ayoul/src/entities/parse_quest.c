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

PRIVATE quest_t *prepare_entity_quest(quest_t *quest)
{
    quest->lines = my_strtok(quest->text, '\n');
    quest->id = 0;
    quest->itr = 1;
    quest->raw = get_quest_chars(quest->lines, 0, 3);
    return (quest);
}

PRIVATE enum quest_type get_quest_type(char *type)
{
    if (type == NULL)
        return (UNKNOWN_QUEST);
    if (!nstrcmp(type, "GET_ITEM"))
        return (GET_ITEM);
    return (UNKNOWN_QUEST);
}

PRIVATE quest_t *parse_quest_needs(quest_t *qu, char *xml)
{
    if (!xml || !qu)
        return (NULL);
    qu->item_id = natoi(xml_get_attribute(xml, "item-id"));
    qu->item_count = natoi(xml_get_attribute(xml, "item-count"));
    qu->rewards = parse_quest_rewards(xml_balcontent(xml, "rewards"));
    return (qu);
}

quest_t *parse_quest(char *xml)
{
    quest_t *quest = malloc(sizeof(quest_t));
    char *started;
    char *finished;
    char *text;

    if (!xml || quest == NULL)
        return (NULL);
    started = xml_balcontent(xml, "already-started");
    finished = xml_balcontent(xml, "finished");
    text = xml_balcontent(xml, "content");
    quest->name = xml_balcontent(xml, "name");
    quest->text = replace_char(text, '@', '\n');;
    quest->info = xml_balcontent(xml, "info");
    quest->started_text = replace_char(started, '@', '\n');
    quest->finished_text = replace_char(finished, '@', '\n');
    quest->type = get_quest_type(xml_balcontent(xml, "type"));
    quest = parse_quest_needs(quest, xml_get_balise(xml, "needs"));
    quest = prepare_entity_quest(quest);
    return (quest);
}