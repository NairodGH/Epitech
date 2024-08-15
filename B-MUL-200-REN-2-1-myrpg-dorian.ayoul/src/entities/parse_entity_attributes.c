/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** parse_entities
*/

#include <rpg/rpg.h>
#include <file_utils.h>
#include <dirent.h>
#include <errno.h>

entity_t *prepare_entity_discuss(entity_t *entity, char *ent)
{
    entity->discuss = xml_get_content(xml_get_balise(ent, "discuss"));
    entity->discuss = replace_char(entity->discuss, '@', '\n');
    entity->discuss_lines = my_strtok(entity->discuss, '\n');
    entity->line_id = 0;
    entity->discuss_itr = 1;
    entity->discuss_raw = get_discuss_chars(entity->discuss_lines, 0, 3);
    entity->discuss_clock = sfClock_create();
    entity->discuss_soundclock = sfClock_create();
    return (entity);
}

entity_t *parse_entity_data(entity_t *entity, char *entity_info)
{
    entity->name = xml_get_content(xml_get_balise(entity_info, "name"));
    entity->rect = parse_rect(xml_get_balise(entity_info, "rect"));
    entity->pos = parse_pos(xml_get_balise(entity_info, "position"));
    entity->quest = parse_quest(xml_get_balise(entity_info, "quest"));
    entity->fight = parse_fight(xml_get_balise(entity_info, "fight"));
    entity = prepare_entity_discuss(entity, entity_info);
    entity->next_time = 40;
    return (entity);
}