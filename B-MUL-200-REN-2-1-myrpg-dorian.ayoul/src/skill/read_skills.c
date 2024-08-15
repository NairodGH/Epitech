/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** read_skills
*/

#include <rpg/rpg.h>
#include <rpg/skill.h>
#include <file_utils.h>

PRIVATE skill_t *parse_skill(char const *xml)
{
    skill_t *skill = ncalloc(1, sizeof(skill_t));

    if (skill == NULL)
        return NULL;
    skill->name = xml_get_attribute(xml, "name");
    skill->type = xml_get_attribute(xml, "type");
    skill->level = natoi(xml_get_attribute(xml, "level"));
    skill->usage = natoi(xml_get_attribute(xml, "usage"));
    skill->attack = natoi(xml_get_attribute(xml, "attack"));
    return skill;
}

list_t *parse_skills(char const *xml)
{
    list_t *list = list_create();
    char *root = xml_get_balise(xml, "skills");
    char **skills = root ? xml_get_balises(root, "skill") : NULL;

    if (list == NULL)
        return NULL;
    if (!root || !skills)
        return (list);
    for (uint itr = 1; skills && skills[itr]; itr++)
        list_add(list, parse_skill(skills[itr]));
    free(skills);
    return list;
}

list_t *load_skills(void)
{
    list_t *skills;
    char *content = read_file("./config/skilltree.xml");

    if (content == NULL)
        return NULL;
    skills = parse_skills(content);
    free(content);
    return skills;
}