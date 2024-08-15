/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** save
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>
#include <engine.h>
#include <envdata.h>
#include <file_utils.h>
#include <hnep/nstring.h>

PRIVATE xml_balise_t *convert_save_to_xml(save_t *sv)
{
    xml_balise_t *save = xml_add_balise(NULL, "save");
    xml_balise_t *progress = xml_add_balise(save, "progress");
    xml_balise_t *achievements = xml_add_balise(save, "achievements");
    xml_balise_t *quest_id = xml_add_balise(save, "quest_id");
    xml_balise_t *quests = xml_add_balise(save, "quests");

    save_attributes(sv, save);
    save_pos(sv, save);
    save_save_inventory(sv, save);
    save_save_skills(sv, save);
    save_save_pickitems(sv, save);
    xml_add_attribute(save, "name", sv->name);
    xml_add_attribute(progress, "level", int_to_str(sv->level));
    xml_add_attribute(progress, "xp", int_to_str(sv->xp));
    xml_set_content(quest_id, int_to_str(sv->quest_id));
    xml_set_content(achievements, sv->achievements);
    xml_set_content(quests, sv->quests);
    return (save);
}

PRIVATE void save_save_xml(save_t *sv)
{
    xml_balise_t *xml;
    char *path;
    char *output;

    if (sv == NULL)
        return;
    xml = convert_save_to_xml(sv);
    if (xml == NULL)
        return;
    path = string_format("saves/%s.xml", sv->name);
    output = xml_serialize(xml);
    if (output == NULL || path == NULL)
        return;
    write_file(path, output);
    xml_free(xml);
    free(output);
    free(path);
}

void save_save(save_t *sv)
{
    if (sv == NULL)
        return;
    save_save_xml(sv);
}