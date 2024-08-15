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

PRIVATE size_t get_entity_count(void)
{
    DIR *dir = opendir("./entities/");
    struct dirent *info;
    int count = 0;

    if (dir == NULL)
        return (0);
    for (; (info = readdir(dir)); ) {
        if (!str_endswith(info->d_name, ".xml"))
            continue;
        ++count;
    }
    return (count);
}

PRIVATE int parse_entity_info(entity_t *entity, char const *xml)
{
    char *entity_info = xml_get_balise(xml, "entity");
    char *raw_id;
    char *asset;
    int id;

    if (entity == NULL || entity_info == NULL)
        return 1;
    if ((raw_id = xml_get_attribute(entity_info, "id")) == NULL)
        return 1;
    if ((asset = xml_get_attribute(entity_info, "asset")) == NULL)
        return 1;
    id = natoi(raw_id);
    entity->id = id;
    entity->asset = asset;
    entity = parse_entity_data(entity, entity_info);
    entity->obj = prepare_entity_object(entity);
    return 0;
}

entity_t *parse_entity_path(char const *path)
{
    char *xml = read_file(path);
    entity_t *entity;

    if (xml == NULL)
        return NULL;
    entity = ncalloc(1, sizeof(entity_t));
    if (parse_entity_info(entity, xml)) {
        return NULL;
    }
    return entity;
}

entity_t **parse_entities(void)
{
    DIR *dir = opendir("./entities/");
    struct dirent *info;
    size_t count = get_entity_count();
    size_t i = 0;
    entity_t **ent = ncalloc(count + 1, sizeof(entity_t));

    if (dir == NULL || ent == NULL)
        return (NULL);
    for (; (info = readdir(dir)); ) {
        if (!str_endswith(info->d_name, ".xml"))
            continue;
        ent[i] = parse_entity_path(append_str("./entities/", info->d_name));
        ++i;
    }
    ent[i] = NULL;
    closedir(dir);
    return (ent);
}