/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load_saves
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>
#include <dirent.h>
#include <errno.h>
#include <file_utils.h>
#include <hnep/nstring.h>

PRIVATE save_t *fill_save_attr(save_t *save, char *attr, char *pos, char *pr)
{
    if (!attr || !pos)
        return NULL;
    save->health = natoi(xml_get_attribute(attr, "health"));
    save->food_level = natoi(xml_get_attribute(attr, "food-level"));
    save->ingame_time = natoi(xml_get_attribute(attr, "ingame-time"));
    save->pos_x = natoi(xml_get_attribute(pos, "x"));
    save->pos_y = natoi(xml_get_attribute(pos, "y"));
    save->level = natoi(xml_get_attribute(pr, "level"));
    save->xp = natoi(xml_get_attribute(pr, "xp"));
    return save;
}

PRIVATE void fill_save(game_t *game, save_t *save, char *content)
{
    char *data;
    char *attr;
    char *pos;
    char *prog;

    if (save == NULL || content == NULL)
        return;
    data = xml_get_balise(content, "save");
    attr = xml_get_balise(data, "attributes");
    pos = xml_get_balise(data, "position");
    prog = xml_get_balise(data, "progress");
    save = fill_save_attr(save, attr, pos, prog);
    save->quest_id = natoi(xml_balcontent(data, "quest_id"));
    save->achievements = xml_balcontent(data, "achievements");
    save->quests = xml_balcontent(data, "quests");
    read_inventory(game, save, data);
    read_pickitems(save, data);
}

save_t *generate_default_save(save_t *save)
{
    if (save == NULL)
        return NULL;
    save_save(save);
    return save;
}

save_t *read_save(game_t *game, char *file)
{
    save_t *save = init_default_save(file);
    char *path = string_format("saves/%s", file);
    char *content = read_file(path);

    if (save == NULL || content == NULL)
        return NULL;
    fill_save(game, save, content);
    save->name = nstrdup(file);
    free(path);
    free(content);
    return save;
}