/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load_saves
*/

#include <rpg/rpg.h>
#include <hnep/nstring.h>

PRIVATE void save_skill(skill_t *skill, xml_balise_t *skills)
{
    xml_balise_t *bskill = xml_add_balise(skills, "skill");
    char *level = string_format("%i", skill->level);
    char *usage = string_format("%i", skill->usage);
    char *attack = string_format("%i", skill->attack);

    xml_add_attribute(bskill, "name", skill->name);
    xml_add_attribute(bskill, "type", skill->type);
    xml_add_attribute(bskill, "level", level);
    xml_add_attribute(bskill, "usage", usage);
    xml_add_attribute(bskill, "attack", attack);
    free(level);
    free(usage);
    free(attack);
}

PRIVATE void save_skills(list_t *list, xml_balise_t *content)
{
    xml_balise_t *skills;

    if (!list || !content)
        return;
    skills = xml_add_balise(content, "skills");
    list_foreach(list, node)
        save_skill((skill_t *)node->value, skills);
}

void save_save_skills(save_t *save, xml_balise_t *content)
{
    if (!save || !save->skills)
        return;
    save_skills(save->skills, content);
}

void save_player_skills(player_t *player, xml_balise_t *content)
{
    if (!player || !player->skills)
        return;
    save_skills(player->skills, content);
}