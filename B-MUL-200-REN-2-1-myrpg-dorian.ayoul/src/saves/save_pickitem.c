/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** save attributes
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>
#include <engine.h>
#include <envdata.h>
#include <file_utils.h>
#include <hnep/nstring.h>

void save_pickitem(posint_t *pos, xml_balise_t *mapobj)
{
    xml_balise_t *slot = xml_add_balise(mapobj, "obj");
    char *pos_x;
    char *pos_y;

    if (!pos || !mapobj || !slot)
        return;
    pos_x = string_format("%i", pos->x);
    pos_y = string_format("%i", pos->y);
    xml_add_attribute(slot, "x", pos_x);
    xml_add_attribute(slot, "y", pos_y);
    free(pos_x);
    free(pos_y);
}

void save_pickitems(list_t *list, xml_balise_t *content)
{
    xml_balise_t *mapobj;

    if (list == NULL || content == NULL)
        return;
    mapobj = xml_add_balise(content, "map-objects");
    list_foreach(list, node)
        save_pickitem((posint_t *)node->value, mapobj);
}

void save_save_pickitems(save_t *save, xml_balise_t *content)
{
    if (!save || !save->pickitems)
        return;
    save_pickitems(save->pickitems, content);
}

void save_player_pickitems(player_t *player, xml_balise_t *content)
{
    if (!player || !player->pickitems)
        return;
    save_pickitems(player->pickitems, content);
}