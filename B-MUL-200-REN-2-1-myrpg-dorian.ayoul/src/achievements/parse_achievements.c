/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** parse_achievements
*/

#include <rpg/rpg.h>
#include <file_utils.h>
#include <dirent.h>
#include <errno.h>

PRIVATE size_t get_achievement_count(char const *xml)
{
    char *list = xml_get_content(xml_get_balise(xml, "achievements"));
    char **achievements = xml_get_balises(list, "achievement");
    size_t count;

    if (list == NULL || achievements == NULL)
        return (0);
    for (count = 0; achievements[count]; ++count);
    return (count);
}

PRIVATE obj_t *prepare_achievement_object(achievement_t *achievement)
{
    obj_t *obj;
    sfIntRect rct = {0, 0, 320, 64};
    sfVector2f pos = {640, -65};

    if (achievement == NULL || achievement->asset == NULL)
        return (NULL);
    obj = create_object(achievement->asset, rct, pos);
    if (obj == NULL)
        return (NULL);
    set_obj_visibility(obj, false);
    return (obj);
}

PRIVATE achievement_t *parse_achievement(char *balise)
{
    achievement_t *achievement = NULL;

    if (balise == NULL)
        return (NULL);
    achievement = ncalloc(1, sizeof(achievement_t));
    if (achievement == NULL)
        return (NULL);
    achievement->id = natoi(xml_get_attribute(balise, "id"));
    achievement->type = xml_get_attribute(balise, "type");
    achievement->npc_id = natoi(xml_get_attribute(balise, "npc_id"));
    achievement->reward_xp = natoi(xml_get_attribute(balise, "reward_xp"));
    achievement->asset = xml_get_attribute(balise, "achievement_img");
    achievement->description = xml_get_attribute(balise, "description");
    achievement->obj = prepare_achievement_object(achievement);
    achievement->animation_state = 0;
    return (achievement);
}

achievement_t **parse_achievements(void)
{
    char *content = read_file("./config/achievements.xml");
    size_t sz = 0;
    size_t itr = 0;
    achievement_t **achievements;
    char *list = xml_get_content(xml_get_balise(content, "achievements"));
    char **balises = list ? xml_get_balises(list, "achievement") : NULL;

    if (content == NULL || !list || !balises)
        return (NULL);
    sz = get_achievement_count(content);
    achievements = ncalloc(1 + sz, sizeof(achievement_t));
    if (achievements == NULL)
        return (NULL);
    for (; balises && balises[itr]; ++itr)
        achievements[itr] = parse_achievement(balises[itr]);
    achievements[itr] = NULL;
    return (achievements);
}