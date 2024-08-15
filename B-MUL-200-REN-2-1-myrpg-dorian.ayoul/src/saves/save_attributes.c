/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** save attributes
*/

#include <rpg/rpg.h>
#include <engine.h>
#include <envdata.h>
#include <file_utils.h>
#include <hnep/nstring.h>

xml_balise_t *save_attributes(save_t *sv, xml_balise_t *content)
{
    xml_balise_t *attr = xml_add_balise(content, "attributes");
    char *ingame_time = string_format("%i", sv->ingame_time);
    char *health = string_format("%i", sv->health);
    char *food_level = string_format("%i", sv->food_level);

    xml_add_attribute(attr, "ingame-time", ingame_time);
    xml_add_attribute(attr, "health", health);
    xml_add_attribute(attr, "food-level", food_level);
    free(ingame_time);
    free(health);
    free(food_level);
    return attr;
}

xml_balise_t *save_attributes_player(player_t *pl, xml_balise_t *content)
{
    xml_balise_t *attr = xml_add_balise(content, "attributes");
    char *ingame_time = string_format("%i", pl->ingame_time);
    char *health = string_format("%i", pl->health);
    char *food_level = string_format("%i", pl->food_level);

    xml_add_attribute(attr, "ingame-time", ingame_time);
    xml_add_attribute(attr, "health", health);
    xml_add_attribute(attr, "food-level", food_level);
    free(ingame_time);
    free(health);
    free(food_level);
    return attr;
}